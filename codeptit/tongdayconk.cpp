#include <stdio.h>

int d[100];
int v[100];
int n, k;
int cnt = 0;


struct daycon
{
    int a[10];
};

struct daycon tong[100];

void init() {
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
    }
}

void hien() {
  int i;
  for (i = 1; i <= n; i++) {
    printf("%d", d[i]);
  }
  printf("\n");
}


void Try(int i) 
{
    int j;
    for(j = 0; j <= 1; j++) 
    {
        d[i] = j;
        if(i == n)
        {
            int s = 0;
            int l;
            for(l = 1; l <= n; l++) {
                if(d[l] == 1) {
                    s = s+ v[l];
                }
            }
            if(s == k) 
            {
                for(int i = 0; i < n; i++) {
                    tong[cnt].a[i] = d[i+1];
                }
                cnt++;
            }
        }
        else {
            Try(i + 1);
        }
    }
}

int main() {
    init();
    Try(1);
    for(int i = 0; i < cnt; i++) 
    {
        int dem = 0;
        if(tong[i].a != NULL) {
            for(int j = 0; j < n; j++) {
                dem++;
                if(v[tong[i].a[j]] != 0) {
                    printf("%d\t", v[dem]);
                }
            }
            printf("\n");
        }
    }
    printf("%d\n", cnt);
     
    return 0;
}
