#include <stdio.h>
#include <stdlib.h>

void insertionSort(int D[], int n) {
    int i, k, key;
    for (i=1; i<n ; i++) {
        key=D[i];

        for(k=i-1; k>=0 && key<=D[k]; k--) 
            D[k+1]=D[k];  // shift
            D[k+1]=key;  // insert
        }
    }

int main() {

    int D[10] = {5, 3, 8, 4, 2, 7, 1, 10, 6, 9};
    int n = sizeof(D)/sizeof(D[0]);
    insertionSort( D, n);
    printf("Sorted array: \n");
    for (int i=0; i<n; i++) {
        printf("%d ", D[i]);
    }

    return 0;
}