//liet ke tap con chinh hop khong lap (n=3,k=2)

#include <stdio.h>
#define MAX 100

int n,k,a[MAX],ok=0;

void khoitao() {
	scanf("%d%d",&n,&k);
	int i;
	for (i = 1; i<=k; i++) {
		a[i] = 1;
	}
}

void chht() {
	int i;
	for( i = 1; i<=k; i++ ) {
		printf("%d",a[i]);
	}
	printf("\t");
}

void sinhtiep() {
	int i = k;
	while(a[i] == n && i>0) {
		i--;
	}
	if(i==0) ok=1;
	else{
		a[i]++;
		int j;
		for(j=i+1; j<=k; j++){
			a[j]=0;
		}
	}
}

int kttn(){
	int x=1, y=k;
	while (x<y) {
		if(a[x] != a[y])
		return 0;
		x++;
		y--;
	}
}

int main() {
	khoitao();
	while(!ok){
		if(!kttn())
		chht();
		sinhtiep();
	}
	return 0;	
}
