#include "openglsample.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <QOpenGLWidget>

extern const char* vertexShaderCode;
extern const char* fragmentShaderCode;

OpenGLWindow::OpenGLWindow(QWidget *parent) : QOpenGLWidget(parent)
{

}

OpenGLWindow::~OpenGLWindow() {}

std::string readShaderCode(const char* fileName)
{
    std::ifstream meInput(fileName);
    if (!meInput.good())
    {
        std::cout << "File failed to load..." << std::endl;
        std::exit(1);
    }

    meInput >> std::noskipws;
    return std::string(
        std::istream_iterator<char>(meInput),
        std::istream_iterator<char>()
    );
}

void OpenGLWindow::initializeGL()
{
    // initializeOpenGLFunctions();
    // glClearColor(0.0f, 0.5f, 0.8f, 1.0f);\

    glewInit();
    glEnable(GL_DEPTH_TEST);
    sendDataToOpenGL();
    installShaders();
}

void OpenGLWindow::installShaders() 
{
    GLuint vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);

    const char* adapter[1];
    // adapter[0] = vertexShaderCode;
    std::string fileName = readShaderCode("../src/VertexShaderCode.glsl");
    // std::cout << fileName << std::endl;
    adapter[0] = fileName.c_str();
    glShaderSource(vertexShaderID, 1, adapter, 0);
    // adapter[0] = fragmentShaderCode;
    fileName = readShaderCode("../src/FragmentShaderCode.glsl");
    adapter[0] = fileName.c_str();
    glShaderSource(fragmentShaderID, 1, adapter, 0);

    glCompileShader(vertexShaderID);
    glCompileShader(fragmentShaderID);

    GLuint programID = glCreateProgram();
    glAttachShader(programID, vertexShaderID);
    glAttachShader(programID, fragmentShaderID);
    glLinkProgram(programID);

    glUseProgram(programID);
}

void OpenGLWindow::sendDataToOpenGL()
{
    const float RED_TRIANGLE_Z = 0.5f;
    const float BLUE_TRIANGLE_Z = -0.5f;
    GLfloat verts[] =
    {
        -1.0f, -1.0f, RED_TRIANGLE_Z,
        +1.0f, +0.0f, +0.0f,
        +0.0f, +1.0f, RED_TRIANGLE_Z,
        +1.0f, +0.0f, +0.0f,
        +1.0f, -1.0f, RED_TRIANGLE_Z,
        +1.0f, +0.0f, +0.0f,

        -1.0f, +1.0f, BLUE_TRIANGLE_Z,
        +0.0f, +0.0f, +1.0f,
        +0.0f, -1.0f, BLUE_TRIANGLE_Z,
        +0.0f, +0.0f, +1.0f,
        +1.0f, +1.0f, BLUE_TRIANGLE_Z,
        +0.0f, +0.0f, +1.0f,
    };
    GLuint vertexBufferID;
    glGenBuffers(1, &vertexBufferID);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferID);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, 0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 6, (char*)(sizeof(float) * 3));
    
    GLushort indices[] = { 0,1,2, 3,4,5,};
    GLuint indexBufferID;
    glGenBuffers(1, &indexBufferID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void OpenGLWindow::paintGL()
{
    // glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, width(), height());
    // glDrawArrays(GL_TRIANGLES, 0, 6);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_SHORT, 0);
}

void OpenGLWindow::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
}