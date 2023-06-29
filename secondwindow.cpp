#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
}

SecondWindow::~SecondWindow()
{
    delete ui;
}



void SecondWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    FirstValue = arg1;
}


void SecondWindow::on_doubleSpinBox_2_valueChanged(double arg1)
{
    SecondValue = arg1;
}

