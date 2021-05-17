#include <stdio.h>

struct SinhVien {
	int masv;
	char hoten[13];
};


int main() {
	int n;
	scanf("%d", &n);
	int i;
	SinhVien SV[n];
	
	SinhVien *ptr;
	
	ptr = SV;
	
	for(i = 0; i < n; i++) {
		scanf("%d", &ptr->masv);
		gets(ptr->hoten);
		ptr++;
	}

	for (i = 0; i < n; i++) {
		printf("%d - %s\n", SV[i].masv, SV[i].hoten);
	}

	return 0;
}
