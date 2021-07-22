#include <stdio.h>

struct SinhVien{
	int masv;
	char hoten[13];
};

int main(){
	int n;
	scanf("%d",&n);
	int i;
	SinhVien sv[n];
	for(i=0;i<n;i++){
		scanf("%d",&sv[i].masv );
		gets(sv[i].hoten);
	}
	for(i=0;i<n;i++){
		printf("%d-%s\n",sv[i].masv ,sv[i].hoten );
	}
	return 0;
}
