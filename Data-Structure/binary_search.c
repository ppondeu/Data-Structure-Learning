#include <stdio.h>

void merge(int arr[], int s, int m, int e)
{
    int L[m - s], R[e - m];
    for (int i = s; i < m; i++)
    {
        L[i - s] = arr[i];
    }
    for (int i = m; i < e; i++)
    {
        R[i - m] = arr[i];
    }

    int idx = s;
    int left_idx = 0, right_idx = 0;
    while (left_idx < m - s && right_idx < e - m)
    {
        if (L[left_idx] <= R[right_idx])
        {
            arr[idx++] = L[left_idx++];
        }
        else
        {
            arr[idx++] = R[right_idx++];
        }
    }

    while (left_idx < m - s)
    {
        arr[idx++] = L[left_idx++];
    }
    while (right_idx < m - s)
    {
        arr[idx++] = R[right_idx++];
    }
}

void mergeSort(int arr[], int s, int e)
{
    if (e - s <= 1)
    {
        return;
    }
    int m = (s + e) / 2;
    mergeSort(arr, s, m);
    mergeSort(arr, m, e);
    merge(arr, s, m, e);
}

int binarySearch(int arr[], int k, int s, int e){
    // base case
    if(s + 1 == e){
        if(arr[s] == k){
            return s;
        }
        else{
            return -1;
        }
    }
    
    // recursive case
    int m = (s + e) / 2;
    if(k < arr[m]){
        return binarySearch(arr, k, s, m);
    }
    else{
        return binarySearch(arr, k, m, e);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n], temp[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        temp[i] = arr[i];
    }

    int value;
    scanf("%d", &value);

    mergeSort(temp, 0, n);

    int idx = binarySearch(temp, value, 0, n);

    if(idx == -1){
        printf("-1");
        return 0;
    }
    for(int i = 0 ; i < n ;i++){
        if(arr[i] == temp[idx]){
            idx = i;
            break;
        }
    }

    printf("%d", idx);

    return 0;
}