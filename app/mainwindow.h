#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <vector>
#include <QMainWindow>
#include "ProcessModelViewer.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void runTest();

private slots:
    void on_actionNew_Component_triggered();
    void on_actionNew_Sink_triggered();

    void on_actionConsole_toggled(bool arg1);
    void on_actionResults_toggled(bool arg1);

private:

    void consoleLog(const std::string& message);
    void consoleWarning(const std::string& message);
    void consoleError(const std::string& message);

    Ui::MainWindow *ui;
    std::vector<ProcessModelViewer> models_;
};

#endif // MAINWINDOW_H
