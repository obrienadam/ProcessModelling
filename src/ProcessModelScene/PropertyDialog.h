#ifndef PROPERTY_DIALOG_H
#define PROPERTY_DIALOG_H

#include <QDialog>
#include <QDoubleSpinBox>

#include "Block.h"
#include "Connector.h"

namespace Ui {
class PropertyDialog;
}

class PropertyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PropertyDialog(const std::string& windowTitle,
                            const std::string& formTitle,
                            const std::map<std::string, double>& properties,
                            const std::map<std::string, double>& solution,
                            QWidget *parent = 0);

    ~PropertyDialog();

    void accept() override;

    std::map<std::string, double> properties() const;

private:
    Ui::PropertyDialog *ui;

    std::map<std::string, QDoubleSpinBox*> properties_;
};

#endif // PROPERTY_DIALOG_H
