#include <stdio.h>

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}

void sapxepchon(int a[100], int n) {
	for(int i = 0; i < n - 1; i++) {
		int min = i;
		for(int j = i + 1; j < n; j++) {
			if(a[j] < a[min]) {
				min = j;
			}
		}
		if(min != i) {
			swap(a[i], a[min]);
		}
		printf("Buoc %d: ", i + 1);
		for(int i = 0; i < n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int a[100];
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	sapxepchon(a, n);
	
	return 0;
}
