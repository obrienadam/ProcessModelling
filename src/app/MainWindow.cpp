#include <QDebug>
#include <QMessageBox>

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

    consoleLog("Gemini version 0.0 Copyright (C) 2016 Adam Robert O'Brien");
    consoleLog("Initialization completed.");
    consoleWarning("This is a very early alpha version. Only a handful of features are currently functioning. Use at your own risk!");

    scene_ = new ProcessModelScene(ui->graphicsView);
    ui->graphicsView->setScene(scene_);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionConsole_toggled(bool arg1)
{
    if(arg1)
        ui->consoleDockWidget->show();
    else
        ui->consoleDockWidget->hide();
}

void MainWindow::on_actionResults_toggled(bool arg1)
{
    if(arg1)
        ui->resultsTableDockWidget->show();
    else
        ui->resultsTableDockWidget->hide();
}

void MainWindow::on_actionRunSolver_triggered()
{
    std::vector<Block*> blocks = scene_->getBlocks();
    std::vector<Connector*> connectors = scene_->getConnectors();

    consoleLog("Solving for " + std::to_string(blocks.size()) + " blocks and " + std::to_string(connectors.size()) + " connectors...");
    solver_.solve(blocks, connectors, false, 50);
    postProcess(blocks, connectors);
    consoleLog("Solution updated.");
}

void MainWindow::on_actionNew_Block_triggered()
{
    BlockDialog dialog;
    if(dialog.exec() == QDialog::Accepted)
    {
        QString blockType = dialog.getSelectedBlock();
        Block *block = nullptr;
        QImage image(":/blocks/images/default.png");

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
        else if(blockType == "Valve")
        {
            block = new Valve();
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
        else if(blockType == "T Connector")
        {
            block = new TJunction();
            image = QImage(":/blocks/images/t_connector.png");
        }
        else
            return;

        QPointF loc = ui->graphicsView->mapToScene(ui->graphicsView->mapFromGlobal(QCursor::pos()));
        ProcessModelScene *scene = (ProcessModelScene*)ui->graphicsView->scene();
        if(scene)
            scene->addBlock(block, image, loc);
    }
}

void MainWindow::on_modelComboBox_currentIndexChanged(const QString &model)
{
    std::vector<Connector*> connectors = scene_->getConnectors();
    bool success = true;

    if(model == "Simple Linear")
        scene_->setNewModel(std::make_shared<Model>(SimpleLinearModel()));
    else if(model == "P&G")
        scene_->setNewModel(std::make_shared<Model>(PGModel()));

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
    QTableWidget& table = *(ui->resultsTable);
    const std::vector<Node*>& nodes = solver_.nodes();

    table.clearContents();
    table.setRowCount(nodes.size());

    for(int i = 0; i < nodes.size(); ++i)
    {
        const Node* node = nodes[i];

        QTableWidgetItem *nodeId = new QTableWidgetItem(tr(std::to_string(i + 1).c_str()));
        QTableWidgetItem *parentBlock = new QTableWidgetItem(tr(node->block()->getName().c_str()));
        QTableWidgetItem *parentBlockType = new QTableWidgetItem(tr(node->block()->getType().c_str()));
        QTableWidgetItem *nodeType = new QTableWidgetItem(tr((node->isInput() ? "Input" : node->isOutput() ? "Output" : "Sink")));
        QTableWidgetItem *pressure = new QTableWidgetItem(tr(std::to_string(nodes[i]->solutionVariables().find("Pressure")->second.value).c_str()));

        int j = 0;
        table.setItem(i, j++, nodeId);
        table.setItem(i, j++, parentBlock);
        table.setItem(i, j++, parentBlockType);
        table.setItem(i, j++, nodeType);
        table.setItem(i, j++, pressure);
    }
}
