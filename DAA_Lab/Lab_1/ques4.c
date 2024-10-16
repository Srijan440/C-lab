// wap to ROTATE_RIGHT(p1, p2 ) right an array for first p2
// elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p &amp;
// q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
// rotated.
// Input:
// Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99
// Call the function ROTATE_RIGHT(A, 5)
// Output:
// Before ROTATE: 11 22 33 44 55 66 77 88 99
// After ROTATE: 55 11 22 33 44 66 77 88 99

#include<stdio.h>

void exchange(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void rotate_right(int *p1, int p2){
    int i;
    for(i=0; i<p2; i++){
        exchange(p1, p1+i);
    }
}


void main(){
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for(i=0; i<n; i++){
        printf("Enter the element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Before ROTATE: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    rotate_right(arr, 5);
    printf("After ROTATE: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}