#include <stdio.h>
#define MAX 100

void inkq(int a[], int l) 
{
	for(int i = 0; i < l; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}


int main() {
	int n;
	int i, j;
	scanf("%d", &n);
	int a[MAX];
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}	

//	printf("Buoc 0: %d\n", a[0]);
	for(i = 1; i < n; i++) {
		int key = a[i];
		j = i - 1;
		while(key < a[j] && j >=0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
//		printf("Buoc %d: ", i);
//		inkq(a, i + 1);
	}
	inkq(a,n);
	return 0;
}
