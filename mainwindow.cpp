#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "calc_memory.h"
#include "elementlist.h"
#include <iostream>
#include "SomeFunctions.h"
#include "secondwindow.h"
#include "ui_secondwindow.h"

ElementList* DispSeq = new ElementList;
calc_memory Memory;
bool IntButtonPressed = false;
double IntStart = 0;
double IntEnd = 0;
bool DerButtonPressed = false;
double DerivativePoint = 0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_NumButton1_clicked()
{
    DispSeq->Append(1);
    ui->Display->setText(ui->Display->text()+"1");
}


void MainWindow::on_NumButton2_clicked()
{
    DispSeq->Append(2);
    ui->Display->setText(ui->Display->text()+"2");

}

void MainWindow::on_NumButton3_clicked()
{
    DispSeq->Append(3);
    ui->Display->setText(ui->Display->text()+"3");
}

void MainWindow::on_NumButton0_clicked()
{
    DispSeq->Append(0);
    ui->Display->setText(ui->Display->text()+"0");
}


void MainWindow::on_ExecuteButtonEq_clicked()
{
    double solution;
    //DispSeq->JussCheckin();
    if (IntButtonPressed){
        solution = CalculateIntegral(IntStart,IntEnd,DispSeq,1,DispSeq->GetMaxIndex(),Memory);
    } else if (DerButtonPressed){
        solution = CalculateDerivative(DerivativePoint,DispSeq,Memory);
    } else {
        solution = DispSeq->Execute(Memory);
    }
    Memory.Ans = solution;
    //QString saveExpression = ui->Display->text();
    //ui->Display->clear();
    //ui->Display->setText(saveExpression + "=" + QString::number(solution));
    ui->DisplayEq->setText("=" + QString::number(solution));
    std::cout << std::endl;
    //std::cout << "integral result: " << CalculateIntegral(IntStart,IntEnd,DispSeq,1,DispSeq->GetMaxIndex(),Memory) << std::endl;
}


void MainWindow::on_SymbolButtonPlus_clicked()
{
    DispSeq->Append("+");
    ui->Display->setText(ui->Display->text()+"+");
}


void MainWindow::on_SymbolButtonMinus_clicked()
{
    DispSeq->Append("-");
    ui->Display->setText(ui->Display->text()+"-");
}


void MainWindow::on_SymbolButtionMulti_clicked()
{
    DispSeq->Append("*");
    ui->Display->setText(ui->Display->text()+"*");
}


void MainWindow::on_SymbolButtonDiv_clicked()
{
    DispSeq->Append("/");
    ui->Display->setText(ui->Display->text()+"/");
}


void MainWindow::on_SymbolButtonLP_clicked()
{
    DispSeq->Append("(");
    ui->Display->setText(ui->Display->text()+"(");
}


void MainWindow::on_SymbolButtonRP_clicked()
{
    DispSeq->Append(")");
    ui->Display->setText(ui->Display->text()+")");
}


void MainWindow::on_NumButton4_clicked()
{
    DispSeq->Append(4);
    ui->Display->setText(ui->Display->text()+"4");
}


void MainWindow::on_NumButton5_clicked()
{
    DispSeq->Append(5);
    ui->Display->setText(ui->Display->text()+"5");
}


void MainWindow::on_NumButton6_clicked()
{
    DispSeq->Append(6);
    ui->Display->setText(ui->Display->text()+"6");
}


void MainWindow::on_NumButton7_clicked()
{
    DispSeq->Append(7);
    ui->Display->setText(ui->Display->text()+"7");
}


void MainWindow::on_NumButton8_clicked()
{
    DispSeq->Append(8);
    ui->Display->setText(ui->Display->text()+"8");
}


void MainWindow::on_NumButton9_clicked()
{
    DispSeq->Append(9);
    ui->Display->setText(ui->Display->text()+"9");
}


void MainWindow::on_ExecuteButtonAC_clicked()
{
    DispSeq->next = nullptr; //memory leak prolly
    ui->Display->setText("");
    ui->DisplayEq->setText("");
}


void MainWindow::on_SymbolButtonExp_clicked()
{
    DispSeq->Append("^");
    ui->Display->setText(ui->Display->text()+"^");
}


void MainWindow::on_SymbolButtonCos_clicked()
{
    DispSeq->Append("cos");
    ui->Display->setText(ui->Display->text()+"cos");
}


void MainWindow::on_SymbolButtonSqrt_clicked()
{
    uint32_t val = 0x221A;  //Roots
    QString symbolText  = QChar(val);

    DispSeq->Append("sqrt");
    ui->Display->setText(ui->Display->text()+symbolText);
}


void MainWindow::on_SymbolButtonXroot_clicked()
{
    DispSeq->Append("xroot");

    ui->Display->setText(ui->Display->text()+"xroot");
}


void MainWindow::on_SymbolButtonSin_clicked()
{
    DispSeq->Append("sin");
    ui->Display->setText(ui->Display->text()+"sin");
}





void MainWindow::on_SymbolButtonTan_clicked()
{
    DispSeq->Append("tan");
    ui->Display->setText(ui->Display->text()+"tan");
}



void MainWindow::on_SymbolButtonCtg_clicked()
{
    DispSeq->Append("ctg");
    ui->Display->setText(ui->Display->text()+"ctg");
}

void MainWindow::on_SymbolButtonDot_clicked()
{
    DispSeq->Append(".");
    ui->Display->setText(ui->Display->text()+".");
}


void MainWindow::on_numButtonAns_clicked()
{
    DispSeq->Append("Ans");
    ui->Display->setText(ui->Display->text()+"Ans");
}


void MainWindow::on_numButtonX_clicked()
{
    DispSeq->Append("X");
    ui->Display->setText(ui->Display->text()+"X");
}

void MainWindow::on_SymbolButtonIntegral_clicked()
{
    SecondWindow OtherWindow;
    OtherWindow.setModal(true);
    OtherWindow.ui->LeftText->setText("start");
    OtherWindow.ui->RightText->setText("end");
    switch (IntButtonPressed){
    case false:
        IntButtonPressed = true;
        DerButtonPressed = false;
        OtherWindow.exec();
        IntStart = OtherWindow.FirstValue;
        IntEnd = OtherWindow.SecondValue;
        ui->ExecuteButtonEq->setText("calculate int (" + QString::number(IntStart)+"to"+QString::number(IntEnd)+")");
        break;
    case true:
        IntButtonPressed = false;
        ui->ExecuteButtonEq->setText("=");
        break;
    }
}

void MainWindow::on_SymbolButtonDerivative_clicked()
{
    SecondWindow OtherWindow;
    OtherWindow.setModal(true);
    OtherWindow.ui->LeftText->setText("At point:");
    OtherWindow.ui->RightText->hide();
    OtherWindow.ui->doubleSpinBox_2->hide();
    switch (DerButtonPressed){
    case false:
        DerButtonPressed = true;
        IntButtonPressed = false;
        OtherWindow.exec();
        DerivativePoint = OtherWindow.FirstValue;
        ui->ExecuteButtonEq->setText("calculate d/dX (at" + QString::number(DerivativePoint)+")");
        break;
    case true:
        DerButtonPressed = false;
        ui->ExecuteButtonEq->setText("=");
        break;
    }
}


void MainWindow::on_SymbolButtonNatlog_clicked()
{
    DispSeq->Append("ln");
    ui->Display->setText(ui->Display->text()+"ln");
}


void MainWindow::on_SymoblButtonLog_clicked()
{
    DispSeq->Append("log");
    ui->Display->setText(ui->Display->text()+"log");
}


void MainWindow::on_NumButtonPi_clicked()
{
    DispSeq->Append("pi");
    uint32_t val = 0x03C0;  //pi
    QString symbolText  = QChar(val);
    ui->Display->setText(ui->Display->text()+symbolText);
}


void MainWindow::on_NumButtonE_clicked()
{
    DispSeq->Append("e");
    ui->Display->setText(ui->Display->text()+"e");
}


void MainWindow::on_SymbolButtonFactorial_clicked()
{
    DispSeq->Append("!");
    ui->Display->setText(ui->Display->text()+"!");
}




