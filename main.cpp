#include "widget.h"
#include "clint.h"
#include <QApplication>
#include <QDialog>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    clint pika;
    pika.show();

    return a.exec();
}
