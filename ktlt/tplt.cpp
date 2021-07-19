#include <stdio.h>

struct dsk {
    int dinhke[50];
    int n;
};

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void nhap(dsk &dinh, int sodinh) {
    int u, v;
    int i = 1;
    char c;
    while(i <= sodinh) {
        scanf("%c", &c);
        if(c == '\n') {
            i++;
        }
        else {
            if(c != ' ') {
                
            }
        }
    }
}

int main() {
    dsk dinh[50];
    int sodinh;
    scanf("%d", &sodinh);
    nhap(dinh[50],sodinh);
    int i, j;

    return 0;
}