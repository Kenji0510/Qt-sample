#include <QApplication>
#include "mainwindow.h"
#include "subwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    SubWindow sub_window;
    sub_window.show();

    return app.exec();
}