#ifndef FANOPTIMIZERDIALOG_H
#define FANOPTIMIZERDIALOG_H

#include <QDialog>

#include "Optimizer/FanOptimizer.h"
#include "Model/FlowModel.h"

namespace Ui {
class FanOptimizerDialog;
}

class FanOptimizerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FanOptimizerDialog(const std::vector<std::shared_ptr<Block>>& blocks, QWidget *parent = 0);
    ~FanOptimizerDialog();

    std::shared_ptr<FanOptimizer> getFanOptimizer(std::shared_ptr<FlowModel>& model);

private:
    Ui::FanOptimizerDialog *ui;
};

#endif // FANOPTIMIZERDIALOG_H
