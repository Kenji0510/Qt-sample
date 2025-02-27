#include "subwindow.h"
#include <QFileDialog>
#include <QString>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>

SubWindow::SubWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Choose directory!");
    resize(500, 350);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);

    label = new QLabel("No directory selected.", this);
    layout->addWidget(label);

    QPushButton *selectDirButton = new QPushButton("Select Directory", this);
    layout->addWidget(selectDirButton);

    connect(selectDirButton, &QPushButton::clicked, this, &SubWindow::chooseDirectory);
}

void SubWindow::chooseDirectory()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Select dir"), "/home", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);

    if (!dir.isEmpty()) {
        label->setText(dir);
        qDebug() << "Selected direcotry: " << dir;
    }
}