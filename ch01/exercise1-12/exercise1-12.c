//
// Created by Chen on 2020/4/12.
//


#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
    int c,status;
    status = OUT;
    while ((c=getchar())!=EOF) {
        if (status == IN && (c == ' ' || c == '\n' || c =='\t')) {  //end of word
            status = OUT;
            putchar('\n');
        }else if (status == OUT && (c == ' ' || c == '\n' || c =='\t')) { // skip the two blanks situation
            continue;
        } else {
            status = IN;
            putchar(c);  //inside the word
        }
    }
    return 0;
}