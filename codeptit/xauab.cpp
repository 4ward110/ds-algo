#include <stdio.h>

int ok = 0;

void sinhtiep(char x[],int n) {
    int i = n - 1;
    while(x[i] == 'B' && i>=0) {
        i--;
    }
    if(i == -1) {
        ok = 1;
    }
    else {
        x[i] = 'B';
        int j;
        for(j = 1 + i; j < n; j++) {
            x[j] = 'A';
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t > 0) {
        int n;
        scanf("%d", &n);
        char x[n];
        int i;
        for(i = 0; i < n; i++) {
		    x[i] = 'A';
	    }
        while(!ok) {
            int l;
            for(l = 0; l < n; l++) {
                printf("%c",x[l]);
	        }
            printf(" ");
            sinhtiep(x, n);
        }
        printf("\n");
        ok = 0;
        t--;
    }
    return 0;
}