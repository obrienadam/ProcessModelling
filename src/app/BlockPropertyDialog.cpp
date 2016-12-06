#include <QFormLayout>
#include <QDebug>

#include "BlockPropertyDialog.h"
#include "ui_blockpropertydialog.h"

BlockPropertyDialog::BlockPropertyDialog(Block *block, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlockPropertyDialog),
    block_(block)
{
    ui->setupUi(this);
    setWindowTitle((block_->name + " Properties").c_str());
    QFormLayout *layout = new QFormLayout();

    for(const Property& property: block_->properties())
    {
        QDoubleSpinBox *field = new QDoubleSpinBox();
        field->setRange(property.min, property.max);
        field->setValue(property.value);
        field->setSingleStep(std::min(0.01*(property.max - property.min), 10.));
        field->setAccelerated(true);

        layout->addRow(property.name.c_str(), field);
        fields_.push_back(field);
    }

    ui->formGroupBox->setTitle(("Block type: " + block_->type).c_str());
    ui->formGroupBox->setLayout(layout);
}

BlockPropertyDialog::~BlockPropertyDialog()
{
    delete ui;
}

void BlockPropertyDialog::accept()
{
    int i = 0;
    for(QDoubleSpinBox *field: fields_)
        block_->properties()[i++].value = field->value();

    QDialog::accept();
}
