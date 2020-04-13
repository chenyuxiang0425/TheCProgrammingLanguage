//
// Created by Chen on 2020/4/12.
//
/*
 * Exercise 1-13.
 * Write a program to print a histogram of the lengths of words in its input.
 * It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 */

#include <stdio.h>
#define MAXWORD 10
#define OUT 0
#define IN 1

void printhor(int counts[]);
void updatecounts(int counts[], int len, int wordlen);
int getpeak(int counts[]);
void printver(int counts[]);

int main() {
    int c;
    int wordLenArray[MAXWORD];
    int wordlen;
    int status;

    //init
    status = OUT;
    wordlen = 0;
    for (int i = 0; i< MAXWORD; i++) {
        wordLenArray[i] = 0;
    }

    // fill in wordLenArray
    while ((c=getchar())!=EOF) {
        if(status == IN && (c == '\t' || c == ' ' || c == '\n')) {
            status = OUT;
            updatecounts(wordLenArray,MAXWORD,wordlen);
            wordlen = 0;
        } else if (status == OUT && (c == '\t' || c == ' ' || c == '\n')) {
            continue;
        } else {
            status = IN;
            wordlen = wordlen + 1;
        }
    }
    printhor(wordLenArray);
    printver(wordLenArray);
}


void updatecounts(int counts[], int len, int wordlen) {
    wordlen = wordlen > len ? len : wordlen;
    counts[wordlen - 1] += 1;
}

void printhor(int count[]) {
    printf("Horizontal histogram\n");
    for (int i = 0 ; i < MAXWORD-1;i++) {
        printf("%5d   : %5d ",i+1,count[i]);
        for (int j = 0; j < count[i]; j++) {printf("*");};
        printf("\n");
    }
    printf("%5d++ :%5d  ",10 ,count[9]);
    for (int j = 0; j < count[9]; j++) {printf("*");};
    printf("\n");
}

int getpeak(int counts[]) {
    int peak = 0;
    int i;
    for (i = 0; i < MAXWORD; i++) {
        peak = peak > counts[i] ? peak : counts[i];
    }
    return peak;
}
//source:https://github.com/fool2fish/the-c-programming-language-exercise-answers/blob/master/ch01/1-13.c
void printver(int counts[]) {
    printf("\nVertical histogram:\n\n");
    int peak = getpeak(counts);
    int i, j, h = 20;

    int bars[MAXWORD];
    for (i = 0; i < MAXWORD; i++) {
        bars[i] = counts[i] * h / peak;
    }

    for (i = 0; i <= h; i++) {
        for (j = 0; j < MAXWORD; j++) {
            if (h - i == bars[j]) {
                printf("%-5d", counts[j]);
            } else if (h - i < bars[j]) {
                printf("%-5c", '+');
            } else {
                printf("%-5c", ' ');
            }
        }
        printf("\n");
    }

    for (i = 0; i < MAXWORD; i++) {
        printf("=====");
    }
    printf("\n");

    for (i = 0; i < MAXWORD; i++) {
        char *format = "%-5d";
        if (i == MAXWORD - 1) {
            format = ">=%-5d";
        }
        printf(format, i + 1);
    }
    printf("\n");
}
