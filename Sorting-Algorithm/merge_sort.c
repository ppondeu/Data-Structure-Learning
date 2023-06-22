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
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Before sorted array\n");
    printArray(arr, n);

    mergeSort(arr, 0, n);

    printf("After sorted array\n");
    printArray(arr, n);

    return 0;
}