#ifndef BLOCKPROPERTYDIALOG_H
#define BLOCKPROPERTYDIALOG_H

#include <QDialog>
#include <QDoubleSpinBox>

#include "Block.h"

namespace Ui {
class BlockPropertyDialog;
}

class BlockPropertyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BlockPropertyDialog(Block* block, QWidget *parent = 0);
    ~BlockPropertyDialog();

    void accept() override;

private:
    Ui::BlockPropertyDialog *ui;
    Block *block_;
    QList<QDoubleSpinBox*> fields_;
};

#endif // BLOCKPROPERTYDIALOG_H
