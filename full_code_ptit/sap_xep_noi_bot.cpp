#include <stdio.h>
#define MAX 100

int n, i, j;

void swap(int &a, int &b) {
	int temp = a;
	 a = b;
	 b = temp;
}

void inkq(int a[]) 
{
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	scanf("%d", &n);
	int a[MAX];
	for(i = 0;  i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(i = 0; i < n - 1; i++) {
		int kt =  0;
		for(j = 0; j < n - i - 1; j++) {
			if(a[j] > a[j + 1 ]) {
				swap(a[j], a[j+1]);
				kt = 1;
			}
		}
		if(kt == 0) break;
		else {
			printf("Buoc %d: ", i + 1);
			inkq(a);
		}	
	}
//	inkq(a);
	return 0;
}
