#ifndef FUNCTIONSPARTTWO_H
#define FUNCTIONSPARTTWO_H
#include <cmath>

double factorial(double number){
    number = std::abs(floor(number));
    if (number>1){
    return number * factorial(number-1);
    } else if (number>=0) {
        return 1;
    } else {
        return 0;
    }
}

#endif // FUNCTIONSPARTTWO_H
