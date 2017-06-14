#include "FanOptimizerDialog.h"
#include "ui_FanOptimizerDialog.h"

FanOptimizerDialog::FanOptimizerDialog(const std::vector<std::shared_ptr<Block> > &blocks, QWidget *parent)
    :
      QDialog(parent),
      ui(new Ui::FanOptimizerDialog)
{
    ui->setupUi(this);

    for(const std::shared_ptr<Block> &block: blocks)
        if(block->type() == "Fan")
            ui->fanComboBox->addItem(block->name.c_str());
}

FanOptimizerDialog::~FanOptimizerDialog()
{
    delete ui;
}

std::shared_ptr<FanOptimizer> FanOptimizerDialog::getFanOptimizer(std::shared_ptr<FlowModel> &model)
{

}
