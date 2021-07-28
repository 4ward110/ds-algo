#include <stdio.h>
#define MAX 100


int n, i, j;

void swap(int &a, int &b) 
{
	int temp = a;
	a = b;
	b = temp;
}

void inkq(int x[]) 
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", x[i]);
	}
	printf("\n");
}



int main() 
{
	scanf("%d", &n);
	int x[MAX];
	for(i = 0; i  < n; i++) 
	{
		scanf("%d", &x[i]);
	}
	
	//sap xep
	
	for(i = 0; i < n - 1; i++)
	{
		int min = i;
		for(j = i + 1; j < n; j++) 
		{
			if(x[j] < x[min])
			{
				min = j;
			}
		}
		if(min != i) 
		{
			swap(x[min], x[i]);
		}
		printf("Buoc %d: ", i + 1);
		inkq(x);
	}
//	inkq(x);
	return 0;
}
