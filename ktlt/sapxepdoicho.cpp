#include <stdio.h>
#define MAX 100

struct data {
    int n;
    int a[MAX];
};

void hienmang(data d) {
	int i;
	for ( i = 0; i< d.n; i++) {
		printf("%d\t", d.a[i]);
	}
}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}


void sapxepdoicho(data d) {
    for(int i = 0; i < d.n - 1; i++) {
        for(int j = i + 1; j < d.n; j++) {
            if (d.a[j] < d.a[i]) {
                swap(d.a[i], d.a[j]);
            }
        }
        printf("buoc %d: ", i + 1);
        hienmang(d);
        printf("\n");
    }

}

int main() {
    data d;
    FILE*f = fopen("mang.txt","r");
    fscanf(f,"%d", &d.n);
    for(int i = 0; i < d.n; i++) {
        int u;
        fscanf(f,"%d",&u);
        d.a[i] = u;
    }
    fclose(f);
    sapxepdoicho(d);
    return 0;
}