#include "mainwindow.h"
#include <QApplication>

#include "mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.showMaximized();

    //MainWidget *mainWidget = new MainWidget();
    //mainWidget->showMaximized();

    return a.exec();
}
