#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <qdebug.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    send = new QPushButton(this);
    close_ = new QPushButton(this);


    send->setText("发送");
    send->move(50,600);
    close_->setText("关闭");
    close_->move(200,600);


    connect(close_, &QPushButton::released,
            [=]()mutable
               {
                    qDebug()<< "23";
                    close();
               }
            );

}

MainWindow::~MainWindow()
{
    delete ui;
}
