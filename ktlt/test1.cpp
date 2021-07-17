#include <stdio.h>
// #include <stdlib.h>
struct dsk{
	int dinhke[1001];
	int n;
};
void swap(int &a, int &b){
	int t=a;
	a=b;
	b=t;
}
struct dsk dinh[1001];
int main(){
	int t;
	scanf("%d",&t);
	int i,j;
	
	while(t>0){
		for(i=1;i<=1000;i++){
			dinh[i].n=0;
		}
		int v,e;
		scanf("%d %d",&v,&e);
		for(i=0;i<e;i++){
			int a,b;
			scanf("%d  %d",&a,&b);
			dinh[a].dinhke[dinh[a].n]=b;
			dinh[a].n++;
			dinh[b].dinhke[dinh[b].n]=a;
			dinh[b].n++;
		}
		int k;
		for(i=1;i<=v;i++){
			for(j=0;j<dinh[i].n-1;j++){
				for(k=j+1;k<dinh[i].n;k++){
					if(dinh[i].dinhke[j]>dinh[i].dinhke[j+1]){
						swap(dinh[i].dinhke[j],dinh[i].dinhke[j+1]);
					}
				}
			}
		}
        for(i=1;i<=v;i++){
        	printf("%d: ",i);
        	for(j=0;j<dinh[i].n;j++){
        		printf("%d ",dinh[i].dinhke[j]);
        	}
        	printf("\n");
        }
        t--;
    }
}
