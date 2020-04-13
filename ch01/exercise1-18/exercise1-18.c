//
// Created by Chen on 2020/4/13.
//


#include <stdio.h>
#define MAXLINE 8000
#define LONGLINE 80
int getLine(char s[], int lim);
int removeInterval(char s[]);

int main() {
    char line[MAXLINE];
    while ((getLine(line, MAXLINE) > 0)) {
        if (removeInterval(line) > 0) {
            printf("%s",line);
        }
    }
}

int getLine(char s[], int lim) {
    int c,i;
    for (i = 0; i < lim - 1 && ((c = getchar())!=EOF) && c!='\n';i++) {
        s[i] = c;
    }
    if (c == '\n') {  //one line with nothing else except \n
        s[i] = c;
        i++;
    }
    s[i] = '\0';  // put \0 every time
    return i;
}

int removeInterval(char s[]) {
    int i;

    i = 0;
    while (s[i] != '\n') {
        i++;
    }
    i--;
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        i--;
    }
    if (i >= 0) {
        i++;
        s[i] = '\n';
        i++;
        s[i] = '\0';
    }
    return i;
}