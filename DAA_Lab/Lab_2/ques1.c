// Write a program in C to convert the first ‘n’ decimal numbers of a disc
// file to binary using recursion. Store the binary value in a separate disc file.
// Note# Read the value of ‘n’, source file name and destination file name from command line
// arguments. Display the decimal numbers and their equivalent binary numbers from the output
// file.

#include <stdio.h>
#include <stdlib.h>

void decimalToBinary(int n) 
{
    if (n > 1)
    decimalToBinary(n / 2);
    printf("%d", n % 2);
}

int main() 
{
    int n;
    printf("Enter the number of elements to convert: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));    
        if (arr == NULL) 
        {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d decimal numbers: ", n);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }

    printf("Binary equivalents: \n");
    for (int i = 0; i < n; i++) 
    {
        printf("The binary equivalent of %d is ", arr[i]);
        if (arr[i] == 0) 
        {
       printf("0"); 
        } else 
        {
            decimalToBinary(arr[i]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}
