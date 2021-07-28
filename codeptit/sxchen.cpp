#include <stdio.h>
#define MAX 100


int n, i, j;

void swap(int &a, int &b) 
{
	int temp = a;
	a = b;
	b = temp;
}

void inkq(int x[], int l) 
{
	for(int i = 0; i < l; i++)
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
	printf("Buoc 0: %d\n", x[0]);
	for(i = 1; i < n; i++) {
		int key = x[i];
		j = i - 1;
		while(j >= 0 && key < x[j]) {
			x[j + 1] = x[j];
			j--;
		}
		x[j + 1] = key;
		printf("Buoc %d: ", i);
		inkq(x, i + 1);
		
	}
	
	
	
	return 0;
}
