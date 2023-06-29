#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "elementlist.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_NumButton1_clicked();

    void on_NumButton2_clicked();

    void on_ExecuteButtonEq_clicked();

    void on_SymbolButtonPlus_clicked();

    void on_SymbolButtonMinus_clicked();

    void on_NumButton3_clicked();

    void on_NumButton0_clicked();

    void on_SymbolButtionMulti_clicked();

    void on_SymbolButtonDiv_clicked();

    void on_SymbolButtonLP_clicked();

    void on_SymbolButtonRP_clicked();

    void on_NumButton4_clicked();

    void on_NumButton5_clicked();

    void on_NumButton6_clicked();

    void on_NumButton7_clicked();

    void on_NumButton8_clicked();

    void on_NumButton9_clicked();

    void on_ExecuteButtonAC_clicked();

    void on_SymbolButtonExp_clicked();

    void on_SymbolButtonCos_clicked();

    void on_SymbolButtonSqrt_clicked();

    void on_SymbolButtonXroot_clicked();

    void on_SymbolButtonSin_clicked();

    void on_SymbolButtonTan_clicked();

    void on_SymbolButtonCtg_clicked();

    void on_SymbolButtonDot_clicked();

    void on_numButtonAns_clicked();

    void on_numButtonX_clicked();

    void on_SymbolButtonIntegral_clicked();

    void on_SymbolButtonNatlog_clicked();

    void on_SymoblButtonLog_clicked();

    void on_NumButtonPi_clicked();

    void on_NumButtonE_clicked();

    void on_SymbolButtonFactorial_clicked();

    void on_SymbolButtonDerivative_clicked();

private:
    Ui::MainWindow *ui;
    //ElementList* DispSeq;

};
#endif // MAINWINDOW_H
