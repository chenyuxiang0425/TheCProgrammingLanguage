//
// Created by Chen on 2020/4/7.
//
#include <stdio.h>
int main() {
    int c, blanks,tabs,newlines;
    int lastchar;
    lastchar = 0;
    blanks = 0;
    tabs = 0;
    newlines = 0;
    while ((c=getchar())!= EOF) {
        if (c==' ') {
            blanks ++;
        }
        if (c == '\t') {
            tabs ++;
        }
        if (c == '\n') {
            newlines ++;
        }
        lastchar = c;
    }
    if (lastchar != '\n') newlines +=1;
    printf("Blanks:%d\nTabs:%d\nNewLines:%d\n",blanks,tabs,newlines);
    return 0;
}