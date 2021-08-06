#include <stdio.h>

bool ok  = false;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void sinhtiep() {
    int n;
    scanf("%d", &n);
    int x[n+5];
    
    for(int i = 1;i <= n; i++) {
        scanf("%d", &x[i]);
    }
    int i = n - 1;
    while(i > 0 && x[i] > x[i + 1]) i-=1;
    if(i <= 0) {
        ok = true;
    }
    else{
        int k = n;
        while (x[k] < x[i]) {
        	k--;	
		}
        swap(x[i], x[k]);
        int l = i + 1, r = n;
        while(l < r) {
            swap(x[l], x[r]);
            l++;
            r--;
        }
    }
}


int main() {
	int t;
    scanf("%d", &t);
    while(t > 0) {
    	while(!ok) {
    		sinhtiep();
		}
        t--;
    }
	return 0;
}
