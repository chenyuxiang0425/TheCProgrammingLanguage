//
// Created by Chen on 2020/4/13.
//


#include <stdio.h>
#define MAXLINE 8000
#define LONGLINE 80
int getLine(char s[], int lim);
void reverse(char s[]);
void swap(char s[],int a,int b);

int main() {
    char line[MAXLINE];
    while ((getLine(line, MAXLINE) > 0)) {
        reverse(line);
        printf("%s",line);
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

void reverse(char s[]) {
    int start,last;

    start = 0;
    last = 0;
    while (s[last] != '\0') {
        last ++;
    }
    last --;
    if (s[last == '\n']) {
        last --;
    }

    while(start < last) {
        swap(s,start,last);
        start ++;
        last --;
    }
}

void swap(char s[],int a,int b) {
    char tmp;
    tmp = s[a];
    s[a] = s[b];
    s[b] = tmp;
}
