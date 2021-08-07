#include <stdio.h>
#define MAX 100
int n, a[MAX];
int ok = 0;
void khoitao()
{
	scanf("%d", &n);
}
void chht(){
	int i;
	for(i=1;i<=n;i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}
void sinhtiep(){
	int i = n;
	while(a[i] ==1 && i>0){
		i--;
	}
	if(i==0) ok=1;
	else {
		a[i] =1;
		int j;
		for(j=i+1;j<=n;j++){
			a[j] =0;
		}
	}
}
int ktra(){
	int i,j=1 ,s=n; 
	for(i=1;i<=n;i++){
		if(a[j] !=a[s]){
			return -1;
		}
		j++;
		s--;
	}
	return 1;
}
int main(){
	khoitao();
	while(!ok){
		if(ktra() ==1){
		chht();
		}
		sinhtiep();
	}
	return 0;
}
