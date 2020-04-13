//
// Created by Chen on 2020/4/13.
//
/*
 * Exercise 1-21
 * Write a program entab that replaces strings of blanks
 * by the minimum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference?
 */


#include <stdio.h>
#define TABINC 8
void putTab(int nt);
void putBlank(int nb);
void putChar(int nt,int nb, int c);
/* replace strings of blanks with tabs and blanks */
int main() {
    int c, nb, nt, pos;
    nb = 0; /* # of blanks necessary */
    nt = 0; /* # of tabs necessary */

    for (pos = 1; (c = getchar()) != EOF; ++pos) {
        if (c == ' ') {
            if ((pos) % TABINC != 0) {
                nb++;
            } else {
                nb = 0; /* reset # of blanks */
                ++nt; /* one more tab */
            }
        } else if (c =='\t') {
            nb = 0; //only need to print \t

            putChar(nt,nb,c);
            nt = 0;

            pos = pos + (TABINC - (pos - 1) % TABINC) - 1;//制表符终结位规则
        } else if (c == '\n') {
            putChar(nt,nb,c);
            nt = 0;
            nb = 0;

            pos = 0;
        } else { // c is a normal char
            putChar(nt,nb,c);
            nt = 0;
            nb = 0;
        }
    }
    return 0;
}

void putTab(int nt) {
    for (; nt > 0; --nt) {
        putchar('\t'); /* output tab(s) */
    }
}

void putBlank(int nb) {
    for (; nb > 0; --nb)
        putchar(' ');
}/* output blank(s) */

void putChar(int nt,int nb, int c) {
    putTab(nt);
    putBlank(nb);
    putchar(c);
}