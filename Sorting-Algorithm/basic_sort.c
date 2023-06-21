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

int selectionSortV2(int arr[], int n){
    for(int i = n-1 ; i >= 0 ; i--){
        int max_idx = i;
        for(int j = 0 ; j <= i ; j++ ){
            if(arr[j] > arr[max_idx]){
                max_idx = j;
            }
        }
        swap(&arr[max_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n){
    int key, j;
    for(int i=1; i<n; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void insertionSortV2(int arr[], int n){
    for(int i = n-2 ; i >= 0 ; i--){
        int temp = arr[i];
        int j = i + 1;
        while(j <= n && temp > arr[j]){
            arr[j-1] = arr[j];
            j = j +1;
        }
        arr[j-1] = temp;
    }
}

void bubbleSort(int arr[], int n){
    int flag;
    for(int i=0; i<n-1; i++){
        flag = 0;
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    
    selectionSort(arr, n);
    printArray(arr, n);

    insertionSort(arr, n);
    printArray(arr, n);

    bubbleSort(arr, n);
    printArray(arr, n);

    selectionSortV2(arr, n);
    printArray(arr, n);

    insertionSortV2(arr, n);
    printArray(arr, n);
    return 0;
}