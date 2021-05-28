#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpServer> //监听套接字
#include <QTcpSocket> //通信套接字
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_send_clicked();

private:
    Ui::Widget *ui;


    QTcpServer *tcpSer;//监听套接字
    QTcpSocket *tcpsoc;//通信套接字
};

#endif // WIDGET_H
