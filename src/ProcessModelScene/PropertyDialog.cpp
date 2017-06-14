#include <QFormLayout>
#include <QLabel>
#include <QDebug>

#include "PropertyDialog.h"
#include "ui_PropertyDialog.h"

PropertyDialog::PropertyDialog(const std::string &windowTitle,
                               const std::string &formTitle,
                               const std::map<std::string, double> &properties,
                               const std::map<std::string, double> &solution,
                               QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropertyDialog)
{
    ui->setupUi(this);
    setWindowTitle(windowTitle.c_str());
    ui->formGroupBox->setTitle(formTitle.c_str());

    QFormLayout *layout = new QFormLayout();

    for(auto &entry: properties)
    {
        QDoubleSpinBox *field = new QDoubleSpinBox();
        field->setMaximum(99999);
        field->setValue(entry.second);
        field->setAccelerated(true);
        layout->addRow((entry.first + ": ").c_str(), field);
        properties_[entry.first] = field;
    }

    for(const auto &entry: solution)
    {
        QLabel *label = new QLabel(std::to_string(entry.second).c_str());
        layout->addRow((entry.first + ": ").c_str(), label);
    }

    ui->formGroupBox->setLayout(layout);
}

PropertyDialog::~PropertyDialog()
{
    delete ui;
}

void PropertyDialog::accept()
{
    QDialog::accept();
}

std::map<std::string, double> PropertyDialog::properties() const
{
    std::map<std::string, double> properties;

    for(const auto& entry: properties_)
        properties[entry.first] = entry.second->value();

    return properties;
}

