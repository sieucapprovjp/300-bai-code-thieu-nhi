#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void bubu_sort_giam(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
void bubu_sort_tang(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    if (n<0 || n>100) return 0;
    int numbers[100];
    int even[100];
    int odd[100];
    int evenCount = 0;
    int oddCount = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
        if (numbers[i] >= 0) {
            if (numbers[i] % 2 == 0) {
                even[evenCount++] = numbers[i];
            } else {
                odd[oddCount++] = numbers[i];
            }
        }
    }
    bubu_sort_giam(even, evenCount);
    bubu_sort_tang(odd, oddCount);
    for (int i = 0; i < evenCount; i++) {
        printf("%d ", even[i]);
    }
    for (int i = 0; i < oddCount; i++) {
        printf("%d ", odd[i]);
    }
    return 0;
}