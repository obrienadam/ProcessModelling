#ifndef BLOCKPROPERTYDIALOG_H
#define BLOCKPROPERTYDIALOG_H

#include <QDialog>
#include <QDoubleSpinBox>

#include "Block.h"
#include "Connector.h"

namespace Ui {
class BlockPropertyDialog;
}

class BlockPropertyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BlockPropertyDialog(Block* block, QWidget *parent = 0);
    explicit BlockPropertyDialog(Connector* connector, QWidget *parent = 0);

    ~BlockPropertyDialog();

    void accept() override;

private:
    void initFields();

    Ui::BlockPropertyDialog *ui;
    std::map<std::string, Property>& properties_;
    QList<std::pair<Property*, QDoubleSpinBox*>> fields_;
};

#endif // BLOCKPROPERTYDIALOG_H
