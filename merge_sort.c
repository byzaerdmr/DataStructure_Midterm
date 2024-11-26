#include <stdio.h>
#include <stdlib.h>

void merge(int D[], int left, int k, int right);
void mergesort(int D[], int left, int right){

    int k;
    if(left<right){
        k = (left+right)/2;
        mergesort(D, left, k);
        mergesort(D, k+1, right);


        merge(D, left, k, right);
    }
}

const int MAX_SIZE = 100;

void merge(int D[], int left, int k, int right){
    int i, j, l=0;
    int M[100];

    for(i=left, j=k+1; i<=k && j<=right;) {
        if(D[i] <= D[j]) {
            M[l] = D[i];
            i++;
            l++;
    }
        else {
            M[l] = D[j];
            j++;
            l++;
        }
    }

    while(i<=k) {
        M[l] = D[i];
        i++;
        l++;
    }

    while(j<=right) {
        M[l] = D[j];
        j++;
        l++;
    }

    for(i=left, l=0; i<=right; i++, l++) 
        D[i] = M[l];
  }

  int main(){
    
        int D[10] = {5, 3, 8, 4, 2, 7, 1, 10, 6, 9};
        int n = sizeof(D)/sizeof(D[0]);
        mergesort(D, 0, n-1);
        printf("Sorted array: \n");
        for (int i=0; i<n; i++) {
            printf("%d ", D[i]);
        }
    
        return 0;

  }