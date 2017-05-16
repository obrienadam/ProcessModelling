#include <QFormLayout>
#include <QLabel>
#include <QDebug>

#include "BlockPropertyDialog.h"
#include "ui_blockpropertydialog.h"

BlockPropertyDialog::BlockPropertyDialog(Block *block, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlockPropertyDialog),
    properties_(block->properties()),
    solution_(block->solution())
{
    initFields();
    setWindowTitle((block->name + " Properties").c_str());
    ui->formGroupBox->setTitle(("Block type: " + block->type).c_str());
}

BlockPropertyDialog::BlockPropertyDialog(Connector *connector, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BlockPropertyDialog),
    properties_(connector->properties()),
    solution_(connector->solution())
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
    for(auto &field: fields_)
        field.first->value = field.second->value();

    QDialog::accept();
}

void BlockPropertyDialog::initFields()
{
    ui->setupUi(this);
    QFormLayout *layout = new QFormLayout();

    for(auto &entry: properties_)
    {
        Property& property = entry.second;

        QDoubleSpinBox *field = new QDoubleSpinBox();
        field->setRange(property.min, property.max);
        field->setValue(property.value);
        field->setSingleStep(std::min(0.01*(property.max - property.min), 10.));
        field->setAccelerated(true);

        layout->addRow((property.symbol + " (" + property.unit().name() + ")").c_str(), field);
        fields_.push_back(std::make_pair(&property, field));
    }

    for(const auto &entry: solution_)
    {
        const Solution& solution = entry.second;
        QLabel *label = new QLabel(std::to_string(solution.value).c_str());

        layout->addRow((solution.symbol + " (" + solution.unit + ")").c_str(), label);
    }

    ui->formGroupBox->setLayout(layout);
}
