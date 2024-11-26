#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int D[], int n) {
    int temp, k, move;
    for (move=0; move<= (n-1); move++ )
    {
        for (k=0; k< (n-1-move); k++) {
            if (D[k] > D[k+1]) {
                temp = D[k];
                D[k] = D[k+1];
                D[k+1] = temp;
            }
        }
    }
}

int main() {

    int D[10] = {5, 3, 8, 4, 2, 7, 1, 10, 6, 9};
    int n = sizeof(D)/sizeof(D[0]);
    bubbleSort(D, n);
    printf("Sorted array: \n");
    for (int i=0; i<n; i++) {
        printf("%d ", D[i]);
    }

    return 0;
}