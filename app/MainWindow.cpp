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
#include "IncompressibleFlowModel.h"
#include "PGFlowModel.h"
#include "FanOptimizerDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->addAction(ui->actionNew_Block);
    ui->graphicsView->setMouseTracking(true);

    consoleLog("Bernoulli version 0.0 Copyright (C) 2017 Mack Global");
    consoleWarning("This is a very early alpha version. Only a handful of features are currently functioning. Use at your own risk!");

    scene_ = new ProcessModelScene(ui->graphicsView);
    ui->graphicsView->setScene(scene_);

    QMainWindow::tabifyDockWidget(ui->nodeResultsDockWidget, ui->connectorResultsDockWidget);
    QMainWindow::tabifyDockWidget(ui->connectorResultsDockWidget, ui->consoleDockWidget);

    ui->actionNode_Results->setChecked(true);
    ui->actionConnector_Results->setChecked(true);
    ui->actionConsole->setChecked(true);

    on_modelComboBox_currentIndexChanged(QString("Incompressible"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

BlockGraphicsItem* MainWindow::addBlock(const std::string &blockType, const QPointF &pos)
{
    std::shared_ptr<Block> block;
    QImage image(":/blocks/images/default.png");

    //- Default node points
    std::vector<QPointF> nodePts = {
        QPointF(-10, 19),
        QPointF(48, 19),
        QPointF(20, -10)
    };

    if(blockType == "Fan")
    {
        block = std::shared_ptr<Block>(new Fan());
        image = QImage(":/blocks/images/fan.png");
    }
    else if(blockType == "Constant Flow Fan")
    {
        block = std::shared_ptr<Block>(new ConstFlowFan());
        image = QImage(":/blocks/images/const_flow_fan.png");
    }
    else if(blockType == "Pressure Reservoir")
    {
        block = std::shared_ptr<Block>(new PressureReservoir());
        image = QImage(":/blocks/images/pressure_reservoir.png");
    }
    else if(blockType == "Mass Flow Reservoir")
    {
        block = std::shared_ptr<Block>(new MassFlowReservoir());
        image = QImage(":/blocks/images/mass_flow_reservoir.png");
    }
    else if(blockType == "Restrictor Valve")
    {
        block = std::shared_ptr<Block>(new RestrictorValve());
        image = QImage(":/blocks/images/valve.png");
    }
    else if(blockType == "Diffuser")
    {
        block = std::shared_ptr<Block>(new Diffuser());
        image = QImage(":/blocks/images/diffuser.png");
    }
    else if(blockType == "Nozzle")
    {
        block = std::shared_ptr<Block>(new Nozzle());
        image = QImage(":/blocks/images/nozzle.png");
    }
    else if(blockType == "Y Connector")
    {
        block = std::shared_ptr<Block>(new YConnector());
        image = QImage(":/blocks/images/y_connector.png");
        nodePts = {
            QPointF(-10, 2.5),
            QPointF(-10, 35),
            QPointF(48, 20)
        };
    }
    else
        return nullptr;

    ProcessModelScene *scene = (ProcessModelScene*)ui->graphicsView->scene();
    if(scene)
        return scene->addBlock(block, image, nodePts, pos);

    return nullptr;
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

void MainWindow::on_actionRun_triggered()
{
    auto blocks = scene_->getBlocks();
    auto connectors = scene_->getConnectors();

    consoleLog("Solving for " + std::to_string(blocks.size()) + " blocks and " + std::to_string(connectors.size()) + " connectors...");

    if(flowModel_)
    {
        flowModel_->solve(blocks, connectors);
        postProcess(blocks, connectors);
        consoleLog("Flow model solution updated.");
    }
    else
        consoleLog("No active flow model.");
}

void MainWindow::on_actionNew_Block_triggered()
{
    BlockDialog dialog;
    if(dialog.exec() == QDialog::Accepted)
    {
        QString blockType = dialog.getSelectedBlock();
        addBlock(blockType.toStdString());
    }
}

void MainWindow::on_modelComboBox_currentIndexChanged(const QString &flowModel)
{
    if(flowModel == "Incompressible" || flowModel == "IncompressibleFlowModel")
        flowModel_ = std::shared_ptr<IncompressibleFlowModel>(new IncompressibleFlowModel());
    else if(flowModel == "Incompressible (Procter and Gamble)" || flowModel == "PGFlowModel")
        flowModel_ = std::shared_ptr<PGFlowModel>(new PGFlowModel());
    else
    {
        consoleError("Flow model \"" + flowModel.toStdString() + "\" is undefined.");
        return;
    }

    flowModel_->initialize(scene_->getBlocks());
    flowModel_->initialize(scene_->getConnectors());
    scene_->setFlowModel(flowModel_);

    consoleLog("Flow model changed to \"" + flowModel.toStdString() + "\".");
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

void MainWindow::postProcess(const std::vector<std::shared_ptr<Block>> &blocks, const std::vector<std::shared_ptr<Connector>> &connectors)
{
    QTableWidget& table = *(ui->nodeResultsTable);
    table.clearContents();
    table.setRowCount(flowModel_->nNodes());

    int i = 0;
    for(const std::shared_ptr<Block>& block: blocks)
        for(std::shared_ptr<Node>& node: block->nodes())
        {
            QTableWidgetItem *nodeId = new QTableWidgetItem(tr(std::to_string(i + 1).c_str()));
            QTableWidgetItem *parentBlock = new QTableWidgetItem(tr(node->block().name.c_str()));
            QTableWidgetItem *parentBlockType = new QTableWidgetItem(tr(node->block().type().c_str()));
            QTableWidgetItem *nodeType = new QTableWidgetItem(tr((node->isInput() ? "Input" : node->isOutput() ? "Output" : "Sink")));
            QTableWidgetItem *pressure = new QTableWidgetItem(tr(std::to_string(node->state()("p")).c_str()));

            int j = 0;
            table.setItem(i, j++, nodeId);
            table.setItem(i, j++, parentBlock);
            table.setItem(i, j++, parentBlockType);
            table.setItem(i, j++, nodeType);
            table.setItem(i++, j++, pressure);
        }

    ui->connectorResultsTable->setRowCount(connectors.size());
    for(uint i = 0; i < connectors.size(); ++i)
    {
        QTableWidgetItem *connectorId = new QTableWidgetItem(tr(std::to_string(i + 1).c_str()));
        QTableWidgetItem *sourceNodeId = new QTableWidgetItem(tr(std::to_string(flowModel_->id(connectors[i]->sourceNode()) + 1).c_str()));
        QTableWidgetItem *destNodeId = new QTableWidgetItem(tr(std::to_string(flowModel_->id(connectors[i]->destNode()) + 1).c_str()));
        QTableWidgetItem *resistance = new QTableWidgetItem(tr(std::to_string(connectors[i]->resistance()).c_str()));
        QTableWidgetItem *flowRate = new QTableWidgetItem(tr(std::to_string(connectors[i]->state()("Q")).c_str()));

        int j = 0;
        ui->connectorResultsTable->setItem(i, j++, connectorId);
        ui->connectorResultsTable->setItem(i, j++, sourceNodeId);
        ui->connectorResultsTable->setItem(i, j++, destNodeId);
        ui->connectorResultsTable->setItem(i, j++, resistance);
        ui->connectorResultsTable->setItem(i, j++, flowRate);
    }
}

void MainWindow::on_actionSave_triggered()
{
    if(filename_.empty())
        on_actionSave_As_triggered();
    else
    {
        consoleLog("Saving case as \"" + filename_ + "\"...");

        std::unordered_map<Node*, uint> nodeIdMap;

        QFile file(QString(filename_.c_str()));

        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QXmlStreamWriter xml(&file);

        std::vector<BlockGraphicsItem*> blocks = scene_->getGraphicsItems<BlockGraphicsItem>();
        std::vector<ConnectorGraphicsPathItem*> connectors = scene_->getGraphicsItems<ConnectorGraphicsPathItem>();

        xml.setAutoFormatting(true);
        xml.writeStartDocument();

        //- Save the model type
        xml.writeStartElement("ProcessModel");
        xml.writeTextElement("FlowModel", flowModel_->type().c_str());

        //- Write block info
        uint nodeId = 0;
        for(BlockGraphicsItem* block: blocks)
        {
            xml.writeStartElement("block");
            xml.writeAttribute("name", block->block()->name.c_str());
            xml.writeAttribute("type", block->block()->type().c_str());
            xml.writeTextElement("x", QString::number(block->pos().x()));
            xml.writeTextElement("y", QString::number(block->pos().y()));
            xml.writeTextElement("transform", block->transform().isScaling() ? "true": "false");

            for(const auto& node: block->block()->nodes())
            {
                xml.writeStartElement("node");
                xml.writeAttribute("type", node->type().c_str());
                nodeIdMap[node.get()] = nodeId;
                xml.writeAttribute("id", QString::number(nodeId++));
                xml.writeEndElement();
            }

            for(const auto& entry: block->block()->properties())
            {
                xml.writeStartElement("property");
                xml.writeAttribute("name", entry.first.c_str());
                xml.writeTextElement("value", QString::number(entry.second));
                xml.writeEndElement();
            }

            for(const auto& entry: block->block()->properties())
            {
                xml.writeStartElement("solution");
                xml.writeAttribute("name", entry.first.c_str());
                xml.writeTextElement("value", QString::number(entry.second));
                xml.writeEndElement();
            }

            xml.writeEndElement(); // End block
        }

        //- Wite connector info
        for(ConnectorGraphicsPathItem* connector: connectors)
        {
            xml.writeStartElement("connector");
            xml.writeTextElement("source", QString::number(nodeIdMap[connector->connector()->sourceNode().get()]));
            xml.writeTextElement("dest", QString::number(nodeIdMap[connector->connector()->destNode().get()]));

            for(const auto& entry: connector->connector()->properties())
            {
                xml.writeStartElement("property");
                xml.writeAttribute("name", entry.first.c_str());
                xml.writeTextElement("value", QString::number(entry.second));
                xml.writeEndElement();
            }

            for(const auto& entry: connector->connector()->solution())
            {
                xml.writeStartElement("solution");
                xml.writeAttribute("name", entry.first.c_str());
                xml.writeTextElement("value", QString::number(entry.second));
                xml.writeEndElement();
            }

            xml.writeEndElement();
        }

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
        QFile file(QString(filename.c_str()));

        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QXmlStreamReader xml(&file);

        scene_->clear();
        std::unordered_map<int, std::shared_ptr<NodeGraphicsItem>> nodes;

        while(xml.readNextStartElement())
        {
            qDebug() << xml.name();

            if(xml.name() == "FlowModel")
                on_modelComboBox_currentIndexChanged(xml.readElementText());
            else if(xml.name() == "block")
            {
                std::string name = xml.attributes().value("name").toString().toStdString();
                std::string type = xml.attributes().value("type").toString().toStdString();

                QPointF pos(0., 0.);
                std::map<std::string, double> properties, solution;
                std::vector<int> nodeId;
                bool flip = false;

                while(xml.readNextStartElement())
                {
                    if(xml.name() == "x")
                        pos.setX(xml.readElementText().toDouble());
                    else if(xml.name() == "y")
                        pos.setY(xml.readElementText().toDouble());
                    else if(xml.name() == "transform")
                    {
                        if(xml.readElementText() == "true")
                            flip = true;
                    }
                    else if(xml.name() == "node")
                    {
                        nodeId.push_back(xml.attributes().value("id").toInt());
                        xml.skipCurrentElement();
                    }
                    else if(xml.name() == "property")
                    {
                        std::string name = xml.attributes().value("name").toString().toStdString();

                        while(xml.readNextStartElement())
                            properties[name] = xml.readElementText().toDouble();
                    }
                    else if(xml.name() == "solution")
                    {
                        std::string name = xml.attributes().value("name").toString().toStdString();

                        while(xml.readNextStartElement())
                            solution[name] = xml.readElementText().toDouble();
                    }
                }

                BlockGraphicsItem* block = addBlock(type, pos);

                if(flip)
                    block->flipHorizontal();

                block->setName(name);
                block->block()->setProperties(properties);

                int i = 0;
                for(std::shared_ptr<NodeGraphicsItem>& node: block->nodes())
                    nodes[nodeId[i++]] = node;
            }
            else if(xml.name() == "connector")
            {
                int source, dest;
                std::map<std::string, double> properties, solution;

                while(xml.readNextStartElement())
                {
                    if(xml.name() == "source")
                        source = xml.readElementText().toInt();
                    else if(xml.name() == "dest")
                        dest = xml.readElementText().toInt();
                    else if(xml.name() == "property")
                    {
                        std::string name = xml.attributes().value("name").toString().toStdString();

                        while(xml.readNextStartElement())
                            properties[name] = xml.readElementText().toDouble();
                    }
                    else if(xml.name() == "solution")
                    {
                        std::string name = xml.attributes().value("name").toString().toStdString();

                        while(xml.readNextStartElement())
                            solution[name] = xml.readElementText().toDouble();
                    }
                }

                ConnectorGraphicsPathItem* connector = scene_->connect(nodes[source], nodes[dest]);
                connector->connector()->setProperties(properties);
            }
        }

        file.close();
    }
}

void MainWindow::on_actionFlow_model_triggered()
{
    FanOptimizerDialog dialog(scene_->getBlocks());

    if(dialog.exec() == QDialog::Accepted)
    {

    }
}
