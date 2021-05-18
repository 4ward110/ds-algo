#include <stdio.h>
#define MAX 100
int n,k,a[MAX];
bool ok=0;
void khoitao(){
	
	scanf("%d%d",&n,&k);
	int i;
	for(i=1;i<=k;i++){
		a[i]=1;
	}
}
void chht(){
	int i;
	for(i=1;i<=k;i++){
		printf("%d",a[i]);
	}
	printf("\n");
}
void sinhtiep(){
	
	int i=k;
	while(a[i]==n && i>0){
		i--;
	}
	if(i==0) ok=1;
	else{
		a[i]++;
		int j;
		for(j=i+1;j<=k;j++){
			a[j]=1;
		}
	}
}
int main(){
	khoitao();
	while(!ok){
		chht();
		sinhtiep();
		
	}
	return 0;
}
