#include <QApplication>
// #include "mainwindow.h"
// #include "subwindow.h"
#include "openglsample.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // MainWindow window;
    // window.show();

    // SubWindow sub_window;
    // sub_window.show();

    OpenGLWindow opengl_window;
    // opengl_window.resize(800, 600);
    opengl_window.show();

    return app.exec();
}