#include <stdio.h>
#define MAX 100

struct Stack {
	int n;
	int a[MAX];
};

void khoitao(Stack &s) {
	s.n = -1;
}
 
int kiemtrarong(Stack &s) {
	if(s.n == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int kiemtraday(Stack &s) {
	if (s.n == MAX - 1 ) {
		return 1;
	}
	else {
		return 0;
	}
}

void push (Stack &s, int x) {
	if (kiemtraday(s)) {
		printf("stack day");
	}
	else {
		s.n++;
		s.a[s.n] = x;
	}
}

int pop (Stack &s) {
	if (kiemtrarong(s)) {
		printf("Stack rong roi");
	}	
	else {
		return s.a[s.n--];
	}
}

int nhapstack(Stack &s) {
	int i;
	int x;
	int m;
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &x);
		push(s,x);
	}
} 

int hienstack(Stack &s) {
	while(kiemtrarong(s) == 0)
	printf("%3d", pop(s));
}

int main() {
	Stack s;
	khoitao(s);
	nhapstack(s);
	hienstack(s);
	return 0;
}
