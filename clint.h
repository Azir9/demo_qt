#ifndef CLINT_H
#define CLINT_H

#include <QWidget>
#include <QTcpSocket>
#include <QDialog>
namespace Ui {
class clint;
}

class clint : public QWidget
{
    Q_OBJECT

public:
    explicit clint(QWidget *parent = 0);
    ~clint();

private slots:
    void on_B_connect__clicked();

    void on_B_disconnect__clicked();

    void on_B_close__clicked();

    void on_B_send__clicked();

private:
    Ui::clint *ui;

    QTcpSocket *tcpSoc_;
};

#endif // CLINT_H
