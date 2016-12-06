#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include "ProcessModelScene.h"
#include "Solver.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionConsole_toggled(bool arg1);
    void on_actionResults_toggled(bool arg1);
    void on_actionRunSolver_triggered();
    void on_actionNew_Block_triggered();
    void on_modelComboBox_currentIndexChanged(const QString &model);

private:

    ProcessModelScene* getActiveProcessModel();

    void consoleLog(const std::string& message);
    void consoleWarning(const std::string& message);
    void consoleError(const std::string& message);
    void postProcess(const std::vector<Block*>& blocks, const std::vector<Connector*>& connectors);

    Ui::MainWindow *ui;
    ProcessModelScene *scene_;

    //- Solver related objects
    std::vector<Solver> solvers_;
};

#endif // MAINWINDOW_H
