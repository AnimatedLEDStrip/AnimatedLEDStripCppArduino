#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_serial(new QSerialPort(this));
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

void MainWindow::on_comboBox_4_currentIndexChanged(const QString &arg1)
{
    ui->lineEdit_8->setText(getColorHex(arg1));
}

void MainWindow::on_pushButton_2_clicked()
{

    str.clear();
    str.append("A ALT ");
    str.append(ui->lineEdit_2->text());
    str.append(" ");
    str.append(ui->lineEdit_3->text());
    str.append(" ");
    str.append(ui->lineEdit_4->text());
    str.append('\r');

}

void MainWindow::on_pushButton_3_clicked()
{
    str.clear();
    str.append("A FDP RED ");
    str.append(" ");
    str.append(ui->lineEdit_5->text());
    str.append(" ");
    str.append(ui->verticalSlider->value());
    str.append(" ");
    str.append(ui->verticalSlider_2->value());
    str.append(' ');
    bool checked = ui->checkBox_4->isChecked();
    if (checked)
        str.append("R");
    else if (!checked)
        str.append("N");
    str.append('\r');

}

void MainWindow::on_pushButton_4_clicked()
{
    str.clear();
    str.append("A FDP GRN ");
    str.append(" ");
    str.append(ui->lineEdit_7->text());
    str.append(' ');
    bool checked = ui->checkBox_3->isChecked();
    if (checked)
        str.append("R");
    else if (!checked)
        str.append("N");
    str.append(" ");
    str.append(ui->verticalSlider_3->value());
    str.append(" ");
    str.append(ui->verticalSlider_4->value());
    str.append('\r');
}

void MainWindow::on_pushButton_5_clicked()
{
    str.clear();
    str.append("A FDP BLU ");
    str.append(" ");
    str.append(ui->lineEdit_9->text());
    str.append(' ');
    str.append(ui->checkBox_2->text());
    str.append(" ");
    str.append(ui->verticalSlider_5->text());
    str.append(" ");
    str.append(ui->verticalSlider_6->text());
    str.append('\r');

}

void MainWindow::on_pushButton_6_clicked()
{
    str.clear();
    str.append("A FDP ALL ");
    str.append(" ");
    str.append(ui->lineEdit_11->text());
    str.append(" ");
    str.append(ui->checkBox->text());
    str.append(" ");
    str.append(ui->verticalSlider_7->text());
    str.append(" ");
    str.append(ui->verticalSlider_8->text());
    str.append('\r');

}

void MainWindow::on_pushButton_7_clicked()
{
    str.clear();
    str.append("A MPR ");
    str.append(" ");
    str.append(ui->lineEdit_6->text());
    str.append(" ");
    str.append(ui->lineEdit_8->text());
    str.append(" ");
    str.append(ui->lineEdit_10->text());
    str.append(" ");
    str.append(ui->radioButton->text());
    str.append(" ");
    str.append(ui->radioButton_2->text());
    str.append('\r');
}

void MainWindow::on_pushButton_12_clicked()
{

    str.clear();
    str.append("A PXR ");
    str.append(" ");
    str.append(ui->lineEdit_12->text());
    str.append(" ");
    str.append(ui->lineEdit_13->text());
    str.append(" ");
    str.append(ui->lineEdit_14->text());
    str.append(" ");
    str.append(ui->radioButton_3->text());
    str.append(" ");
    str.append(ui->radioButton_4->text());
    str.append('\r');

}

void MainWindow::on_pushButton_8_clicked()
{
    str.clear();
    str.append("A PXR ");
    str.append(" ");
    str.append(ui->lineEdit_15->text());
    str.append(" ");
    str.append(ui->lineEdit_16->text());
    str.append(" ");
    str.append(ui->lineEdit_17->text());
    str.append(" ");
    str.append(ui->radioButton_5->text());
    str.append(" ");
    str.append(ui->radioButton_6->text());
    str.append('\r');
}

void MainWindow::on_pushButton_9_clicked()
{
    str.clear();
    str.append("A SCH ");
    str.append(" ");
    str.append(ui->lineEdit_38->text());
    str.append(" ");
    str.append(ui->radioButton_10->text());
    str.append(" ");
    str.append(ui->radioButton_9->text());
    str.append(" ");
    str.append(ui->checkBox_5->text());
    str.append('\r');
}

void MainWindow::on_pushButton_10_clicked()
{
    str.clear();
    str.append("A STC ");
    str.append(" ");
    str.append(ui->lineEdit_19->text());
    str.append('\r');

}

void MainWindow::on_pushButton_11_clicked()
{
    str.clear();
    str.append("A WIP ");
    str.append(" ");
    str.append(ui->radioButton_7->text());
    str.append(" ");
    str.append(ui->radioButton_8->text());
    str.append('\r');

}
