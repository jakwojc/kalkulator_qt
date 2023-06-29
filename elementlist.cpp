#include "FunctionsPartTwo.h"
#define _USE_MATH_DEFINES
#include "elementlist.h"
#include <QApplication>
#include <iostream>
#include <math.h>
#include <cmath>

ElementList::ElementList(){
    next = nullptr;
    index = 0;
}

ElementList::ElementList(double numInput) : numberVal(numInput) {
    next = nullptr;
    type = 1;
    index = 0;
}

ElementList::ElementList(QString txtInput) : symbolVal(txtInput) {
    type = 2;
    next = nullptr;
    index = 0;
}

void ElementList::Append(double numInput){
    ElementList* tmpCopy = this;
    int tmpIndex = 1;
    while (tmpCopy->next != nullptr) { //autobus do ostatniego elementu
        tmpCopy=tmpCopy->next;
        tmpIndex++;
    }
    if (tmpCopy->type == 1) {
        tmpCopy->symbolVal = QString::number(tmpCopy->numberVal) + QString::number(numInput);
        tmpCopy->numberVal = tmpCopy->symbolVal.toDouble();
    } else {
        ElementList* New = new ElementList;
        New->index = tmpIndex;
        New->numberVal=numInput;
        New->type=1;
        tmpCopy->next = New;
    }
}

void ElementList::Append(QString txtInput){
    ElementList* tmpCopy = this;
    int tmpIndex = 1;
    while (tmpCopy->next != nullptr) { //autobus do ostatniego elementu
        tmpCopy=tmpCopy->next;
        tmpIndex++;
    }

    ElementList* New = new ElementList;
    New->index = tmpIndex;
    New->symbolVal=txtInput;
    if (txtInput == "pi"){
        New->numberVal = 3.14159265359;
    }
    if (txtInput == "e"){
        New->numberVal = 2.71828182846;
    }
    New->type=2;
    tmpCopy->next = New;
}

void ElementList::JussCheckin(){
   
    ElementList* tmpCopy = this;
    char cont = 't';
    while (cont == 't') { //autobus do ostatniego elementu
        cont = 'n';
        std::cout << tmpCopy->index << " ";
        switch (tmpCopy->type){
        case 1:
            std::cout << tmpCopy->numberVal << "\n";
            break;
        case 2:
            std::cout << tmpCopy->symbolVal.toStdString() << "\n";
            break;
        default:
            std::cout << "sumin wong\n";
        }
        if (tmpCopy->next!=nullptr){
            tmpCopy=tmpCopy->next;
            cont = 't';
        }
    }
}

ElementList* ElementList::GetPointerToIndex(int i){
    ElementList* tmpCopy = this;
    while (tmpCopy->index != i){
        tmpCopy = tmpCopy->next;
    }
    return tmpCopy;

}

int ElementList::GetMaxIndex(){
    ElementList* tmpCopy = this;
    while (tmpCopy->next != nullptr){
        tmpCopy = tmpCopy->next;
    }
    return tmpCopy->index;
}

int ElementList::GetNumberAmount(){
    int counter=0;
    ElementList* tmpCopy = this;
    while (tmpCopy->next != nullptr){
        tmpCopy = tmpCopy->next;
        if (tmpCopy->type == 1){
            counter++;
        }
    }
    return counter;
}

int ElementList::GetType(){
    return this->type;
}

double ElementList::Execute(){
    std::cout << "cos jeszcze" << std::endl;
    return 0;
}

double ElementList::Execute(calc_memory Memory){
    /* int i = 0, j = 0;
    ElementList* tmpCopy = this;
    int ExpressionLength = tmpCopy->GetMaxIndex();
    int NumberAmount = tmpCopy->GetNumberAmount();
    double* Numbers = new double[NumberAmount];
    QString* Symbols = new QString[ExpressionLength-NumberAmount];
    for (i = 0;i<NumberAmount;i++){
        Numbers[i] = tmpCopy->GetPointerToIndex(1+i*2)->numberVal;
    }
    for (i = 0;i<ExpressionLength-NumberAmount;i++){
        Symbols[i] = tmpCopy->GetPointerToIndex((2+i*2))->symbolVal;
    }
    int result = 0;
    for (i = 0;i<ExpressionLength-NumberAmount;i++){
        if (i==0){
            if (Symbols[0] == "+"){
                result = Numbers[0] + Numbers[1];
            } else if (Symbols[0] == "-"){
                result = Numbers[0] - Numbers[1];
            }
        } else {
            if (Symbols[i] == "+"){
                result += Numbers[i + 1];
            } else if (Symbols[i] == "-"){
                result -= Numbers[i + 1];
            }
        }
    }
    delete []Numbers;
    delete []Symbols;
    return result;*/




    //proba z rekurencyjnoscia
    ElementList* tmpCopy = this;
    tmpCopy->JussCheckin();
    double result = 69;
    int ExpressionLength = tmpCopy->GetMaxIndex();
    //tu te rzeczy co sie zapisuja w pamieci
    //Ans
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "Ans"){
            ElementList* tmpNewCopy = new ElementList;
            if (tmpCopy->GetPointerToIndex(i-1)->type == 1){
                for(int j=1;j<=ExpressionLength-1;j++){
                    if (j<i-1){
                        if (tmpCopy->GetPointerToIndex(j)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                        }
                    } else if(j == i - 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(i-1)->numberVal * Memory.Ans);
                    } else { //uwaga na nullptr na koncu
                        if (tmpCopy->GetPointerToIndex(j+1)!=nullptr){
                            if (tmpCopy->GetPointerToIndex(j+1)->type == 1){
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->numberVal);
                            } else {
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->symbolVal);
                            }
                        }
                    }
                }
            } else {
                for(int j=1;j<=ExpressionLength;j++){
                    if(j == i){
                        tmpNewCopy->Append(Memory.Ans);
                    } else {
                        if (tmpCopy->GetPointerToIndex(j)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }
    //stale
    //pi
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "pi"){
            ElementList* tmpNewCopy = new ElementList;
            if (tmpCopy->GetPointerToIndex(i-1)->type == 1 || (tmpCopy->GetPointerToIndex(i-1)->type == 2 && tmpCopy->GetPointerToIndex(i-1)->numberVal != 0)){
                for(int j=1;j<=ExpressionLength-1;j++){
                    if (j<i-1){
                        if (tmpCopy->GetPointerToIndex(j)->type == 1 ){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                        }
                    } else if(j == i - 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(i-1)->numberVal * 3.14159265359);
                    } else { //uwaga na nullptr na koncu
                        if (tmpCopy->GetPointerToIndex(j+1)!=nullptr){
                            if (tmpCopy->GetPointerToIndex(j+1)->type == 1){
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->numberVal);
                            } else {
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->symbolVal);
                            }
                        }
                    }
                }
            } else {
                for(int j=1;j<=ExpressionLength;j++){
                    if(j == i){
                        tmpNewCopy->Append(3.14159265359);
                    } else {
                        if (tmpCopy->GetPointerToIndex(j)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }
    //e
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "e"){
            ElementList* tmpNewCopy = new ElementList;
            if (tmpCopy->GetPointerToIndex(i-1)->type == 1 || (tmpCopy->GetPointerToIndex(i-1)->type == 2 && tmpCopy->GetPointerToIndex(i-1)->numberVal != 0)){
                for(int j=1;j<=ExpressionLength-1;j++){
                    if (j<i-1){
                        if (tmpCopy->GetPointerToIndex(j)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                        }
                    } else if(j == i - 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(i-1)->numberVal * 2.71828182846);
                    } else { //uwaga na nullptr na koncu
                        if (tmpCopy->GetPointerToIndex(j+1)!=nullptr){
                            if (tmpCopy->GetPointerToIndex(j+1)->type == 1){
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->numberVal);
                            } else {
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->symbolVal);
                            }
                        }
                    }
                }
            } else {
                for(int j=1;j<=ExpressionLength;j++){
                    if(j == i){
                        tmpNewCopy->Append(2.71828182846);
                    } else {
                        if (tmpCopy->GetPointerToIndex(j)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }

    //tu sie konczy wszystko
    if (tmpCopy->GetMaxIndex() == 1){
        return tmpCopy->GetPointerToIndex(1)->numberVal;
    }
    //kropka do ulamkow dziesietnych
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "."){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-2;j++){
                if (j<i-1){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i-1){
                    tmpNewCopy->Append(tmpCopy->GetPointerToIndex(i-1)->numberVal+tmpCopy->GetPointerToIndex(i+1)->numberVal/pow(10,1+floor(log10(tmpCopy->GetPointerToIndex(i+1)->numberVal))));
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+2)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+2)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+2)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+2)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }


    //PEMDAS more like SPEMDA ?
    //S
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "-"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            if (tmpCopy->GetPointerToIndex(i-1)->type == 1){
                for(int j=1;j<=ExpressionLength;j++){
                    if (j<i){
                        if (tmpCopy->GetPointerToIndex(j)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                        }
                    } else if(j == i){
                        tmpNewCopy->Append("+");
                    } else if(j == i+1){
                        tmpNewCopy->Append(-1 * tmpCopy->GetPointerToIndex(i+1)->numberVal); //dzielenie przez zero
                    } else { //uwaga na nullptr na koncu
                        if (tmpCopy->GetPointerToIndex(j)!=nullptr){
                            if (tmpCopy->GetPointerToIndex(j)->type == 1){
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                            } else {
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                            }
                        }
                    }
                }
            } else {
                for(int j=1;j<=ExpressionLength-1;j++){
                    if (j<i){
                        if (tmpCopy->GetPointerToIndex(j)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                        }
                    } else if(j == i){
                        tmpNewCopy->Append(-1 * tmpCopy->GetPointerToIndex(j+1)->numberVal);
                    } else { //uwaga na nullptr na koncu
                        if (tmpCopy->GetPointerToIndex(j+1)!=nullptr){
                            if (tmpCopy->GetPointerToIndex(j+1)->type == 1){
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->numberVal);
                            } else {
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->symbolVal);
                            }
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }
    //P
    for(int i = 1;i<=ExpressionLength;i++){

        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "("){

            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            ElementList* tmpNewCopy2 = new ElementList;
            int closeCheck = 1;
            for(int j=i+1;j<=ExpressionLength;j++){
                if(tmpCopy->GetPointerToIndex(j)->symbolVal == "("){
                    closeCheck++;
                } else if(tmpCopy->GetPointerToIndex(j)->symbolVal == ")"){
                    closeCheck--;
                }
                //std::cout << "check="<<closeCheck << std::endl;
                if(closeCheck == 0){

                    for(int k=1;k<=ExpressionLength-2;k++){
                        //std::cout << "i="<<i<<" j="<<j<<" k=" << k <<std::endl;
                        if (k<i){
                            if (tmpCopy->GetPointerToIndex(k)->type == 1){
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(k)->numberVal);
                            } else {
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(k)->symbolVal);
                            }
                        } else if (k>=i && k<j-2){
                            //tmpCopy->JussCheckin();

                            if (tmpCopy->GetPointerToIndex(k+1)->type == 1){
                                tmpNewCopy2->Append(tmpCopy->GetPointerToIndex(k+1)->numberVal);
                                //std::cout << tmpCopy->GetPointerToIndex(k+1)->numberVal << std::endl;
                            } else {
                                tmpNewCopy2->Append(tmpCopy->GetPointerToIndex(k+1)->symbolVal);
                            }
                        } else if (k==j-2){

                            if (tmpCopy->GetPointerToIndex(k+1)->type == 1){
                                tmpNewCopy2->Append(tmpCopy->GetPointerToIndex(k+1)->numberVal);
                            } else {
                                tmpNewCopy2->Append(tmpCopy->GetPointerToIndex(k+1)->symbolVal);
                            }
                            //std::cout << "ok so we here" << std::endl;

                            tmpNewCopy->Append(tmpNewCopy2->Execute(Memory));
                        } else {
                            if (tmpCopy->GetPointerToIndex(k+2)->type == 1){
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(k+2)->numberVal);
                            } else {
                                tmpNewCopy->Append(tmpCopy->GetPointerToIndex(k+2)->symbolVal);
                            }
                        }
                    }
                    delete tmpNewCopy2;
                    return tmpNewCopy->Execute(Memory);
                }
            }
        }
    }
    //funkcje
    //cosinus
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "cos"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-1;j++){
                if (j<i){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i){
                    tmpNewCopy->Append(cos(tmpCopy->GetPointerToIndex(j+1)->numberVal / 180 * M_PI));
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+1)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+1)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }
    //sinus
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "sin"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-1;j++){
                if (j<i){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i){
                    tmpNewCopy->Append(sin(tmpCopy->GetPointerToIndex(j+1)->numberVal / 180 * M_PI));
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+1)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+1)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }
    //tangens
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "tan"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-1;j++){
                if (j<i){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i){
                    tmpNewCopy->Append(tan(tmpCopy->GetPointerToIndex(j+1)->numberVal / 180 * M_PI));
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+1)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+1)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }
    //contangens
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "ctg"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-1;j++){
                if (j<i){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i){
                    tmpNewCopy->Append(cos(tmpCopy->GetPointerToIndex(j+1)->numberVal / 180 * M_PI)/sin(tmpCopy->GetPointerToIndex(j+1)->numberVal / 180 * M_PI));
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+1)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+1)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }
    //cos^-1
    //sin^-1
    //tan^-1
    //ctg^-1
    //sqare root
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "sqrt"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-1;j++){
                if (j<i){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i){
                    tmpNewCopy->Append(sqrt(tmpCopy->GetPointerToIndex(j+1)->numberVal));
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+1)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+1)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }
    //xroot
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "xroot"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-2;j++){
                if (j<i-1){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i-1){
                    tmpNewCopy->Append(pow(tmpCopy->GetPointerToIndex(i+1)->numberVal,1/tmpCopy->GetPointerToIndex(i-1)->numberVal));
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+2)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+2)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+2)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+2)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }
    //log
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "log"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-1;j++){
                if (j<i){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i){
                    tmpNewCopy->Append(log(tmpCopy->GetPointerToIndex(j+1)->numberVal)/log(10));
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+1)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+1)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }
    //ln
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "ln"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-1;j++){
                if (j<i){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i){
                    tmpNewCopy->Append(log(tmpCopy->GetPointerToIndex(j+1)->numberVal));
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+1)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+1)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }
    //silnia
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "!"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-1;j++){
                if (j<i-1){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i-1){
                    tmpNewCopy->Append(factorial(tmpCopy->GetPointerToIndex(i-1)->numberVal));
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+1)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+1)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+1)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }

    //E
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "^"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-2;j++){
                if (j<i-1){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i-1){
                    tmpNewCopy->Append(pow(tmpCopy->GetPointerToIndex(i-1)->numberVal,tmpCopy->GetPointerToIndex(i+1)->numberVal));
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+2)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+2)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+2)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+2)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }

    //M
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "*"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-2;j++){
                if (j<i-1){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i-1){
                    tmpNewCopy->Append(tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i+1)->numberVal);
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+2)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+2)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+2)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+2)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }
    //D
    for(int i = 1;i<=ExpressionLength;i++){
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "/"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-2;j++){
                if (j<i-1){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i-1){
                    tmpNewCopy->Append(tmpCopy->GetPointerToIndex(i-1)->numberVal / tmpCopy->GetPointerToIndex(i+1)->numberVal); //dzielenie przez zero
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+2)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+2)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+2)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+2)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }

    //A
    for(int i = 1;i<=ExpressionLength;i++){
        //std::cout << tmpCopy->GetPointerToIndex(i)->symbolVal.toStdString() << std::endl;
        if(tmpCopy->GetPointerToIndex(i)->symbolVal == "+"){
            //double tmpSubstitute = tmpCopy->GetPointerToIndex(i-1)->numberVal * tmpCopy->GetPointerToIndex(i-1)->numberVal;
            //std::cout << "tu bylo" << std::endl;
            ElementList* tmpNewCopy = new ElementList;
            for(int j=1;j<=ExpressionLength-2;j++){
                //std::cout << "i="<<i<<" j="<<j<<std::endl;
                if (j<i-1){
                    if (tmpCopy->GetPointerToIndex(j)->type == 1){
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->numberVal);
                    } else {
                        tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j)->symbolVal);
                    }
                } else if(j == i-1){

                    tmpNewCopy->Append(tmpCopy->GetPointerToIndex(i-1)->numberVal + tmpCopy->GetPointerToIndex(i+1)->numberVal); //dzielenie przez zero
                } else { //uwaga na nullptr na koncu
                    if (tmpCopy->GetPointerToIndex(j+2)!=nullptr){
                        if (tmpCopy->GetPointerToIndex(j+2)->type == 1){
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+2)->numberVal);
                        } else {
                            tmpNewCopy->Append(tmpCopy->GetPointerToIndex(j+2)->symbolVal);
                        }
                    }
                }
            }
            result = tmpNewCopy->Execute(Memory);
            return result;
            break;
        }
    }

    return result;
}
