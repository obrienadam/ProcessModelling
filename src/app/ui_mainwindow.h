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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
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
    QAction *actionConsole;
    QAction *actionNode_Results;
    QAction *actionRunSolver;
    QAction *actionNew_Block;
    QAction *actionConnector_Results;
    QAction *actionSave;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QFormLayout *formLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QComboBox *modelComboBox;
    QLabel *label_2;
    QComboBox *solverComboBox;
    QSpacerItem *horizontalSpacer;
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
    QDockWidget *nodeResultsDockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *nodeResultsTable;
    QDockWidget *connectorResultsDockWidget;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout;
    QTableWidget *connectorResultsTable;

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
        actionNode_Results = new QAction(MainWindow);
        actionNode_Results->setObjectName(QStringLiteral("actionNode_Results"));
        actionNode_Results->setCheckable(true);
        actionRunSolver = new QAction(MainWindow);
        actionRunSolver->setObjectName(QStringLiteral("actionRunSolver"));
        actionNew_Block = new QAction(MainWindow);
        actionNew_Block->setObjectName(QStringLiteral("actionNew_Block"));
        actionConnector_Results = new QAction(MainWindow);
        actionConnector_Results->setObjectName(QStringLiteral("actionConnector_Results"));
        actionConnector_Results->setCheckable(true);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(0);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        modelComboBox = new QComboBox(centralWidget);
        modelComboBox->setObjectName(QStringLiteral("modelComboBox"));

        horizontalLayout->addWidget(modelComboBox);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        solverComboBox = new QComboBox(centralWidget);
        solverComboBox->setObjectName(QStringLiteral("solverComboBox"));

        horizontalLayout->addWidget(solverComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);


        verticalLayout_4->addLayout(formLayout);

        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setContextMenuPolicy(Qt::ActionsContextMenu);
        graphicsView->setFrameShape(QFrame::WinPanel);
        graphicsView->setRenderHints(QPainter::HighQualityAntialiasing|QPainter::SmoothPixmapTransform|QPainter::TextAntialiasing);

        verticalLayout_4->addWidget(graphicsView);

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
        nodeResultsDockWidget = new QDockWidget(MainWindow);
        nodeResultsDockWidget->setObjectName(QStringLiteral("nodeResultsDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        nodeResultsTable = new QTableWidget(dockWidgetContents_2);
        if (nodeResultsTable->columnCount() < 5)
            nodeResultsTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        nodeResultsTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        nodeResultsTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        nodeResultsTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        nodeResultsTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        nodeResultsTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        nodeResultsTable->setObjectName(QStringLiteral("nodeResultsTable"));
        nodeResultsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(nodeResultsTable);

        nodeResultsDockWidget->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), nodeResultsDockWidget);
        connectorResultsDockWidget = new QDockWidget(MainWindow);
        connectorResultsDockWidget->setObjectName(QStringLiteral("connectorResultsDockWidget"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QStringLiteral("dockWidgetContents_4"));
        verticalLayout = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        connectorResultsTable = new QTableWidget(dockWidgetContents_4);
        if (connectorResultsTable->columnCount() < 5)
            connectorResultsTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        connectorResultsTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        connectorResultsTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        connectorResultsTable->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        connectorResultsTable->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        connectorResultsTable->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        connectorResultsTable->setObjectName(QStringLiteral("connectorResultsTable"));
        connectorResultsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout->addWidget(connectorResultsTable);

        connectorResultsDockWidget->setWidget(dockWidgetContents_4);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), connectorResultsDockWidget);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuFile->addAction(actionSave);
        menuWindow->addAction(actionFull_screen);
        menuWindow->addAction(menuViews->menuAction());
        menuViews->addAction(actionConsole);
        menuViews->addAction(actionNode_Results);
        menuViews->addAction(actionConnector_Results);
        mainToolBar->addAction(actionRunSolver);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Process Modeller", 0));
        actionFull_screen->setText(QApplication::translate("MainWindow", "Full Screen", 0));
        actionFull_screen->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+F11", 0));
        actionConsole->setText(QApplication::translate("MainWindow", "Console", 0));
        actionNode_Results->setText(QApplication::translate("MainWindow", "Node Results", 0));
        actionRunSolver->setText(QApplication::translate("MainWindow", "Run Solver", 0));
#ifndef QT_NO_TOOLTIP
        actionRunSolver->setToolTip(QApplication::translate("MainWindow", "Run Solver", 0));
#endif // QT_NO_TOOLTIP
        actionNew_Block->setText(QApplication::translate("MainWindow", "New Block", 0));
#ifndef QT_NO_TOOLTIP
        actionNew_Block->setToolTip(QApplication::translate("MainWindow", "Create a new block", 0));
#endif // QT_NO_TOOLTIP
        actionConnector_Results->setText(QApplication::translate("MainWindow", "Connector Results", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0));
        label->setText(QApplication::translate("MainWindow", "Model:  ", 0));
        modelComboBox->clear();
        modelComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Simple Linear", 0)
         << QApplication::translate("MainWindow", "P&G", 0)
        );
        label_2->setText(QApplication::translate("MainWindow", "Solver: ", 0));
        solverComboBox->clear();
        solverComboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Flow Solve", 0)
         << QApplication::translate("MainWindow", "Fan Optimization", 0)
        );
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0));
        menuWindow->setTitle(QApplication::translate("MainWindow", "Window", 0));
        menuViews->setTitle(QApplication::translate("MainWindow", "Views", 0));
        consoleDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Console", 0));
        nodeResultsDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Node Results", 0));
        QTableWidgetItem *___qtablewidgetitem = nodeResultsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Node ID", 0));
        QTableWidgetItem *___qtablewidgetitem1 = nodeResultsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Parent Block", 0));
        QTableWidgetItem *___qtablewidgetitem2 = nodeResultsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Parent Block Type", 0));
        QTableWidgetItem *___qtablewidgetitem3 = nodeResultsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Node Type", 0));
        QTableWidgetItem *___qtablewidgetitem4 = nodeResultsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Pressure", 0));
        connectorResultsDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Connector Results", 0));
        QTableWidgetItem *___qtablewidgetitem5 = connectorResultsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Connector ID", 0));
        QTableWidgetItem *___qtablewidgetitem6 = connectorResultsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Source Node ID", 0));
        QTableWidgetItem *___qtablewidgetitem7 = connectorResultsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Destination Node ID", 0));
        QTableWidgetItem *___qtablewidgetitem8 = connectorResultsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Resistance", 0));
        QTableWidgetItem *___qtablewidgetitem9 = connectorResultsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Flow Rate", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
