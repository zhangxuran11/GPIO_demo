#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gpio = NULL;
    gpio = new GPIO(107);
    gpio->setDirection(GPIO::OUT);
    gpio->setState(GPIO::L);
    qDebug()<<"gpio direction"<<(gpio->getDirection() == GPIO::IN?"IN":"OUT");
    qDebug()<<"gpio state"<<(gpio->getState() == GPIO::H?"H":"L");
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_updateButton_clicked()
{
    if(gpio == NULL)
        gpio = new GPIO(ui->io_nr->text().toInt());
    ui->io_dir->setText(gpio->getDirection() == GPIO::IN?"IN":"OUT");
    ui->io_val->setText(gpio->getState() == GPIO::H?"H":"L");

}
