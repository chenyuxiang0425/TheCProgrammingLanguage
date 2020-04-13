//
// Created by Chen on 2020/4/13.
//


#include <stdio.h>
#define MAXWORD 10
#define OUT 0
#define IN 1

void printhor(int counts[],int numcount);
void updatecounts(int counts[], int len, int wordlen);

int main() {
    int c;
    int wordLenArray[MAXWORD];
    int wordlen;
    int status;
    int numcount;
    //init
    status = OUT;
    wordlen = 0;
    numcount = 0;

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
    for (int i = 0; i< MAXWORD; i++) {
        numcount += wordLenArray[i];
    }

    printhor(wordLenArray,numcount);
}


void updatecounts(int counts[], int len, int wordlen) {
    wordlen = wordlen > len ? len : wordlen;
    counts[wordlen - 1] += 1;
}

void printhor(int count[],int numcount) {
    for (int i = 0 ; i < MAXWORD-1;i++) {
        printf("%5d   : %5.2f ",i+1,(double)count[i]/numcount);
        for (int j = 0; j < count[i]; j++) {printf("*");};
        printf("\n");
    }
    printf("%5d++ : %5.2f  ",10 ,(double)count[9]/numcount);
    for (int j = 0; j < count[9]; j++) {printf("*");};
    printf("\n");
}
