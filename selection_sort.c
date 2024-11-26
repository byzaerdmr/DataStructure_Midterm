#include<stdio.h>
#include<stdlib.h>

void selectionSort(int D[], int n) {
    int i, index, j, min;
    for( i=0; i<n-1; i++) {
        min = D[n-1];
        index = n-1;

        for(j=i; j< (n-1); j++) {
            if(D[j] < min) {
                min = D[j];
                index = j;
            }
        }
        if (i != index) {
            D[index] = D[i];
            D[i] = min;
        }
    }
}

int main(){

    int D[10] = {5, 3, 8, 4, 2, 7, 1, 10, 6, 9};
    int n = sizeof(D)/sizeof(D[0]);
    selectionSort(D, n);
    printf("Sorted array: \n");
    for (int i=0; i<n; i++) {
        printf("%d ", D[i]);
    }

    return 0;
}