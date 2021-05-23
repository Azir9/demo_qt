#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
/*
    * editer:taqiya
    * date:2021_5_23
    * vision:1.0
    param
    * send:发送按钮
    * close:关闭窗口
*/
    QPushButton *send;
    QPushButton *close_;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
