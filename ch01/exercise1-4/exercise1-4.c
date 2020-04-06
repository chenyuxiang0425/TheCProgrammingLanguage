//
// Created by Chen on 2020/4/6.
//

#include <stdio.h>

int main() {
    float celsius, fahr;
    float lower, upper, step;
    lower = -100;
    upper = 200;
    step = 20;
    celsius = lower;

    printf("print Celsius Fahrenheit table\n");
    while (celsius <= upper) {
        fahr = (9.0/5.0)*(celsius + 32.0);
        printf("%3.0f %6.1f\n",celsius,fahr);
        celsius += step;
    }

}
