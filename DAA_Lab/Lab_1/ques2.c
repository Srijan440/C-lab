// wap to : Given an array arr[] of size N, find the prefix sum of the array. A prefix
// sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is
// arr[0] + arr[1] + arr[2] . . . arr[i].
// Input Array: 3 4 5 1 2
// Output Array: 3 7 12 13 15
#include <stdio.h>

void calculatePrefixSum(int arr[], int prefixSum[], int n) 
{
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++) 
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int main() {
    int arr[] = {3, 4, 5, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int prefixSum[n];

    calculatePrefixSum(arr, prefixSum, n);

    printf("Input Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nPrefix Sum Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }
    
    return 0;
}
