//
// Created by Chen on 2020/4/7.
//

#include <stdio.h>
int main() {
    int c;
    int lastchar;
    lastchar = -1;
    while ((c=getchar()) != EOF) {
        if (c != ' ' || lastchar != ' ') {
            putchar(c);
        }
        lastchar = c;
    }
    return 0;
}