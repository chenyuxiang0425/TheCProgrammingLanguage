//
// Created by Chen on 2020/4/13.
//

/*
 * Exercise 1-20
 * Write a program detab that replaces tabs in the input
 * with the proper number of blanks to space to the next tab stop.
 * Assume a fixed set of tab stops, say every n columns.
 * Should n be a variable or a symbolic parameter?
 */

#include <stdio.h>
#define TABINC 8

int main() {
    int c;
    int pos;
    int nb; //number of blanks
    pos = 0;
    while((c=getchar()) != EOF) {
        if (c == '\t') {
            nb = TABINC - pos % TABINC;
            for (int i = 0; i < nb; i++) {
                pos ++;
                putchar(' ');
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 0;
        } else {
            putchar(c);
            pos ++;
        }
    }
    return 0;
}

