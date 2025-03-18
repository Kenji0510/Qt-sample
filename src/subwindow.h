#ifndef SUBWINDOW_H
#define SUBWINDOW_H

#include <QWidget>

class QLabel;

class SubWindow : public QWidget
{
    Q_OBJECT
public: 
    explicit SubWindow(QWidget *parent = nullptr);

private:
    void chooseDirectory();
private:
    QLabel *label;
};

#endif // SUBWINDOW_H