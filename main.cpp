#include <QtGui/QApplication>
#include <QDebug>
#include <QPointer>
#include "logbrowser.h"

QPointer<LogBrowser> logBrowser;

void myMessageOutput(QtMsgType type, const char *msg)
{
    if (logBrowser)
        logBrowser->outputMessage(type, msg);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    logBrowser = new LogBrowser;
    qInstallMsgHandler(myMessageOutput);

    qDebug() << "test fo debug";
    int result = a.exec();
    qDebug() << "application exec return result = " << result;

    delete logBrowser;
    return result;
}
