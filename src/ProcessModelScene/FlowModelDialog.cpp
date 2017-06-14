#include "FlowModelDialog.h"
#include "ui_FlowModelDialog.h"

FlowModelDialog::FlowModelDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FlowModelDialog)
{
    ui->setupUi(this);
}

FlowModelDialog::~FlowModelDialog()
{
    delete ui;
}
