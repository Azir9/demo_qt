#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    //监听套接字，指定父对象自动回收空间，自动回收空间
    tcpSer = new QTcpServer(this);
    //对应的ip和端口
    tcpSer->listen(QHostAddress::Any,8888);
    //用lamda表达式
    connect(tcpSer,&QTcpServer::newConnection,
            [=]()
            {
                tcpsoc = tcpSer->nextPendingConnection();
                QString ip = tcpsoc->peerAddress().toString();
                qint16 port = tcpsoc->peerPort();\
                QString temp = QString("[]:成功链接").arg(ip).arg(port);
                ui->read->setText(temp);
            }
            );
    //通信套接字
    tcpsoc = new QTcpSocket(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    //获取链接内容然后发送
    QString str = ui->write->toPlainText();
    tcpsoc->write(str.toUtf8().data());
}

void Widget::on_send_clicked()
{
    close();
}
