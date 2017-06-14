#ifndef FLOWMODELDIALOG_H
#define FLOWMODELDIALOG_H

#include <QDialog>

namespace Ui {
class FlowModelDialog;
}

class FlowModelDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FlowModelDialog(QWidget *parent = 0);
    ~FlowModelDialog();

private:
    Ui::FlowModelDialog *ui;
};

#endif // FLOWMODELDIALOG_H
