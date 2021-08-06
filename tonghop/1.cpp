#include <stdio.h>

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void sapxepdoicho(int a[100], int n) {
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
//		printf("Buoc %d: ", i+1);
//		for(int i = 0; i < n; i++) {
//			printf("%d ", a[i]);
//		}
//		printf("\n");
	}
	for(int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main() {
	int n;
	scanf("%d", &n);
	int a[100];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sapxepdoicho(a, n);
	return 0;
}
