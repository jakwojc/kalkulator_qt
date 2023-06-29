#ifndef ELEMENTLIST_H
#define ELEMENTLIST_H

#include "calc_memory.h"
#include <QMainWindow>

class ElementList {
private:
    int type=0;
    double numberVal=0;
    QString symbolVal="";
    ElementList* next;
    int index=0;
    friend class MainWindow;
    friend double CalculateIntegral(double start, double end, ElementList* Seq, int startIndex, int endIndex, calc_memory Mem);
    friend double CalculateDerivative(double point,ElementList* Seq, calc_memory Memory);
    friend double factorial(double number);
public:
    ElementList();
    ElementList(double numInput);
    ElementList(QString txtInput);
    ElementList* GetNext();
    void Append(double numInput);
    void Append(QString txtInput);
    void JussCheckin();
    double Execute();
    double Execute(calc_memory Memory); //zrobic rekurencyjnosc tutaj
    ElementList* GetPointerToIndex(int i);
    int GetType();
    int GetMaxIndex();
    int GetNumberAmount();

};

#endif // ELEMENTLIST_H
