#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::set_data()
{
    int d = int(280/num);
    QLine l;
    for(int j{}; j<num; j++)
    {
        l = QLine::QLine(20, 20 + d*j, 60 + d*j, 300);
        data.push_back(l);
    }

}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    QLine l1(20,300, 20, 20);
    QLine l2(20, 300, 300, 300);
    data.push_back(l1);
    data.push_back(l2);

    ui->setupUi(this);
    ui->spinBox->setValue(10);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(up()));
    timer->start(interval);
    ui->horizontalSlider->setMinimum(100);
    ui->horizontalSlider->setMaximum(1000);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent*)
{
    if(iter<data.size())
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(Qt::darkGreen);
        for(int i{0}; i< iter; i++)
            painter.drawLine(data[i]);
    }
}

void MainWindow::up()
{
    if(b !=0 && iter<data.size()-1)
    {
        iter++;
        update();
    }
}

void MainWindow::on_pushButton_clicked()
{
    b =1;
    iter =0;
}

void MainWindow::value(int v)
{

    iter =0;
    timer->setInterval(v);

}

void MainWindow::on_horizontalSlider_sliderReleased()
{
    MainWindow::value(ui->horizontalSlider->value());
}

void MainWindow::on_spinBox_valueChanged(const QString &arg1)
{
    iter =0;
    data.clear();
    QLine l1(20,300, 20, 20);
    QLine l2(20, 300, 300, 300);
    data.push_back(l1);
    data.push_back(l2);
    num = int(ui->spinBox->value());
    set_data();
}


