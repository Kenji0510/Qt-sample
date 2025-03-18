#include "openglsample.h"
#include <QApplication>
#include <QOpenGLWidget>

OpenGLWindow::OpenGLWindow(QWidget *parent) : QOpenGLWidget(parent)
{

}

OpenGLWindow::~OpenGLWindow() {}

void OpenGLWindow::initializeGL()
{
    // initializeOpenGLFunctions();
    // glClearColor(0.0f, 0.5f, 0.8f, 1.0f);\

    glewInit();

    GLfloat verts[] =
    {
        +0.0f, +0.0f,
        +1.0f, +1.0f,
        -1.0f, +1.0f,

        +0.0f, +0.0f,
        -1.0f, -1.0f,
        +1.0f, -1.0f,
    };
    GLuint myBufferID;
    glGenBuffers(1, &myBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, myBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, 0);

}

void OpenGLWindow::paintGL()
{
    // glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, width(), height());
    glDrawArrays(GL_TRIANGLES, 0, 6);
}

void OpenGLWindow::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}