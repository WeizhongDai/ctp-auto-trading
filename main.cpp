#include <QtGui/QApplication>
#include <QMainWindow>
#include "ui_ctpmain.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Ui::ctpwindow ui;
    QMainWindow *ctpwindow = new QMainWindow;
    ui.setupUi(ctpwindow);
    ctpwindow->show();

    return a.exec();
}
