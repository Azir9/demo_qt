#include "widget.h"
#include "ui_widget.h"
#include "QString"
#include "QDebug"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    tcpSer = NULL;
    tcpsoc = NULL;
    ui->setupUi(this);
    //监听套接字，指定父对象自动回收空间，自动回收空间
    tcpSer = new QTcpServer(this);
    //对应的ip和端口

    //通信套接字
    tcpsoc = new QTcpSocket(this);
    tcpSer->listen(QHostAddress::Any,8888);
    //用lamda表达式
    connect(tcpSer,&QTcpServer::newConnection,
            [=]()
            {
                tcpsoc = tcpSer->nextPendingConnection();
                QString ip = tcpsoc->peerAddress().toString();
                qint16 port = tcpsoc->peerPort();



                ip_ = ip;
                port_  = port;
                QString temp = QString("[%1,%2]:success pika").arg(ip).arg(port);
                ui->read->setText(temp);

                connect(tcpsoc,&QTcpSocket::readyRead,
                        [=]()
                {
                        qDebug()<<"disconnect";
                        //从通信套接字取出内容
                        QByteArray arr =   tcpsoc->readAll();
                        ui->read->append(arr);
                }

                        );



            }
            );






}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{

    //获取链接内容然后发送
    QString str = ui->write->toPlainText();

    //发送数据，使用套接字tcpsocket
    tcpsoc->write(str.toUtf8().data());

    qDebug() << str;
}

void Widget::on_send_clicked()
{
    tcpsoc->disconnectFromHost();
    tcpsoc->close();
    close();
}
