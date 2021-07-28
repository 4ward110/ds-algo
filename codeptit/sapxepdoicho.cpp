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

int main() {
	// nhap xuat du lieu
	scanf("%d", &n);
	int x[MAX];
	for(i = 0; i  < n; i++) 
	{
		scanf("%d", &x[i]);
	}
	
	// sap xep;
	for(i = 0; i < n - 1; i++)
	{
		for(j = i + 1; j < n; j++) 
		{
			if(x[j] < x[i]) 
			{
				swap(x[j], x[i]);
			}
		}
		printf("Buoc %d: ", (i+ 1));
		inkq(x);
	}
	
	// in kq

	
	
	
	
		
	return 0;
}
