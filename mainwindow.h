#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "graph_vizualizer.h"
#include "graphic_info.h"

#include <QKeyEvent>
#include <QMainWindow>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChartView>
#include <QtCharts/QtChartsVersion>
#include <QtCharts>
#include <QTimer>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void keyPressEvent(QKeyEvent *event);

    void on_lineA_textEdited(const QString &arg1);
    void on_lineA_textChanged(const QString &arg1);

    void on_lineB_textEdited(const QString &arg1);
    void on_lineB_textChanged(const QString &arg1);

    void on_lineC_textEdited(const QString &arg1);
    void on_lineC_textChanged(const QString &arg1);

    void on_lineF_textEdited(const QString &arg1);
    void on_lineF_textChanged(const QString &arg1);

    void on_lineT_textEdited(const QString &arg1);
    void on_lineT_textChanged(const QString &arg1);

    void on_lineS_textEdited(const QString &arg1);
    void on_lineS_textChanged(const QString &arg1);

    void on_formulas_cb__activated(int index);
    void on_brakeButton_clicked();
    void on_graphicButton_clicked();
    void on_startButton_clicked();
    void on_pauseButton_clicked();
    void closeEvent(QCloseEvent *event);

    void changeWindow();
    void reset_loc_series();
    void axes_print();
    void Time_delay();
    int waitUntilSignalIsEmitted(QObject *sender, const char *signal);

private:
    Ui::MainWindow *ui;
    QtCharts::QLineSeries *loc_series;
    graphic_info *gr_info;
    graph_vizualizer *root_;
};
#endif // MAINWINDOW_H
