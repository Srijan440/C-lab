#include <stdio.h>
#include <stdlib.h>

// Define a structure ITEM
typedef struct ITEM {
    int item_id;
    int item_profit;
    int item_weight;
    double profit_weight_ratio;
} ITEM;

// Function to swap two items
void swap(ITEM *a, ITEM *b) {
    ITEM temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify the array
void heapify(ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to build a max heap
void build_max_heap(ITEM arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Function to extract the maximum element from the heap
ITEM extract_max(ITEM arr[], int *n) {
    ITEM max = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    heapify(arr, *n, 0);
    return max;
}

// Function to calculate the maximum profit using the Fractional Knapsack algorithm
double fractional_knapsack(ITEM items[], int n, int capacity) {
    // Build a max heap
    build_max_heap(items, n);

    double total_profit = 0;
    while (capacity > 0 && n > 0) {
        ITEM item = extract_max(items, &n);
        if (item.item_weight <= capacity) {
            capacity -= item.item_weight;
            total_profit += item.item_profit;
        } else {
            double fraction = (double)capacity / item.item_weight;
            total_profit += item.item_profit * fraction;
            break;
        }
    }

    return total_profit;
}

int main() {
    int num_items;
    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    ITEM items[num_items];
    for (int i = 0; i < num_items; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%d %d", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = (double)items[i].item_profit / items[i].item_weight;
    }

    int capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &capacity);

    double max_profit = fractional_knapsack(items, num_items, capacity);

    printf("Maximum profit: %.2f\n", max_profit);

    return 0;
}