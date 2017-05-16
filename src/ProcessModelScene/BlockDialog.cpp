#include "BlockDialog.h"
#include "ui_BlockDialog.h"

BlockDialog::BlockDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlockDialog)
{
    ui->setupUi(this);
}

BlockDialog::~BlockDialog()
{
    delete ui;
}

QString BlockDialog::getSelectedBlock() const
{
    return ui->blockTreeWidget->currentItem()->text(ui->blockTreeWidget->currentColumn());
}
