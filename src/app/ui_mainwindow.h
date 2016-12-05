/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFull_screen;
    QAction *actionConsole;
    QAction *actionResults;
    QAction *actionSolver_Settings;
    QAction *actionRunSolver;
    QAction *actionNew_Block;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *modelTabWidget;
    QWidget *modelTab;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuWindow;
    QMenu *menuViews;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *consoleDockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QTextBrowser *console;
    QDockWidget *resultsTableDockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *resultsTable;
    QDockWidget *solverSettingsDockWidget;
    QWidget *dockWidgetContents_4;
    QGridLayout *gridLayout;
    QTreeView *solverSettingsTree;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        actionFull_screen = new QAction(MainWindow);
        actionFull_screen->setObjectName(QStringLiteral("actionFull_screen"));
        actionConsole = new QAction(MainWindow);
        actionConsole->setObjectName(QStringLiteral("actionConsole"));
        actionConsole->setCheckable(true);
        actionResults = new QAction(MainWindow);
        actionResults->setObjectName(QStringLiteral("actionResults"));
        actionResults->setCheckable(true);
        actionSolver_Settings = new QAction(MainWindow);
        actionSolver_Settings->setObjectName(QStringLiteral("actionSolver_Settings"));
        actionSolver_Settings->setCheckable(true);
        actionRunSolver = new QAction(MainWindow);
        actionRunSolver->setObjectName(QStringLiteral("actionRunSolver"));
        actionNew_Block = new QAction(MainWindow);
        actionNew_Block->setObjectName(QStringLiteral("actionNew_Block"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        modelTabWidget = new QTabWidget(centralWidget);
        modelTabWidget->setObjectName(QStringLiteral("modelTabWidget"));
        modelTabWidget->setTabsClosable(true);
        modelTabWidget->setMovable(true);
        modelTab = new QWidget();
        modelTab->setObjectName(QStringLiteral("modelTab"));
        verticalLayout = new QVBoxLayout(modelTab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        graphicsView = new QGraphicsView(modelTab);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setContextMenuPolicy(Qt::ActionsContextMenu);
        graphicsView->setFrameShape(QFrame::WinPanel);
        graphicsView->setFrameShadow(QFrame::Sunken);
        graphicsView->setDragMode(QGraphicsView::NoDrag);

        verticalLayout->addWidget(graphicsView);

        modelTabWidget->addTab(modelTab, QString());

        horizontalLayout_2->addWidget(modelTabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 19));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QStringLiteral("menuWindow"));
        menuViews = new QMenu(menuWindow);
        menuViews->setObjectName(QStringLiteral("menuViews"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        consoleDockWidget = new QDockWidget(MainWindow);
        consoleDockWidget->setObjectName(QStringLiteral("consoleDockWidget"));
        consoleDockWidget->setAllowedAreas(Qt::BottomDockWidgetArea|Qt::TopDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        console = new QTextBrowser(dockWidgetContents);
        console->setObjectName(QStringLiteral("console"));

        verticalLayout_3->addWidget(console);

        consoleDockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), consoleDockWidget);
        resultsTableDockWidget = new QDockWidget(MainWindow);
        resultsTableDockWidget->setObjectName(QStringLiteral("resultsTableDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        resultsTable = new QTableWidget(dockWidgetContents_2);
        if (resultsTable->columnCount() < 3)
            resultsTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        resultsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        resultsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        resultsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        resultsTable->setObjectName(QStringLiteral("resultsTable"));
        resultsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(resultsTable);

        resultsTableDockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), resultsTableDockWidget);
        solverSettingsDockWidget = new QDockWidget(MainWindow);
        solverSettingsDockWidget->setObjectName(QStringLiteral("solverSettingsDockWidget"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        gridLayout = new QGridLayout(dockWidgetContents_4);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        solverSettingsTree = new QTreeView(dockWidgetContents_4);
        solverSettingsTree->setObjectName(QStringLiteral("solverSettingsTree"));

        gridLayout->addWidget(solverSettingsTree, 1, 0, 1, 1);

        solverSettingsDockWidget->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), solverSettingsDockWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuWindow->addAction(actionFull_screen);
        menuWindow->addAction(menuViews->menuAction());
        menuViews->addAction(actionConsole);
        menuViews->addAction(actionResults);
        menuViews->addAction(actionSolver_Settings);
        mainToolBar->addAction(actionRunSolver);

        retranslateUi(MainWindow);

        modelTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Process Modeller", 0));
        actionFull_screen->setText(QApplication::translate("MainWindow", "Full Screen", 0));
        actionFull_screen->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+F11", 0));
        actionConsole->setText(QApplication::translate("MainWindow", "Console", 0));
        actionResults->setText(QApplication::translate("MainWindow", "Results", 0));
        actionSolver_Settings->setText(QApplication::translate("MainWindow", "Solver Settings", 0));
        actionRunSolver->setText(QApplication::translate("MainWindow", "Run Solver", 0));
#ifndef QT_NO_TOOLTIP
        actionRunSolver->setToolTip(QApplication::translate("MainWindow", "Run Solver", 0));
#endif // QT_NO_TOOLTIP
        actionNew_Block->setText(QApplication::translate("MainWindow", "New Block", 0));
#ifndef QT_NO_TOOLTIP
        actionNew_Block->setToolTip(QApplication::translate("MainWindow", "Create a new block", 0));
#endif // QT_NO_TOOLTIP
        modelTabWidget->setTabText(modelTabWidget->indexOf(modelTab), QApplication::translate("MainWindow", "New Model*", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0));
        menuViews->setTitle(QApplication::translate("MainWindow", "Views", 0));
        consoleDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Console", 0));
        resultsTableDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Results", 0));
        QTableWidgetItem *___qtablewidgetitem = resultsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Node ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = resultsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Parent Block", 0));
        QTableWidgetItem *___qtablewidgetitem2 = resultsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Parent Block Type", 0));
        solverSettingsDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Solver settings", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
