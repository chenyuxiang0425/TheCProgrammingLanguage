//
// Created by Chen on 2020/4/13.
//


#include <stdio.h>

float changeTemp(float fahr);

int main() {
    float fahr;
    float lower, upper, step;
    lower = 0;
    upper = 300;
    step = 20;
    fahr = lower;

    printf("print Fahrenheit Celsius table\n");
    while (fahr <= upper) {
        printf("%3.0f\t%6.1f\n",fahr,changeTemp(fahr));
        fahr += step;
    }

}

float changeTemp(float fahr) {
    int celsius = (5.0/9.0) *(fahr - 32.0);
    return celsius;
}