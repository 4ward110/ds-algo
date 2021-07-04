#include <stdio.h>
#define MAX 100

void hienmang(int a[], int n) {
  int i;
  for(i = 0; i < n; i++) {
    printf("%d\t", a[i]);
  }
}

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int partition(int a[], int low, int high ) {
    // dat gia tri cho pivot
    int left, right, pivot_item = a[low];
    // gan gia tri cho 2 moc left va right
    left = low;
    right = high;
    while(left < right) {
        //move left item when left < pivot
        while(a[left] <= pivot_item) {
            left++;
        }
        //move right item when right > pivot
        while(a[right] > pivot_item) {
            right--;
        }
        if(left < right) {
            swap(a[left], a[right]);
        }
    }
    // right is final position for the pivot
    a[low] = a[right];
    a[right] = pivot_item;
    return right;
}

void Quicksort(int a[], int low, int high) {
    int pivot;
    //termination condition
    if(high > low) {
        pivot = partition(a, low, high);
        Quicksort(a, low, pivot - 1);
        Quicksort(a, pivot + 1, high);
    }
}


int main() {
    int i, n, a[MAX];
    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    Quicksort(a, 0, n-1);
    hienmang(a,n);
    return 0;
}