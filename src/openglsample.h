#ifndef OPENGLSAMPLE_H
#define OPENGLSAMPLE_H

#include <GL/glew.h>

#include <QOpenGLWidget>
// #include <QOpenGLFunctions>

class OpenGLWindow : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit OpenGLWindow(QWidget *parent = nullptr);
    ~OpenGLWindow();
protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;
};

#endif // OPENGLWINDOW_H