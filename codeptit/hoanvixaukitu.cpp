#include <stdio.h>
#include <string.h>

int a[100];//mang gia tri dau ra
int chuaxet[100]; //mang gia tri xac nhan ki tu da duoc chon hay chua
char s[100]; //mang gia tri dau vao

void Try(int i) 
{
    for(int j = 0; j < strlen(s) - 1; j++)  // 
    {
        if(!chuaxet[j]) 
        {
            a[i] = j;
            chuaxet[j] = 1;
            if(i == strlen(s) - 1) // in ra cau hinh
            {
                //
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
        // doc tu ban phim
        fgets(s,100,stdin);
        int size = strlen(s) - 1;
        int i, j;
        //sap xep lai chuoi tu phan phim vua nhap the A->Z
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
        //quay lui de sinh cau hinh
        Try(1);
        printf("\n");
        t--;
    }while (t >= 0);
    return 0;
}