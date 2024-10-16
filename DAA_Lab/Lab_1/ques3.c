// wap to Aim of the program: Write a program to read ‘n’ integers from a disc file that must contain
// some duplicate values and store them into an array. Perform the following operations on the
// array.
// a) Find out the total number of duplicate elements.
// b) Find out the most repeating element in the array.
// Input:
// Enter how many numbers you want to read from file: 15
// Output:
// The content of the array: 10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
// Total number of duplicate values = 4
// The most repeating element in the array = 10

#include<stdio.h>

void main(){
    int n, i, j, temp, max, count, maxCount;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if(n<2){
        printf("Array size is less than 2\n");
        return;
    }
    int arr[n];
    for(i=0; i<n; i++){
        printf("Enter the element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    count = 0;
    maxCount = 0;
    for(i=0; i<n; i++){
        count = 0;
        for(j=0; j<n; j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > maxCount){
            maxCount = count;
            max = arr[i];
        }
    }
    printf("Total number of duplicate values = %d\n", maxCount);
    printf("The most repeating element in the array = %d\n", max);
}