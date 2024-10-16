/// Wacp to find the Second Largest and Second Samllest in an array!

#include<stdio.h>

void main(){
    int n, temp;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i=0; i<n; i++){
        printf("Enter the element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    printf("Second smallest element: %d\n", arr[1]);
    printf("Second largest element: %d\n", arr[n-2]);
}