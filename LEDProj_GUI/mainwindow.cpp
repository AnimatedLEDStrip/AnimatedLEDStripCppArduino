#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_3_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_3->setText(getColorHex(arg1));
}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_2->setText(getColorHex(arg1));
}
