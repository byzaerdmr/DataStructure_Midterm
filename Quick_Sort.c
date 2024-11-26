#include <stdio.h>
#include <stdlib.h>

void quick_sort(int D[], int left, int right){

    int k, j, q, temp;

    k=left;
    j=right;
    q=D[(left+right)/2];

    do{
        while((D[k]<q) && (k<right)) 
            k++;
        while((D[j]>q) && (j>left))
            j--;
        
        if(k<=j){
            temp=D[k];
            D[k]=D[j];
            D[j]=temp;
            k++;
            j--;
        }
    }  while(k<=j);

    if(left<j)
        quick_sort(D, left, j);
    if(k<right)
        quick_sort(D, k, right);
}

int main(){
    int D[10]={5, 3, 8, 4, 2, 7, 1, 10, 6, 9};
    int i;

    quick_sort(D, 0, 9);

    for(i=0; i<10; i++)
        printf("%d ", D[i]);
    printf("\n");

    return 0;
}