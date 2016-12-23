#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include "ProcessModelScene.h"
#include "Solver.h"
#include "Model.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void writeSceneToFile(const std::string& filename);
    void loadSceneFromFile(const std::string& filename);

private slots:
    void on_actionConsole_toggled(bool arg1);
    void on_actionNode_Results_toggled(bool arg1);
    void on_actionConnector_Results_toggled(bool arg1);
    void on_actionSave_triggered();
    void on_actionRunSolver_triggered();
    void on_actionNew_Block_triggered();
    void on_modelComboBox_currentIndexChanged(const QString &model);

private:

    ProcessModelScene* getActiveProcessModel();

    void addBlockToModel(const std::string& type, const QPointF& pos = QPointF(0., 0.));
    void addConnector(int sourceNodeId, int baseNodeId);

    void consoleLog(const std::string& message);
    void consoleWarning(const std::string& message);
    void consoleError(const std::string& message);
    void postProcess(const std::vector<Block*>& blocks, const std::vector<Connector*>& connectors);

    Ui::MainWindow *ui;
    ProcessModelScene *scene_;

    //- Solver related objects
    Solver solver_;
};

#endif // MAINWINDOW_H
