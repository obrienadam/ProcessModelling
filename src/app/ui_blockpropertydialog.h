/********************************************************************************
** Form generated from reading UI file 'blockpropertydialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLOCKPROPERTYDIALOG_H
#define UI_BLOCKPROPERTYDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_BlockPropertyDialog
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *formGroupBox;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *BlockPropertyDialog)
    {
        if (BlockPropertyDialog->objectName().isEmpty())
            BlockPropertyDialog->setObjectName(QStringLiteral("BlockPropertyDialog"));
        BlockPropertyDialog->resize(240, 320);
        verticalLayout = new QVBoxLayout(BlockPropertyDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        formGroupBox = new QGroupBox(BlockPropertyDialog);
        formGroupBox->setObjectName(QStringLiteral("formGroupBox"));

        verticalLayout->addWidget(formGroupBox);

        buttonBox = new QDialogButtonBox(BlockPropertyDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(BlockPropertyDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), BlockPropertyDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), BlockPropertyDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(BlockPropertyDialog);
    } // setupUi

    void retranslateUi(QDialog *BlockPropertyDialog)
    {
        BlockPropertyDialog->setWindowTitle(QApplication::translate("BlockPropertyDialog", "Dialog", 0));
        formGroupBox->setTitle(QApplication::translate("BlockPropertyDialog", "GroupBox", 0));
    } // retranslateUi

};

namespace Ui {
    class BlockPropertyDialog: public Ui_BlockPropertyDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLOCKPROPERTYDIALOG_H
