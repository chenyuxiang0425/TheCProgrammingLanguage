//
// Created by Chen on 2020/4/13.
//


#include <stdio.h>
#define MAXLINE 8000
#define LONGLINE 80
int getLine(char s[], int lim);

int main() {
    int len;
    char line[MAXLINE];
    while((len = getLine(line,MAXLINE)) > 0) {
        if (len > LONGLINE) {
            printf("%5d: %s", len, line);
        }
    }
    return 0;
}

int getLine(char s[], int lim) {
    int c,i;
    for(i = 0; i < lim - 1 && ((c=getchar())!=EOF) && c !='\n'; i++) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
