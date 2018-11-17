#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"QWidget"
#include <QtGui>
#include "QPixmap"
#include "vector"
#include "QLine"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    std::vector<QLine> data;
    int iter{0};
    int b{};
    int interval {200};
    int num{10};
    QTimer *timer;
    ~MainWindow();

public slots:
    void up();
    void value(int);

private slots:
    void on_pushButton_clicked();

    //void on_horizontalSlider_actionTriggered(int action);

    void on_horizontalSlider_sliderReleased();

    void on_spinBox_valueChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent *);
    void set_data();
};

#endif // MAINWINDOW_H
