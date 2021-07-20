#include <stdio.h>
#include <string.h>

int a[100];
int chuaxet[100];
char s[100];

void Try(int i) 
{
    for(int j = 0; j < strlen(s) - 1; j++) 
    {
        if(!chuaxet[j]) 
        {
            a[i] = j;
            chuaxet[j] = 1;
            if(i == strlen(s) - 1) 
            {
                for(int l = 1; l <= strlen(s) - 1; l++) 
                {
                    printf("%c",s[a[l]]);
                }
                printf(" ");
            }
            else {
                Try(i + 1);
            }
            chuaxet[j] = 0;
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    do
    {
        fgets(s,100,stdin);
        int size = strlen(s) - 1;
        int i, j;
        for (i = 0; i < size-2; i++) 
        {
            for (j = i+1; j < size - 1; j++) 
            {
                if (s[i] > s[j]) 
                {
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }
        Try(1);
        printf("\n");
        t--;
    }while (t >= 0);
    return 0;
}