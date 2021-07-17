#include <stdio.h>
#define MAX 100

int n,a[MAX], ok = 0;

void khoitao() {
  scanf("%d", &n);
}

void chht() {
  int i;
  for(i = 1; i <= n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void sinhtiep() {
  int i = n;
  while(a[i] == 1 && i > 0) {
    i--;
  }
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

int kttn() {
  int x = 1, y = n;
  int i;
  for(i = 1; i <= n; i++)
  {
    if(a[x] != a[y]) {
      return -1;
    }
    x++;
    y--;
  }
  return 1;
}

int main() {
  khoitao();
  while(!ok) {
    if(kttn() == 1) {
      chht();
    }
    sinhtiep();
  }
  return 0;
}
