#include <QDebug>
#include "MainWindow.h"
#include "ui_mainwindow.h"
#include "BlockDialog.h"
#include "Model.h"

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
    solvers_.push_back(Solver());
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
    Solver& solver = solvers_.back();
    std::vector<Block*> blocks = scene_->getBlocks();
    std::vector<Connector*> connectors = scene_->getConnectors();

    consoleLog("Solving for " + std::to_string(blocks.size()) + " blocks and " + std::to_string(connectors.size()) + " connectors...");
    solver.solve(blocks, connectors);
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
        else if(blockType == "Pressure Reservoir")
        {
            block = new PressureReservoir();
            image = QImage(":/blocks/images/pressure_reservoir.png");
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
    std::vector<Block*> blocks = scene_->getBlocks();
    std::vector<Connector*> connectors = scene_->getConnectors();

    if(model == "Simple Linear")
    {

    }
    else if(model == "P&G")
    {
        PGModel model;
        model.initialize(blocks, connectors);
    }
    else
        return;

    consoleLog("Flow model changed to \"" + model.toStdString() + "\".");
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
    const std::vector<const Node*>& nodes = solvers_.back().nodes();

    table.clearContents();
    table.setRowCount(nodes.size());

    for(int i = 0; i < nodes.size(); ++i)
    {
        QTableWidgetItem *nodeId = new QTableWidgetItem(tr(std::to_string(i + 1).c_str()));
        QTableWidgetItem *parentBlock = new QTableWidgetItem(tr(nodes[i]->block()->getName().c_str()));
        QTableWidgetItem *parentBlockType = new QTableWidgetItem(tr(nodes[i]->block()->getType().c_str()));

        table.setItem(i, 0, nodeId);
        table.setItem(i, 1, parentBlock);
        table.setItem(i, 2, parentBlockType);
    }
}
