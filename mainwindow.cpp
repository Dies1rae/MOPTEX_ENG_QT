#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QString"
#include "QtDebug"
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->reset_loc_series();
    this->root_ = new graph_vizualizer();
    this->gr_info = new graphic_info();

    ui->formulas_cb_->addItem("Choose formula");
    for(size_t ptr = 0; ptr < this->root_->get_core_formulas().size(); ptr++){
        QString tmp_f = QString::fromStdString(this->root_->get_core_formulas()[ptr]);
        ui->formulas_cb_->addItem(tmp_f);
    }

    gr_info->set_root(this->root_);
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::axes_print(){
    for(int ptr = 0; ptr < 50; ptr ++){
        this->loc_series->append(0.0,ptr);
    }
    for(int ptr = 0; ptr < 51; ptr ++){
        this->loc_series->append(ptr,0.0);
    }

    for(int ptr = 0; ptr > -50; ptr --){
        this->loc_series->append(ptr,0.0);
    }
    for(int ptr = 0; ptr > -50; ptr --){
        this->loc_series->append(0.0,ptr);
    }
}

void MainWindow::reset_loc_series(){
    QtCharts::QChart * loc_chart = new QtCharts::QChart();
    loc_chart->legend()->hide();
    QtCharts::QValueAxis *axisX = new QtCharts::QValueAxis();
    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
    loc_chart->addAxis(axisX, Qt::AlignLeft);
    loc_chart->addAxis(axisY, Qt::AlignBottom);

    loc_series = new QtCharts::QLineSeries(loc_chart);
    loc_chart->addSeries(loc_series);
    loc_series->attachAxis(axisX);
    loc_series->attachAxis(axisY);
    axisX->setRange(-50.0,50.0);
    axisY->setRange(-50.0,50.0);
    loc_series->setUseOpenGL(true);
    QtCharts::QChartView* graphic_ = new QtCharts::QChartView(loc_chart);
    this->axes_print();
    ui->graphics_layout->layout()->addWidget(graphic_);

}

void MainWindow::keyPressEvent(QKeyEvent *event){
    switch(event->key())
        {
        case Qt::Key_Escape:
            this->on_brakeButton_clicked();
            break;
    case Qt::Key_Enter:
        this->on_startButton_clicked();
        break;
        default:
            QMainWindow::keyPressEvent(event);
        }
}

void MainWindow::changeWindow(){
    if(this->gr_info->isVisible()){
        this->gr_info->hide();
        this->show();
    } else {
        this->hide();
        this->gr_info->show();
    }
}

void MainWindow::closeEvent (QCloseEvent *event){
    QMessageBox::StandardButton resBtn = QMessageBox::question( this, "GVizualizer",
                                                                   tr("Are you sure?\n"),
                                                                   QMessageBox::Cancel | QMessageBox::No | QMessageBox::Yes,
                                                                   QMessageBox::Yes);
       if (resBtn != QMessageBox::Yes) {
           event->ignore();
       } else {
           event->accept();
       }
}

void MainWindow::on_lineA_textEdited(const QString &arg1)
{
    double tmpA;
    if(arg1.isEmpty()){
        tmpA = 0.0;
    } else {
        tmpA = arg1.toDouble();
    }
    this->root_->set_a(tmpA);
}
void MainWindow::on_lineA_textChanged(const QString &arg1)
{
    double tmpA;
    if(arg1.isEmpty()){
        tmpA = 0.0;
    } else {
        tmpA = arg1.toDouble();
    }
    this->root_->set_a(tmpA);
}

void MainWindow::on_lineB_textEdited(const QString &arg1){
    double tmpB;
    if(arg1.isEmpty()){
        tmpB = 0.0;
    } else {
        tmpB = arg1.toDouble();
    }
    this->root_->set_b(tmpB);
}
void MainWindow::on_lineB_textChanged(const QString &arg1){
    double tmpB;
    if(arg1.isEmpty()){
        tmpB = 0.0;
    } else {
        tmpB = arg1.toDouble();
    }
    this->root_->set_b(tmpB);
}

void MainWindow::on_lineC_textEdited(const QString &arg1){
    double tmpC;
    if(arg1.isEmpty()){
        tmpC = 0.0;
    } else {
        tmpC = arg1.toDouble();
    }
    this->root_->set_c(tmpC);
}
void MainWindow::on_lineC_textChanged(const QString &arg1){
    double tmpC;
    if(arg1.isEmpty()){
        tmpC = 0.0;
    } else {
        tmpC = arg1.toDouble();
    }
    this->root_->set_c(tmpC);
}

void MainWindow::on_lineF_textEdited(const QString &arg1){
    double tmpF;
    if(arg1.isEmpty()){
        tmpF = 0.0;
    } else {
        tmpF = arg1.toDouble();
    }
    this->root_->set_from(tmpF);
}
void MainWindow::on_lineF_textChanged(const QString &arg1){
    double tmpF;
    if(arg1.isEmpty()){
        tmpF = 0.0;
    } else {
        tmpF = arg1.toDouble();
    }
    this->root_->set_from(tmpF);
}

void MainWindow::on_lineT_textEdited(const QString &arg1){
    double tmpT;
    if(arg1.isEmpty()){
        tmpT = 0.0;
    } else {
        tmpT = arg1.toDouble();
    }
    this->root_->set_to(tmpT);
}
void MainWindow::on_lineT_textChanged(const QString &arg1){
    double tmpT;
    if(arg1.isEmpty()){
        tmpT = 0.0;
    } else {
        tmpT = arg1.toDouble();
    }
    this->root_->set_to(tmpT);
}

void MainWindow::on_lineS_textEdited(const QString &arg1){
    double tmpS;
    if(arg1.isEmpty()){
        tmpS = 0.0;
    } else {
        tmpS = arg1.toDouble();
    }
    this->root_->set_step(tmpS);
}
void MainWindow::on_lineS_textChanged(const QString &arg1){
    double tmpS;
    if(arg1.isEmpty()){
        tmpS = 0.0;
    } else {
        tmpS = arg1.toDouble();
    }
    this->root_->set_step(tmpS);
}

void MainWindow::on_brakeButton_clicked()
{
    ui->lineA->setDisabled(0);
    ui->lineB->setDisabled(0);
    ui->lineC->setDisabled(0);
    ui->lineF->setDisabled(0);
    ui->lineT->setDisabled(0);
    ui->lineS->setDisabled(0);
    ui->formulas_cb_->setDisabled(0);
    this->root_->set_brake(true);
    this->root_->set_pause(true);
    this->root_->set_start(false);
    this->root_->set_a(0.0);
    this->root_->set_b(0.0);
    this->root_->set_c(0.0);
    this->root_->set_from(0.0);
    this->root_->set_to(0.0);
    this->root_->set_step(0.0);
    this->root_->set_formula(0);

    this->ui->formulas_cb_->setCurrentIndex(0);
    this->ui->lineA->clear();
    this->ui->lineB->clear();
    this->ui->lineC->clear();
    this->ui->lineF->clear();
    this->ui->lineT->clear();
    this->ui->lineS->clear();

    ui->startButton->setText("New");
    ui->pauseButton->setText("Pause");

    this->loc_series->clear();
    this->axes_print();
}

void MainWindow::on_formulas_cb__activated(int index)
{
    this->root_->set_formula(index);
}


void MainWindow::on_graphicButton_clicked()
{
    if(this->root_->get_form_num() != 0){
        this->gr_info->setWindowTitle(QString::fromStdString(this->root_->get_core_formulas()[this->root_->get_form_num() - 1]));
    } else {
        this->gr_info->setWindowTitle("Empty");
    }
    this->gr_info->show();

}

void MainWindow::Time_delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 700);
}

void MainWindow::on_startButton_clicked()
{
    if(ui->startButton->text() == "Start"){
        this->loc_series->clear();
        this->axes_print();
        this->root_->clear_res_points();
        this->root_->set_quit(false);
        this->root_->set_pause(false);
        this->root_->set_brake(false);
        this->root_->set_start(true);

        ui->lineA->setDisabled(1);
        ui->lineB->setDisabled(1);
        ui->lineC->setDisabled(1);
        ui->lineF->setDisabled(1);
        ui->lineT->setDisabled(1);
        ui->lineS->setDisabled(1);
        ui->formulas_cb_->setDisabled(1);

        this->root_->main_menu_loop();
        ui->startButton->setText("Progress-");
        for(size_t ptr = 0; ptr < this->root_->get_res().size(); ptr ++){
            if(this->root_->get_pause()){
                this->waitUntilSignalIsEmitted(ui->pauseButton, SIGNAL(clicked()));
            }
            this->loc_series->append(this->root_->get_res()[ptr].first, this->root_->get_res()[ptr].second);
            double progress = (ptr / ((this->root_->get_to() - this->root_->get_from()) / this->root_->get_step())) * 100;
            ui->startButton->setText("Progress: " + QString::number(progress));
            this->Time_delay();
        }
    } else if(ui->startButton->text() == "New") {
        ui->lineA->setDisabled(0);
        ui->lineB->setDisabled(0);
        ui->lineC->setDisabled(0);
        ui->lineF->setDisabled(0);
        ui->lineT->setDisabled(0);
        ui->lineS->setDisabled(0);
        ui->formulas_cb_->setDisabled(0);

        this->root_->set_brake(true);
        this->root_->set_pause(true);
        this->root_->set_start(false);
        this->root_->set_a(0.0);
        this->root_->set_b(0.0);
        this->root_->set_c(0.0);
        this->root_->set_from(0.0);
        this->root_->set_to(0.0);
        this->root_->set_step(0.0);
        this->root_->set_formula(0);

        this->ui->formulas_cb_->setCurrentIndex(0);
        this->ui->lineA->clear();
        this->ui->lineB->clear();
        this->ui->lineC->clear();
        this->ui->lineF->clear();
        this->ui->lineT->clear();
        this->ui->lineS->clear();

        ui->startButton->setText("Start");
        ui->pauseButton->setText("Pause");

        this->loc_series->clear();
        this->axes_print();
    } else {
        this->on_brakeButton_clicked();
    }
}

int MainWindow::waitUntilSignalIsEmitted(QObject *sender, const char *signal) {
    QEventLoop loop;
    connect(sender, signal, &loop, SLOT(quit()));
    return loop.exec();
}

void MainWindow::on_pauseButton_clicked(){
    if(!this->root_->get_pause()){
        this->root_->set_pause(true);
        ui->pauseButton->setText("Continue");
    } else {
        this->root_->set_pause(false);
        ui->pauseButton->setText("Pause");
    }
}
