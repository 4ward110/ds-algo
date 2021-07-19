#include<stdio.h>
#include <math.h> 
const int MAX = 1000;
int a[MAX][MAX],b[MAX][MAX],c[MAX][MAX];
 int main(){
  int n,m,p;
  scanf("%d%d%d",&n,&m,&p);
  
   
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
      { 
         scanf("%d", &a[i][j]);
        }
    
	for(int i = 0; i < m; i++)
      for(int j = 0; j < p; j++)
      {
         scanf("%d", &b[i][j]);
         }   
	
 
	for(int i = 0; i < m; i++)
      for(int j = 0; j < m; j++)
      {
        c[i][j]=0;  
        for(int k=0; k<m ;k++)  
          {  
              c[i][j]+=a[i][k]*b[k][j];  
          }  
        }   
	
	 for(int i=0;i<p;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
          return 0; 
         }