#include "graphic_info.h"
#include "ui_graphic_info.h"
#include <QDebug>

graphic_info::graphic_info(QWidget *parent) :
    QDialog(parent),
    info_ui(new Ui::graphic_info)
{
    info_ui->setupUi(this);

}

graphic_info::~graphic_info()
{
    delete info_ui;
}


void graphic_info::set_root(graph_vizualizer* r){
    this->g_root_ = r;
}

void graphic_info::on_pushButton_clicked()
{
      QTableWidget *coord_info = new QTableWidget(this->g_root_->get_res().size(), 2, this);
      coord_info->setMinimumWidth(1000);
      coord_info->setMinimumHeight(390);
      coord_info->verticalHeader()->setVisible(false);
      coord_info->setShowGrid(false);
      coord_info->setHorizontalHeaderLabels(QStringList() << tr("X") << tr("Y"));

      for(size_t ptr = 1; ptr < this->g_root_->get_res().size(); ptr++){
          QTableWidgetItem * item_x = new QTableWidgetItem(QString::number(this->g_root_->get_res()[ptr].first));
          QTableWidgetItem * item_y = new QTableWidgetItem( QString::number(this->g_root_->get_res()[ptr].second));
          coord_info->insertRow(ptr);
          coord_info->setItem(ptr,0,item_x);
          coord_info->setItem(ptr,1,item_y);
      }

      coord_info->show();
}

void graphic_info::on_save_button_clicked()
{
    this->g_root_->save_result();
}
