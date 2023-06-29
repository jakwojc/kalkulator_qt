#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();

private slots:
    void on_doubleSpinBox_valueChanged(double arg1);

    void on_doubleSpinBox_2_valueChanged(double arg1);

private:
    Ui::SecondWindow *ui;
    double FirstValue = 0;
    double SecondValue = 0;

    friend class MainWindow;
};

#endif // SECONDWINDOW_H
