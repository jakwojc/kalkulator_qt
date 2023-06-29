#ifndef SOMEFUNCTIONS_H
#define SOMEFUNCTIONS_H

#include "elementlist.h"

double CalculateIntegral(double start, double end, ElementList* Seq, int startIndex, int endIndex, calc_memory Mem){
    //korzystajac z metody prostokatow (prawa strona)
    if (end <= start){
        return 0;
    } else {
        int rectangleAmt = 100;
        double width = (end - start)/(rectangleAmt);
        double result = 0;
        for (int i=1;i<=rectangleAmt;i++){
            ElementList* tmpCopy = new ElementList;
            for(int j=startIndex;j<=endIndex;j++){
                if (Seq->GetPointerToIndex(j)->symbolVal == "X"){
                    if (Seq->GetPointerToIndex(j-1)->type == 1){
                        tmpCopy->Append("*");
                    }
                    tmpCopy->Append(start + i*width);
                } else if(Seq->GetPointerToIndex(j)->type == 2) {
                    tmpCopy->Append(Seq->GetPointerToIndex(j)->symbolVal);
                } else {
                    tmpCopy->Append(Seq->GetPointerToIndex(j)->numberVal);
                }
            }
            result += tmpCopy->Execute(Mem) * width;
            delete tmpCopy;
        }
        return result;
    }
}

double CalculateDerivative(double point,ElementList* Seq, calc_memory Mem){
    double h= 0.001;
    double result = 0;
    for (int i=-1;i<=1;i=i+2){
        ElementList* tmpCopy = new ElementList;
        for(int j=1;j<=Seq->GetMaxIndex();j++){
            if (Seq->GetPointerToIndex(j)->symbolVal == "X"){
                if (Seq->GetPointerToIndex(j-1)->type == 1){
                    tmpCopy->Append("*");
                }
                tmpCopy->Append(point - i * h);
            } else if(Seq->GetPointerToIndex(j)->type == 2) {
                tmpCopy->Append(Seq->GetPointerToIndex(j)->symbolVal);
            } else {
                tmpCopy->Append(Seq->GetPointerToIndex(j)->numberVal);
            }
        }
        result += -1*i*tmpCopy->Execute(Mem);
        delete tmpCopy;
    }
    return result/2/h;
}


#endif // SOMEFUNCTIONS_H
