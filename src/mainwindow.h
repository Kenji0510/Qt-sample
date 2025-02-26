#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QLabel;

class MainWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void incrementCounter();

private:
    QLabel *label;
    int counter = 0;
};

#endif // MAINWINDOW_H