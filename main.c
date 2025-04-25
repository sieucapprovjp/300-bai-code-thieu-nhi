#include <stdio.h>

int nhapdayso(int a[]) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    return n;
}
int chen_so(int a[], int n) {
    int x, k;
    scanf("%d %d", &x, &k);
    if (k > n) k = n;
    if (k < 0) k = 0;
    for (int i = n; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;
    return n + 1;
}
void sap_xep(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
int chen_dung_vi_tri(int a[], int n) {
    int x;
    scanf("%d", &x);
    int k = 0;
    while (k < n && a[k] < x) k++;
    for (int i = n; i > k; i--) {
        a[i] = a[i - 1];
    }
    a[k] = x;
    return n + 1;
}
int xoa_phan_tu(int a[], int n) {
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 5 != 0) {
            a[m++] = a[i];
        }
    }
    return m;
}
void in_ra(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[105];
    int n;
    n = nhapdayso(a);
    n = chen_so(a, n);
    sap_xep(a, n);
    n = chen_dung_vi_tri(a, n);
    n = xoa_phan_tu(a, n);
    in_ra(a, n);
    return 0;
}