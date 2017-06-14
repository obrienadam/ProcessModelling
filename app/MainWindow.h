#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>

#include "ProcessModelScene.h"
#include "FlowModel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    BlockGraphicsItem *addBlock(const std::string& blockType, const QPointF& pos = QPointF(0., 0.));

private slots:
    void on_actionConsole_toggled(bool arg1);
    void on_actionNode_Results_toggled(bool arg1);
    void on_actionConnector_Results_toggled(bool arg1);
    void on_actionRun_triggered();
    void on_actionNew_Block_triggered();
    void on_modelComboBox_currentIndexChanged(const QString &flowModel);
    void on_actionSave_triggered();
    void on_actionSave_As_triggered();
    void on_actionOpen_triggered();
    void on_actionFlow_model_triggered();

private:

    ProcessModelScene* getActiveProcessModel();

    void addBlockToModel(const std::string& type, const QPointF& pos = QPointF(0., 0.));
    void addConnector(int sourceNodeId, int baseNodeId);

    void consoleLog(const std::string& message);
    void consoleWarning(const std::string& message);
    void consoleError(const std::string& message);
    void postProcess(const std::vector<std::shared_ptr<Block> > &blocks, const std::vector<std::shared_ptr<Connector> > &connectors);

    Ui::MainWindow *ui;
    ProcessModelScene *scene_;

    std::shared_ptr<FlowModel> flowModel_;

    std::string filename_;
};

#endif // MAINWINDOW_H
