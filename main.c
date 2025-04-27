#include <stdio.h>

int nhapso() {
    int n;
    do {
        printf("Nhap so nguyen duong n (>0): ");
        scanf("%d", &n);
    } while (n <= 0);
    return n;
}

int sum(int n) {
    int tong = 0;
    int tmp = n;
    while (tmp > 0) {
        tong += tmp % 10;
        tmp /= 10;
    }
    printf("Tong cac chu so cua %d la: %d\n", n, tong);
    return tong;
}

void liet_ke_uoc(int n) {
    printf("Cac uoc so cua %d la: ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int so_nto(int n) {
    if (n < 2) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void liet_ke_uoc_nto(int n) {
    printf("Cac uoc so nguyen to cua %d la: ", n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0 && so_nto(i)) {
            printf("%d ", i);
        }
    }
    printf("\n");
}
void phan_tich_n_la_so_nto(int n) {
    printf("Phan tich %d thanh cac thua so nguyen to: ", n);
    for (int i = 2; i * i <= n; i++) {
        int count = 0;
        while (n % i == 0) {
            count++;
            n /= i;
        }
        if (count) {
            if (count > 1)
                printf("%d^%d", i, count);
            else
                printf("%d", i);
            if (n > 1) printf(" * ");
        }
    }
    if (n > 1) {
        printf("%d", n);
    }
    printf("\n");
}
int main() {
    int so = nhapso();
    sum(so);
    liet_ke_uoc(so);
    liet_ke_uoc_nto(so);
    phan_tich_n_la_so_nto(so);
    return 0;
}