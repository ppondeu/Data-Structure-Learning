#include<stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n){
    int min_index;
    for(int i=0; i<n-1; i++){
        min_index = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);
    }
}

int main(){
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printArray(arr, n);
    return 0;
}