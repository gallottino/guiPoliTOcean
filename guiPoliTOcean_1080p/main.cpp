#include "mainwindow.h"
#include <QApplication>

#include "rovcontrol.h"

int main(int argc, char *argv[])
{
    RovControl* station;

    QApplication a(argc, argv);

    station = new RovControl();

    return a.exec();
}

