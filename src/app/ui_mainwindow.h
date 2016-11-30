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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFull_screen;
    QAction *actionNew_Component;
    QAction *actionConsole;
    QAction *actionNew_Sink;
    QAction *actionResults;
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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        actionFull_screen = new QAction(MainWindow);
        actionFull_screen->setObjectName(QStringLiteral("actionFull_screen"));
        actionNew_Component = new QAction(MainWindow);
        actionNew_Component->setObjectName(QStringLiteral("actionNew_Component"));
        actionConsole = new QAction(MainWindow);
        actionConsole->setObjectName(QStringLiteral("actionConsole"));
        actionConsole->setCheckable(true);
        actionNew_Sink = new QAction(MainWindow);
        actionNew_Sink->setObjectName(QStringLiteral("actionNew_Sink"));
        actionResults = new QAction(MainWindow);
        actionResults->setObjectName(QStringLiteral("actionResults"));
        actionResults->setCheckable(true);
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
        if (resultsTable->rowCount() < 4)
            resultsTable->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        resultsTable->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        resultsTable->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        resultsTable->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        resultsTable->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        resultsTable->setItem(0, 0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        resultsTable->setItem(0, 1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        resultsTable->setItem(0, 2, __qtablewidgetitem9);
        resultsTable->setObjectName(QStringLiteral("resultsTable"));

        verticalLayout_2->addWidget(resultsTable);

        resultsTableDockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), resultsTableDockWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuWindow->addAction(actionFull_screen);
        menuWindow->addAction(menuViews->menuAction());
        menuViews->addAction(actionConsole);
        menuViews->addAction(actionResults);

        retranslateUi(MainWindow);

        modelTabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Process Modeller", 0));
        actionFull_screen->setText(QApplication::translate("MainWindow", "Full Screen", 0));
        actionFull_screen->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+F11", 0));
        actionNew_Component->setText(QApplication::translate("MainWindow", "New Component", 0));
        actionConsole->setText(QApplication::translate("MainWindow", "Console", 0));
        actionNew_Sink->setText(QApplication::translate("MainWindow", "New Sink", 0));
        actionResults->setText(QApplication::translate("MainWindow", "Results", 0));
        modelTabWidget->setTabText(modelTabWidget->indexOf(modelTab), QApplication::translate("MainWindow", "New Model*", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0));
        menuViews->setTitle(QApplication::translate("MainWindow", "Views", 0));
        consoleDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Console", 0));
        resultsTableDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Results", 0));
        QTableWidgetItem *___qtablewidgetitem = resultsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Pressure", 0));
        QTableWidgetItem *___qtablewidgetitem1 = resultsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Flow rate", 0));
        QTableWidgetItem *___qtablewidgetitem2 = resultsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Temperature", 0));
        QTableWidgetItem *___qtablewidgetitem3 = resultsTable->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Node 1", 0));
        QTableWidgetItem *___qtablewidgetitem4 = resultsTable->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Node 2", 0));
        QTableWidgetItem *___qtablewidgetitem5 = resultsTable->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Node 3", 0));
        QTableWidgetItem *___qtablewidgetitem6 = resultsTable->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Node 4", 0));

        const bool __sortingEnabled = resultsTable->isSortingEnabled();
        resultsTable->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem7 = resultsTable->item(0, 0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "101325", 0));
        QTableWidgetItem *___qtablewidgetitem8 = resultsTable->item(0, 1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "20", 0));
        QTableWidgetItem *___qtablewidgetitem9 = resultsTable->item(0, 2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "293", 0));
        resultsTable->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
