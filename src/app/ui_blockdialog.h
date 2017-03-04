/********************************************************************************
** Form generated from reading UI file 'blockdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKDIALOG_H
#define UI_BLOCKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BlockDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *blockTreeWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BlockDialog)
    {
        if (BlockDialog->objectName().isEmpty())
            BlockDialog->setObjectName(QStringLiteral("BlockDialog"));
        BlockDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(BlockDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        blockTreeWidget = new QTreeWidget(BlockDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(blockTreeWidget);
        __qtreewidgetitem->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(blockTreeWidget);
        __qtreewidgetitem1->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(blockTreeWidget);
        __qtreewidgetitem2->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem2);
        new QTreeWidgetItem(__qtreewidgetitem2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(blockTreeWidget);
        __qtreewidgetitem3->setFlags(Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        new QTreeWidgetItem(__qtreewidgetitem3);
        blockTreeWidget->setObjectName(QStringLiteral("blockTreeWidget"));
        blockTreeWidget->setAutoExpandDelay(0);

        verticalLayout->addWidget(blockTreeWidget);

        buttonBox = new QDialogButtonBox(BlockDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(BlockDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BlockDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BlockDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BlockDialog);
    } // setupUi

    void retranslateUi(QDialog *BlockDialog)
    {
        BlockDialog->setWindowTitle(QApplication::translate("BlockDialog", "Dialog", 0));
        QTreeWidgetItem *___qtreewidgetitem = blockTreeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("BlockDialog", "Blocks", 0));

        const bool __sortingEnabled = blockTreeWidget->isSortingEnabled();
        blockTreeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = blockTreeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("BlockDialog", "Power Input", 0));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("BlockDialog", "Fan", 0));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("BlockDialog", "Constant Flow Fan", 0));
        QTreeWidgetItem *___qtreewidgetitem4 = blockTreeWidget->topLevelItem(1);
        ___qtreewidgetitem4->setText(0, QApplication::translate("BlockDialog", "Flow control", 0));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem4->child(0);
        ___qtreewidgetitem5->setText(0, QApplication::translate("BlockDialog", "Restrictor Valve", 0));
        QTreeWidgetItem *___qtreewidgetitem6 = blockTreeWidget->topLevelItem(2);
        ___qtreewidgetitem6->setText(0, QApplication::translate("BlockDialog", "Reservoirs", 0));
        QTreeWidgetItem *___qtreewidgetitem7 = ___qtreewidgetitem6->child(0);
        ___qtreewidgetitem7->setText(0, QApplication::translate("BlockDialog", "Pressure Reservoir", 0));
        QTreeWidgetItem *___qtreewidgetitem8 = ___qtreewidgetitem6->child(1);
        ___qtreewidgetitem8->setText(0, QApplication::translate("BlockDialog", "Mass Flow Reservoir", 0));
        QTreeWidgetItem *___qtreewidgetitem9 = blockTreeWidget->topLevelItem(3);
        ___qtreewidgetitem9->setText(0, QApplication::translate("BlockDialog", "Connectors", 0));
        QTreeWidgetItem *___qtreewidgetitem10 = ___qtreewidgetitem9->child(0);
        ___qtreewidgetitem10->setText(0, QApplication::translate("BlockDialog", "Diffuser", 0));
        QTreeWidgetItem *___qtreewidgetitem11 = ___qtreewidgetitem9->child(1);
        ___qtreewidgetitem11->setText(0, QApplication::translate("BlockDialog", "Nozzle", 0));
        QTreeWidgetItem *___qtreewidgetitem12 = ___qtreewidgetitem9->child(2);
        ___qtreewidgetitem12->setText(0, QApplication::translate("BlockDialog", "T Connector", 0));
        QTreeWidgetItem *___qtreewidgetitem13 = ___qtreewidgetitem9->child(3);
        ___qtreewidgetitem13->setText(0, QApplication::translate("BlockDialog", "Y Connector", 0));
        blockTreeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class BlockDialog: public Ui_BlockDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKDIALOG_H
