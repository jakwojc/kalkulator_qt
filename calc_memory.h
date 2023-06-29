#ifndef CALC_MEMORY_H
#define CALC_MEMORY_H

#include <QMainWindow>

class calc_memory
{
private:
    double Ans;
    double X;
    double A;
public:
    calc_memory();
    friend class MainWindow;
    friend class ElementList;
};

#endif // CALC_MEMORY_H
