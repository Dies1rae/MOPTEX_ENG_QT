#ifndef GRAPHIC_INFO_H
#define GRAPHIC_INFO_H

#include <QDialog>
#include "graph_vizualizer.h"

namespace Ui {
class graphic_info;
}

class graphic_info : public QDialog
{
    Q_OBJECT

public:
    explicit graphic_info(QWidget *parent = nullptr);
    ~graphic_info();

    void set_root(graph_vizualizer *r);

private slots:

    void on_pushButton_clicked();

    void on_save_button_clicked();

private:
    Ui::graphic_info *info_ui;
    graph_vizualizer *g_root_;
};

#endif // GRAPHIC_INFO_H
