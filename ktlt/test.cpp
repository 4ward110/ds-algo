#include <stdio.h>
#define MAX 100

struct data {
    int n;
    int a[MAX];
};


void hienmang(int a[], int n) {
	int i;
	for ( i = 0; i< n; i++) {
		printf("%d\t", a[i]);
	}
}

void docfile(data d) {
    FILE*f = fopen("mang.txt","r");
    fscanf(f,"%d", &d.n);
    for(int i = 0; i < d.n; i++) {
        int u;
        fscanf(f,"%d",&u);
        d.a[i] = u;
    }
    fclose(f);
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}


void sapxepdoicho(data d) {
    for(int i = 0; i < d.n - 1; i++) {
        for(int j = i + 1; j < d.n - i; j++) {
            if (d.a[j] > d.a[i]) {
                swap(d.a[i], d.a[j]);
            }
        }
    }
    hienmang(d.a,d.n);
    printf("\n");
}

int main() {
    data d;
    docfile(d);
    sapxepdoicho(d);
    return 0;
}
