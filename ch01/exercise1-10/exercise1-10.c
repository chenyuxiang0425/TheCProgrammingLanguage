//
// Created by Chen on 2020/4/11.
//


#include <stdio.h>
int main () {
    int c;

    while ((c=getchar()) != EOF) {
        if (c =='\t') printf("\\t");
        if (c =='\b') printf("\\b");
        if (c == '\\') printf("\\\\");
        if (c != '\t' && c != '\b' && c != '\\') putchar(c);
    }
    return 0;
}

