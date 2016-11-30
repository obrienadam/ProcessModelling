#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Fan.h"
#include "PressureReservoir.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->addAction(ui->actionNew_Component);
    ui->graphicsView->addAction(ui->actionNew_Sink);
    ui->graphicsView->setMouseTracking(true);

    consoleLog("Gemini version 0.0 Copyright (C) 2016 Adam Robert O'Brien");
    consoleLog("Initialization completed.");
    consoleWarning("This is a very early alpha version. Only a handful of features are currently functioning. Use at your own risk!");
    runTest();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::runTest()
{
    ProcessModelViewer* pm = new ProcessModelViewer();
    ui->graphicsView->setScene(pm);
}

void MainWindow::on_actionNew_Component_triggered()
{
    QGraphicsView* source = nullptr;

    for(QWidget *widget: ui->actionNew_Component->associatedWidgets())
        if(widget->hasFocus())
            source = (QGraphicsView*)widget;

    if(source == nullptr)
        return;

    ProcessModelViewer* processModel = (ProcessModelViewer*)source->scene();
    BlockGraphicsObject *component = new BlockGraphicsObject(new Fan());
    QPointF loc = source->mapToScene(source->mapFromGlobal(QCursor::pos()));

    component->setPos(loc);
    processModel->addBlock(component);
    consoleLog("Successfully added new component of type \"" + component->block()->type + "\".");
}

void MainWindow::on_actionNew_Sink_triggered()
{
    QGraphicsView* source = nullptr;

    for(QWidget *widget: ui->actionNew_Component->associatedWidgets())
        if(widget->hasFocus())
            source = (QGraphicsView*)widget;

    if(source == nullptr)
        return;

    ProcessModelViewer* processModel = (ProcessModelViewer*)source->scene();
    BlockGraphicsObject *sink = new BlockGraphicsObject(new PressureReservoir());
    QPointF loc = source->mapToScene(source->mapFromGlobal(QCursor::pos()));

    sink->setPos(loc);
    processModel->addBlock(sink);
    consoleLog("Successfully added new sink of type \"" + sink->block()->type + "\".");
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
