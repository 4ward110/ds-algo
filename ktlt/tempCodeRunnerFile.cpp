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
        str[i] = '0';
        i--;
    } 
    if(i >= 0) {
        str[i] = '1';
    }
}

int main() {
    int test;
    scanf("%d\n", &test);
    char str[MAX];
    while(test>0){
        sinhtiep();
        puts(str);
        test--;
    }
    return 0;
}