#include <QFormLayout>
#include <QDebug>

#include "BlockPropertyDialog.h"
#include "ui_blockpropertydialog.h"

BlockPropertyDialog::BlockPropertyDialog(Block *block, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlockPropertyDialog),
    properties_(block->properties())
{
    initFields();
    setWindowTitle((block->name + " Properties").c_str());
    ui->formGroupBox->setTitle(("Block type: " + block->type).c_str());
}

BlockPropertyDialog::BlockPropertyDialog(Connector *connector, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlockPropertyDialog),
    properties_(connector->properties())
{
    initFields();
    setWindowTitle("Connector");
    ui->formGroupBox->setTitle("Connector type: standard");
}

BlockPropertyDialog::~BlockPropertyDialog()
{
    delete ui;
}

void BlockPropertyDialog::accept()
{
    int i = 0;
    for(QDoubleSpinBox *field: fields_)
        properties_[i++].value = field->value();

    QDialog::accept();
}

void BlockPropertyDialog::initFields()
{
    ui->setupUi(this);
    QFormLayout *layout = new QFormLayout();

    for(const Property& property: properties_)
    {
        QDoubleSpinBox *field = new QDoubleSpinBox();
        field->setRange(property.min, property.max);
        field->setValue(property.value);
        field->setSingleStep(std::min(0.01*(property.max - property.min), 10.));
        field->setAccelerated(true);

        layout->addRow((property.name + " (" + property.symbol + ")").c_str(), field);
        fields_.push_back(field);
    }

    ui->formGroupBox->setLayout(layout);
}