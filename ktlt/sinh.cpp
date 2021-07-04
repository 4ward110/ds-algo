// xac dinh duoc trattu cac nghiem
// biet nghiem dau va nghiem cuoi
// xay dung duoc thuat toan tu mot nghiem chua phai la nghien cuoi cung ta deu sinh ra mot cau hihf dung sau no


#include <stdio.h>
#define MAX 100

int n,a[MAX], ok = 0;

void khoitao() {
  int i;
  scanf("%d", &n);
  for(i = 1; i <= n; i++) {
    a[i] = 0;
  }
}

void chht() {
  int i;
  for(i = 1; i <= n; i++) {
    printf("%d", a[i]);
  }
  printf("\n");
}

void sinhtiep() {
  int i = n;
  while(a[i] == 1 && i > 0) {
    i--;
  }
  // break khi gia tri i giam xuong gia tri 0
  if(i == 0) {
    ok = 1;
  }
  else {
    a[i] = 1;
    int j;
    for(j = i + 1; j <= n; j++) {
      a[j] = 0;
    }
  }
}

int kiemtrathuannghich() {
  int i, temp = 0;
  int m[MAX];
  for(i = n; i >= 1; i--) {
    m[i] = a[n - i + 1];
  }
  for(int j = 1; j <= n; j++) {
    if(m[j] == a[j]) {
      temp++;
    }
  }
  return temp;
}

int kttn() {
  int x = 1, y = n;
  while (x < y) {
    if(a[x] != a[y]) {
      return 0;
    }
    x++;
    y--;
  }
}


int main() {
  khoitao();
  while(!ok) {
    if(kttn()) {
      chht();
    }
    sinhtiep();
  }
  return 0;
}
