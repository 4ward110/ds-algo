#include <stdio.h>
#define MAX 100

struct List {
	int n;
	int a[MAX];
};

void khoitao(List &l) {
	l.n = 0;
}

void nhap(List &l) {
	int i;
	scanf("%d", &l.n);
	for(i = 0; i < l.n; i++) {
		scanf("%d",&l.a[i]);
	}
}

void hienmang(List l) {
	int i;
	for (i = 0; i < l.n; i++) {
		printf("%d\t",l.a[i]);
	}
	printf("\n");
}

void themvtk(List &l) {
	int x,k,i;
	scanf("%d",&k);
	scanf("%d",&x);

	if(k<=0) {
		for(i=l.n; i > k; i--){
			l.a[i] = l.a[i-1];
		}
		l.a[0]  = x;
		l.n++;
	}
	else if(k>=l.n) {
		l.a[l.n] = x;
		l.n++;
	}
	else {
		for (i = l.n; i > k; i--) {
			l.a[i] = l.a[i-1];
		}
		l.a[k] = x;
		l.n++;
	}
}

void xoaptk(List &l) {
	int i,k;
	scanf("%d",&k);
	if(k<=0) {
		for(i = 0; i < l.n; i++) {
			l.a[i] = l.a[i+1];
		}
		l.n--;
	}
	else if(k>=l.n) {
		l.n--;
	}
	else{
		for(i = k; i < l.n; i++) {
			l.a[i] = l.a[i+1];
		}
		l.n--;
	}
}

void timk(List &l) {
	int i, k;
	scanf("%d", &k);
	for (i = 0; i < l.n; i++) {
		if(l.a[i] == k)
		printf("%d\t",l.a[i]);
	}
}

void swap(int &a, int &b) {
	int temp = a;
		a = b;
		b = temp;
}

//sap xep noi bot
void sapxep(List &l) {
	int i, j;
	for (i = 0; i < l.n-1 ; i++) {
		for(j = 0; j < l.n - i -1; j++) {
			if(l.a[j] > l.a[j+1]){
				swap(l.a[j], l.a[j+1]);
			}
		}
	}
}


int main() {
	List l;
	khoitao(l);
	nhap(l);
//	hienmang(l);
//	themvtk(l);
//	xoaptk(l);
	sapxep(l);
	hienmang(l);
//	timk(l);
	return 0;
}
