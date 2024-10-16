// Implement Bubble Sort using C language. Use rand function to take input.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) 
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++) 
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1]) 
            {
                temp = arr[j];                            // Swapping arr[j] and arr[j + 1] 
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    srand(time(0));
    for (i = 0; i <n; i++) 
    {
        arr[i] = rand() % 100; 
    }

    printf("Original array:\n");
    for (i = 0; i < n; i++) 
    {
     printf("%d ", arr[i]);
    }
    printf("\n");

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
