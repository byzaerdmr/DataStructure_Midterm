#include<stdio.h>
#include<stdlib.h>

int left(int i) {
    return 2 * i + 1;
}   

int right(int i) {
    return 2 * i + 2;
}

int heap_size;

void heapify(int D[], int i) {
    int left_child, right_child, max, temp;
    left_child = left(i);
    right_child = right(i);

    if (left_child < heap_size && D[left_child] > D[i]) {
        max = left_child;
    } else {
        max = i;
    }

    if (right_child < heap_size && D[right_child] > D[max]) {
        max = right_child;
    }   

    if (max != i) {
        temp = D[i];
        D[i] = D[max];
        D[max] = temp;
        heapify(D, max);
    }
}

void build_heap (int D[], int n) {
    heap_size = n;
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(D, i);
    }

}

void heapsort(int D[], int n) {
    int i, temp;
    build_heap(D, n);
    for (i = n - 1; i > 0; i--) {
        temp = D[0];
        D[0] = D[i];
        D[i] = temp;
        heap_size--;
        heapify(D, 0);
    }
}

int main() {
    int n, i;
    int *D;

    printf("Dizi boyutunu girin: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Geçersiz dizi boyutu.\n");
        return 1;
    }

    D = (int *)malloc(sizeof(int) * n);
    if (D == NULL) {
        printf("Bellek tahsisi başarısız.\n");
        return 1;
    }

    printf("Dizinin elemanlarını girin: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &D[i]) != 1) {
            printf("Geçersiz giriş.\n");
            free(D);
            return 1;
        }
    }

    heapsort(D, n);

    printf("Sıralanmış dizi: ");
    for (i = 0; i < n; i++) {
        printf("%d ", D[i]);
    }
    printf("\n");

    free(D);
    return 0;
}