#include <stdio.h>
#include <stdlib.h>

struct Team {
    char name[31];
    int so_tran_thang;
    int so_tran_thua;
    int so_tran_hoa;
    int so_ban_thang;
    int so_ban_thua;
    int diem;
};
typedef struct Team Team;

void swap(Team *teamA, Team *teamB) {
    Team temp = *teamA;
    *teamA = *teamB;
    *teamB = temp;
}

void selection(Team a[], int n) {
    int max_idx;
    for (int i = 0; i < n - 1; i++) {
        max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j].diem > a[max_idx].diem) {
                max_idx = j;
            }
        }
        if (max_idx != i) {
            swap(&a[i], &a[max_idx]);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    Team doi_bong[n];
    for (int i = 0; i < n; i++) {
        scanf("%s", doi_bong[i].name);
        doi_bong[i].so_tran_thang = 0;
        doi_bong[i].so_tran_thua = 0;
        doi_bong[i].so_tran_hoa = 0;
        doi_bong[i].so_ban_thang = 0;
        doi_bong[i].so_ban_thua = 0;
        doi_bong[i].diem = 0;
    }

    int so_tran = (n * (n - 1)) / 2;

    for (int k = 0; k < so_tran; k++) {
        int A, B, X, Y;
        scanf("%d %d %d %d", &A, &B, &X, &Y);
        A--;
        B--;
        doi_bong[A].so_ban_thang += X;
        doi_bong[A].so_ban_thua += Y;
        doi_bong[B].so_ban_thang += Y;
        doi_bong[B].so_ban_thua += X;

        if (X > Y) {
            doi_bong[A].so_tran_thang++;
            doi_bong[A].diem += 3;
            doi_bong[B].so_tran_thua++;
        } else if (Y > X) {
            doi_bong[B].so_tran_thang++;
            doi_bong[B].diem += 3;
            doi_bong[A].so_tran_thua++;
        } else {
            doi_bong[A].so_tran_hoa++;
            doi_bong[B].so_tran_hoa++;
            doi_bong[A].diem += 1;
            doi_bong[B].diem += 1;
        }
    }
    selection(doi_bong, n);
    for (int i = 0; i < 3 && i < n; i++) {
        printf("%s %d\n", doi_bong[i].name, doi_bong[i].diem);
    }

    int r=rand();
    printf("%d",r/10);
    return 0;
}
