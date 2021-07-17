#include <stdio.h>
#define MAX 100

bool ok = false;
int n, k, a[MAX];

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void khoitao() {
    scanf("%d", &n);
    scanf("%d", &k);
    int i;
    for(i = 1; i <= k; i++) {
        a[i] = i;
    }
}

void chht() {
    int i;
    for(i = 1; i <= k; i++) {
        printf("%d", a[i]);
    }
    printf("\n");
}

// // sinh hoanvi
// void sinhtiep() {
//     // tim tu trai qua phai vi tri co chi so i dau tien thoa man xi < xi + 1
//     int i = n - 1;
//     while(i > 0 && a[i] > a[i + 1]) {
//         i--;
//     }
//     if( i == 0) ok = true;
//     else {
//         int k = n;
//         while(a[i] > a[k]) {
//             k--;
//         }
//         swap(a[i],a[k]);
//     }
//     // lat nguoc
//     int r = i + 1;
//     int s = n;
//     while( r < s) {
//         swap(a[r], a[s]);
//         r++;
//         s--;
//     }
// }




// sinh chinh hop
// void sinhtiep() {
//     int i = k;
//     while(a[i] == n && i > 0) {
//         i--;
//     }
//     if(i == 0) ok = true;
//     else {
//         a[i]++;
//         for(int j = i + 1; j <= k;j++) {
//             a[j] = 1;
//         }
//     }
// }

// sinh to hop 
void sinhtiep() {
    int i = k;
    while(a[i] == n - k + i && i > 0) {
        i--;
    }
    if(i == 0) ok = true;
    else {
        a[i]++;
        int j;
        for(j = i + 1; j <= k; j++) {
            a[j] = a[i] + j - i;
        }
    }
}

int main() {
    khoitao();
    while(!ok) {
        chht();
        sinhtiep();
    }
    return 0;
}