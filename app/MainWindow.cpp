#include <fstream>

#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>

#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "BlockDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->addAction(ui->actionNew_Block);
    ui->graphicsView->setMouseTracking(true);

    consoleLog("Gemini version 0.0 Copyright (C) 2017 Mack Global");
    consoleLog("Initialization completed.");
    consoleWarning("This is a very early alpha version. Only a handful of features are currently functioning. Use at your own risk!");

    scene_ = new ProcessModelScene(ui->graphicsView);
    ui->graphicsView->setScene(scene_);

    setSolver(ui->solverComboBox->currentText().toStdString());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setSolver(const std::string &solverType)
{
    bool success = false;

    if(solverType == "Flow Solve")
    {
        solver_ = std::make_shared<Solver>(Solver());
        success = true;
    }
    else if(solverType == "Fan Optimization")
    {
        solver_ = std::make_shared<FanOptimizer>(FanOptimizer());
        success = true;
    }

    if(success)
        consoleLog("Set solver type \"" + solverType + "\".");
    else
        consoleError("could not set solver type \"" + solverType + "\".");
}

void MainWindow::on_actionConsole_toggled(bool arg1)
{
    if(arg1)
        ui->consoleDockWidget->show();
    else
        ui->consoleDockWidget->hide();
}

void MainWindow::on_actionNode_Results_toggled(bool arg1)
{
    if(arg1)
        ui->nodeResultsDockWidget->show();
    else
        ui->nodeResultsDockWidget->hide();
}

void MainWindow::on_actionConnector_Results_toggled(bool arg1)
{
    if(arg1)
        ui->connectorResultsDockWidget->show();
    else
        ui->connectorResultsDockWidget->hide();
}

void MainWindow::on_actionRunSolver_triggered()
{
    std::vector<Block*> blocks = scene_->getBlocks();
    std::vector<Connector*> connectors = scene_->getConnectors();

    consoleLog("Solving for " + std::to_string(blocks.size()) + " blocks and " + std::to_string(connectors.size()) + " connectors...");
    double error = solver_->solve(blocks, connectors, false, 100);
    postProcess(blocks, connectors);
    consoleLog("Solution updated. Final error residual = " + std::to_string(error) + ".");
}

void MainWindow::on_actionNew_Block_triggered()
{
    BlockDialog dialog;
    if(dialog.exec() == QDialog::Accepted)
    {
        QString blockType = dialog.getSelectedBlock();
        Block *block = nullptr;
        QImage image(":/blocks/images/default.png");

        //- Default node points
        std::vector<QPointF> nodePts = {
            QPointF(-10, 19),
            QPointF(48, 19),
            QPointF(20, -10)
        };

        if(blockType == "Fan")
        {
            block = new Fan();
            image = QImage(":/blocks/images/fan.png");
        }
        else if(blockType == "Constant Flow Fan")
        {
            block = new ConstFlowFan();
            image = QImage(":/blocks/images/const_flow_fan.png");
        }
        else if(blockType == "Pressure Reservoir")
        {
            block = new PressureReservoir();
            image = QImage(":/blocks/images/pressure_reservoir.png");
        }
        else if(blockType == "Mass Flow Reservoir")
        {
            block = new MassFlowReservoir();
            image = QImage(":/blocks/images/mass_flow_reservoir.png");
        }
        else if(blockType == "Restrictor Valve")
        {
            block = new RestrictorValve();
            image = QImage(":/blocks/images/valve.png");
        }
        else if(blockType == "Diffuser")
        {
            block = new Diffuser();
            image = QImage(":/blocks/images/diffuser.png");
        }
        else if(blockType == "Nozzle")
        {
            block = new Nozzle();
            image = QImage(":/blocks/images/nozzle.png");
        }
        else if(blockType == "Y Connector")
        {
            block = new YConnector();
            image = QImage(":/blocks/images/y_connector.png");
            nodePts = {
                QPointF(-10, 2.5),
                QPointF(-10, 35),
                QPointF(48, 20)
            };
        }
        else
            return;

        ProcessModelScene *scene = (ProcessModelScene*)ui->graphicsView->scene();
        if(scene)
            scene->addBlock(block, image, nodePts, QPointF(0, 0));
    }
}

void MainWindow::on_modelComboBox_currentIndexChanged(const QString &model)
{
    bool success = true;

    if(model == "Simple Linear")
        scene_->setNewModel(std::make_shared<SimpleLinearModel>(SimpleLinearModel()));
    else if(model == "P&G")
        scene_->setNewModel(std::make_shared<PGModel>(PGModel()));

    if(success)
        consoleLog("Flow model changed to \"" + model.toStdString() + "\".");
    else
        consoleError("Flow model could not be changed to \"" + model.toStdString() + "\".");
}

ProcessModelScene *MainWindow::getActiveProcessModel()
{
    QGraphicsView* source = nullptr;

    for(QWidget *widget: ui->actionNew_Block->associatedWidgets())
        if(widget->hasFocus())
            source = (QGraphicsView*)widget;

    if(source == nullptr)
        return nullptr;

    ProcessModelScene* scene = (ProcessModelScene*)source->scene();
    return scene;
}

void MainWindow::addBlockToModel(const std::string &type, const QPointF &pos)
{

}

void MainWindow::consoleLog(const std::string &message)
{
    ui->console->append(
                ("<strong><font color=\"blue\">>> " + message + "</font></strong>").c_str()
                );
}

void MainWindow::consoleWarning(const std::string& message)
{
    ui->console->append(
                ("<strong><font color=\"#FFC300\">>> Warning: " + message + "</font></strong>").c_str()
                );
}

void MainWindow::consoleError(const std::string &message)
{
    ui->console->append(
                ("<strong><font color=\"red\">>> Error: " + message + "</font></strong>").c_str()
                );
}

void MainWindow::postProcess(const std::vector<Block *> &blocks, const std::vector<Connector *> &connectors)
{
    QTableWidget& table = *(ui->nodeResultsTable);
    const std::vector<Node*>& nodes = solver_->nodes();

    table.clearContents();
    table.setRowCount(nodes.size());

    for(int i = 0; i < nodes.size(); ++i)
    {
        const Node* node = nodes[i];

        QTableWidgetItem *nodeId = new QTableWidgetItem(tr(std::to_string(i + 1).c_str()));
        QTableWidgetItem *parentBlock = new QTableWidgetItem(tr(node->block().name.c_str()));
        QTableWidgetItem *parentBlockType = new QTableWidgetItem(tr(node->block().type().c_str()));
        QTableWidgetItem *nodeType = new QTableWidgetItem(tr((node->isInput() ? "Input" : node->isOutput() ? "Output" : "Sink")));
        QTableWidgetItem *pressure = new QTableWidgetItem(tr(std::to_string(nodes[i]->getSolution("P")).c_str()));

        int j = 0;
        table.setItem(i, j++, nodeId);
        table.setItem(i, j++, parentBlock);
        table.setItem(i, j++, parentBlockType);
        table.setItem(i, j++, nodeType);
        table.setItem(i, j++, pressure);
    }

    ui->connectorResultsTable->setRowCount(connectors.size());

    for(uint i = 0; i < connectors.size(); ++i)
    {
        QTableWidgetItem *connectorId = new QTableWidgetItem(tr(std::to_string(i + 1).c_str()));
        QTableWidgetItem *sourceNodeId = new QTableWidgetItem(tr(std::to_string(solver_->nodeId(connectors[i]->sourceNode()) + 1).c_str()));
        QTableWidgetItem *destNodeId = new QTableWidgetItem(tr(std::to_string(solver_->nodeId(connectors[i]->destNode()) + 1).c_str()));
        QTableWidgetItem *resistance = new QTableWidgetItem(tr(std::to_string(connectors[i]->getResistance()).c_str()));
        QTableWidgetItem *flowRate = new QTableWidgetItem(tr(std::to_string(connectors[i]->getSolution("Q")).c_str()));

        int j = 0;
        ui->connectorResultsTable->setItem(i, j++, connectorId);
        ui->connectorResultsTable->setItem(i, j++, sourceNodeId);
        ui->connectorResultsTable->setItem(i, j++, destNodeId);
        ui->connectorResultsTable->setItem(i, j++, resistance);
        ui->connectorResultsTable->setItem(i, j++, flowRate);
    }
}

void MainWindow::on_solverComboBox_currentIndexChanged(const QString &solver)
{
    setSolver(solver.toStdString());
}

void MainWindow::on_actionSave_triggered()
{
    if(filename_.empty())
        on_actionSave_As_triggered();
    else
    {
        consoleLog("Saving case as \"" + filename_ + "\"...");
        std::map<const Node*, uint> idMap;

        QFile file(QString(filename_.c_str()));
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QXmlStreamWriter xml(&file);

        std::vector<Block*> blocks = scene_->getBlocks();
        std::vector<Connector*> connectors = scene_->getConnectors();

        xml.setAutoFormatting(true);
        xml.writeStartDocument();

        //- Save the model type
        xml.writeStartElement("ProcessModel");
        xml.writeTextElement("Model", scene_->model().type().c_str());

        //- Write block info
        xml.writeStartElement("Blocks");
        xml.writeAttribute("count", QString::number(blocks.size()));

        uint nodeId = 0;
        for(Block* block: blocks)
        {
            xml.writeStartElement("Block");
            xml.writeAttribute("name", block->name.c_str());
            xml.writeAttribute("type", block->type().c_str());

            xml.writeStartElement("Nodes");
            for(const auto& node: block->nodes())
            {
                xml.writeStartElement("Node");
                xml.writeAttribute("type", node->type().c_str());
                idMap[node.get()] = nodeId;
                xml.writeAttribute("id", QString::number(nodeId++));
                xml.writeEndElement();
            }
            xml.writeEndElement(); // End nodes
            xml.writeEndElement(); // End block
        }

        xml.writeEndElement(); // End blocks

        //- Wite connector info
        xml.writeStartElement("Connectors");
        xml.writeAttribute("count", QString::number(connectors.size()));
        for(Connector* connector: connectors)
        {
            xml.writeStartElement("Connector");
            xml.writeTextElement("SourceNode", QString::number(idMap[connector->sourceNode()]));
            xml.writeTextElement("DestNode", QString::number(idMap[connector->destNode()]));

            xml.writeStartElement("Properties");
            for(const auto& entry: connector->properties())
            {
                const Property& p = entry.second;
                xml.writeTextElement(p.symbol.c_str(), QString::number(p.value));
            }
            xml.writeEndElement();

            xml.writeStartElement("Solution");
            for(const auto& entry: connector->solution())
            {
                const Solution& s = entry.second;
                xml.writeTextElement(s.symbol.c_str(), QString::number(s.value));
            }
            xml.writeEndElement();
            xml.writeEndElement();
        }
        xml.writeEndElement();

        xml.writeEndElement();
        xml.writeEndDocument();

        file.close();
    }
}

void MainWindow::on_actionSave_As_triggered()
{
    std::string filename = QFileDialog().getSaveFileName().toStdString();
    if(!filename.empty())
    {
        filename_ = filename;
        on_actionSave_triggered();
    }
}

void MainWindow::on_actionOpen_triggered()
{
    std::string filename = QFileDialog().getOpenFileName().toStdString();

    if(!filename.empty())
    {
        consoleLog("Loading file \"" + filename + "\"...");
    }
}
