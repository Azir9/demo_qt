#include "clint.h"
#include "ui_clint.h"
#include <QHostAddress>
#include <QString>
clint::clint(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clint)
{
    ui->setupUi(this);
    setWindowTitle("clint ");


    tcpSoc_ = NULL;


    tcpSoc_ = new QTcpSocket(this);

    connect(tcpSoc_,&QTcpSocket::connected,
            [=]()
    {
            ui->B_connect_->setStyleSheet("color:red");
    }
            );

   connect(tcpSoc_,&QTcpSocket::readyRead,
           [=]()
   {

            QByteArray arr =  tcpSoc_->readAll();
            ui->E_read_->append(arr);
   }

           );

}

clint::~clint()
{
    delete ui;
}

void clint::on_B_connect__clicked()
{
    QString ip_ = ui->L_ip_->text();
    qint16 PORT_ = ui->L_port_->text().toInt();
    tcpSoc_->abort();
    tcpSoc_->connectToHost(QHostAddress(ip_), PORT_);
}

void clint::on_B_disconnect__clicked()
{
    //tcpSoc_->abort();
    tcpSoc_->disconnectFromHost();
    //tcpSoc_->disconnect();
    //tcpSoc_->close();
            ui->B_connect_->setStyleSheet("color:black");
}

void clint::on_B_close__clicked()
{
    tcpSoc_->disconnect();
    tcpSoc_->close();
    close();
}

void clint::on_B_send__clicked()
{
    //获取链接内容然后发送
    QString str = ui->E_write_->toPlainText();

    //发送数据，使用套接字tcpsocket
    tcpSoc_->write(str.toUtf8().data());

    qDebug() << str;
}
