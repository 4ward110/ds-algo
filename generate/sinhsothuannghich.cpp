//sinh quay lui
#include <math.h>
#include <stdio.h>
#define MAX 100
int n,a[MAX],ok=0;
void khoitao() {
	scanf("%d", &n);
	int i;
	for (i = 1; i<=n; i++) {
		a[i] = 0;
	}
}

void chht(){
	int i;
	for( i =1; i<=n; i++) {
		printf("%d", a[i]);
	}
	printf("\t");
}
// sinh nhi phan truoc => xet dk de tim so than nghich
void sinhtiep() {
	// chay tu phai sang trai
	int i = n;
	while(a[i] == 1 &&  i > 0){
		i--;
	}
	if(i==0) ok=1;
	else{
		a[i] = 1;
		int j;
		for(j=i+1 ; j <= n; j++) {
			a[j] = 0;
		}
	}
}

// kiem tra thuan nghich
int kttn() {
	int x = 1;
	int y = n;
	while( x < y ) {
		if(a[x] != a[y]){
			return 0;
		}
		x++;
		y--;
	}
}


int main() {
// can 
	khoitao();
	while(!ok) {
		if(kttn())
		chht();
		sinhtiep();	
	}
	return 0;
}
