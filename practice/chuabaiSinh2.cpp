//ktra nguyento, in ra bang xau
#include<stdio.h>
#include<math.h>
#define MAX 100
int n, a[MAX],ok=0;
void khoitao(){
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		a[i]=0;
	}
}
void chht(){
	int i;
	for(i=1;i<=n;i++){
		printf("%d",a[i]);
	}
	printf("\t");
}
int loaikhong(){
	if(a[1]==0)
	return 0;
	return 1;
}
int ktrathuannghich(){
	int x=1, y=n;
	while(x<y){
		if(a[x]!=a[y])
		return 0;
		x++;
		y--;
	}
}
int ktngto(int m){
	if(m<2) return 0;
	if(m==2) return 1;
	int i;
	for(i=2;i<=sqrt(m);i++)
	if(m%i==0) return 0;
	return 1;
}
long gt(int *a, int n){
	int s=0,t=1;
	int i;
	for(i=n;i>=1;i--){
		s=s+a[i]*t;
		t=t*10;
	}
	return s;
}
void sinhtiep(){
	int i=n;//chay tu phai sang trai
	while(a[i]==9 && i>0){
		i--;
	}
	if(i==0) ok=1;
	else{
		a[i]++;
		int j;
		for(j=i+1;j<=n;j++){
			a[j]=0;
		}
	}
}
int main(){
	khoitao();
	while(!ok){
		long b=gt(a,n);
		if(loaikhong() && ktrathuannghich() && ktngto(b))
		chht();
		sinhtiep();
	}
	return 0;
}
