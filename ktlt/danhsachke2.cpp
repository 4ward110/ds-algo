#include <stdio.h>
#define MAX 100

struct SinhVien
{
    int masv;
    char hoten[8];
};

struct DanhSach
{
    SinhVien sv[MAX];
    int n;
};

void khoitao(DanhSach &d) {
    d.n = 0;
}

void nhapdanhsach(DanhSach &d) {
    int i, n;
    scanf("%d", &d.n);
    for(i = 0; i < d.n; i++) {
        scanf("%d", &d.sv[i].masv);
        fgets(d.sv[i].hoten, 8, stdin);
    }
}

void hiendanhsach(DanhSach &d) {
    int j;
    for(j = 0; j < d.n; j++) {
        printf("%d - %s",d.sv[j].masv, d.sv[j].hoten);
        printf("\n");
    }
}

void themvitrik(DanhSach &d) {
    int k, i;
    scanf("%d", &k);
    SinhVien x;
    scanf("%d", &x.masv);
    fgets(x.hoten,8, stdin);
    if(k <= 0) {
        for(i = d.n; i > k; i--){
            d.sv[i] = d.sv[i-1];
        }
        d.sv[0] = x;
        d.n++;
    }
    else if(k > d.n) {
        i = d.n;
        d.sv[i] = x;
        d.n++;
    }
    else {
        for(i = d.n; i > k; i--) {
            d.sv[i] = d.sv[i-1];
        }
        d.sv[k] = x;
        d.n++;
    }
}

void xoavtk(DanhSach &d) {
    int i, k;
    scanf("%d", &k);
    if(k <= 0) {
        for(i = 0; i < d.n; i++) {
            d.sv[i] = d.sv[i+1];
        }
        d.n--;
    }
    else if (k > d.n) {
        d.n--;
    }
    else {
        for(i = k; i < d.n; i++){
            d.sv[i] = d.sv[i+1];
        }
        d.n--;
    } 
}

void tim(DanhSach d) {
    int i, x;
    scanf("%d", &x);
    for(i = 0; i < d.n; i++) {
        if(x == d.sv[i].masv) {
            printf("%d - %s", d.sv[i].masv, d.sv[i].hoten);
        }
        else{
            printf("khong co trong danh sach sv");
            break;
        }
    }
}

void swap(SinhVien &a, SinhVien &b) {
    SinhVien temp = a;
    a = b;
    b = temp;
}

void sapxep(DanhSach &d) {
    int i, j, x;
    for(i = 0; i< d.n - 1; i++) {
        for(j = 0; j < d.n - i - 1; j++) {
            if(d.sv[j].masv > d.sv[j+1].masv) {
                swap(d.sv[j], d.sv[j+1]);
            }
        }
    }
}

int main() {
    DanhSach d;
    nhapdanhsach(d);
    hiendanhsach(d);
    themvitrik(d);
    xoavtk(d);
    tim(d);
    printf("-----------\n");
    sapxep(d);
    hiendanhsach(d);
    return 0;
}