#include <stdio.h>

int d[10];
int v[10];
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
    for(int j = 1; j <= n - 1; j++) {
        for(int k = j + 1; k <= n; k++) {
            if(v[j] > v[k]) {
                int temp = v[j];
                v[j] = v[k];
                v[k] = temp;
            }
        }
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
                for(int i = 1; i <= n; i++) {
                    if(d[i] != 0)
                    {
                        tong[cnt].a[i] = i;
                    }
                    else {
                        tong[cnt].a[i] = 0;
                    }
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
    int t;
    scanf("%d", &t);
    while (t > 0)
    {
        init();
        Try(1);
        if(cnt == 0) {
            printf("-1");
        }
        else 
        {
            for(int i = cnt - 1; i >= 0; i--) 
            {
                int dem = 0;
                int arr[n];
                if(tong[i].a != NULL) 
                {
                    for(int j = 1; j <= n; j++) 
                    {
                        if(tong[i].a[j] != 0) {
                            arr[dem] = v[tong[i].a[j]];
                            dem++;
                        }
                    }
                }
                printf("[");
                for(int i = 0; i < dem - 1; i++) {
                    printf("%d ", arr[i]);
                }
                printf("%d",arr[dem-1]);
                printf("] ");
            }
        }
        printf("\n");
        cnt = 0;
        t--;
    }
     
    return 0;
}
