#include <stdio.h>
#include <conio.h>


void docDSC(int a[][100],int &V){
	int i, j, u, v, sc;
	FILE*fi = fopen("DSC.txt","r");
	fscanf(fi, "%d %d", &V, &sc);
	for(i = 1; i <= sc; i++){
		fscanf(fi,"%d %d", &u, &v);
		a[u][v]=a[v][u]=1;
	}
	fclose(fi);
}

void ghiMTK(int a[][100],int V){
	int i,j;
	FILE*fi=fopen("MTK1.txt","w");
	fprintf(fi,"%d\n",V);
	for(i=1;i<=V;i++){
		for(j=1;j<=V;j++){
			fprintf(fi,"%3d",a[i][j]);
		}
		fprintf(fi,"\n");
	}
	fclose(fi);
}

void hienMTK(int a[][100],int V){
	int i,j;
	printf("%d\n",V);
	for(i=1;i<=V;i++){
		for(j=1;j<=V;j++){
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
}
int main(){
	int V,a[100][100];
	docDSC(a,V);
	ghiMTK(a,V);
	hienMTK(a,V);
	return 0;
}
