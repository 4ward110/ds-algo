// tim so nhi phan tiep theo
#include <stdio.h>
#include <string.h>
#define MAX 100

char str[10000];
int t;

void sinhtiep() {
    gets(str);
    t = strlen(str);
    int i = t - 1;
    while(str[i] == '1' && i>= 0) {
        i--;
    } 
    if(i < 0) {
        for(int i = 0; i < t; i++) {
            printf("0");
        }
        printf("\n");
    }
    else {
        str[i] = '1';
        for(int j = i + 1; j < t; j++) {
            str[j] = '0';
        }
        for(int i = 0; i < t; i++) {
            printf("%c",str[i]);
        }
        printf("\n");
    }
}

int main() {
    int test;
    scanf("%d\n", &test);
    char str[MAX];
    while(test>0){
        sinhtiep();
        test--;
    }
    return 0;
}