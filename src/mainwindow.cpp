#include "mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Qt sample!");
    resize(500, 400);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    label = new QLabel("Counter: 0", this);
    layout->addWidget(label);

    QPushButton *button = new QPushButton("Click me!", this);
    layout->addWidget(button);

    connect(button, &QPushButton::clicked, this, &MainWindow::incrementCounter);

    QPushButton *closeButton = new QPushButton("Close", this);
    layout->addWidget(closeButton);

    connect(closeButton, &QPushButton::clicked, this, &QWidget::close);

    QLabel *imageLabel = new QLabel(this);
    QPixmap image("/home/kenji/workspace/Cpp/Qt/qt_sample01/data/images/sample.png");
    imageLabel->setPixmap(image);
    layout->addWidget(imageLabel);
}

void MainWindow::incrementCounter()
{
    counter++;
    label->setText(QString("Counter!: %1").arg(counter));
}