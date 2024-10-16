#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SYMBOL {
    char alphabet;
    int frequency;
} SYMBOL;

typedef struct NODE {
    SYMBOL symbol;
    struct NODE *left, *right;
} NODE;

typedef struct MIN_HEAP {
    NODE **array;
    int size;
} MIN_HEAP;

NODE* create_node(SYMBOL symbol) {
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->symbol = symbol;
    node->left = node->right = NULL;
    return node;
}

MIN_HEAP* create_min_heap(int capacity) {
    MIN_HEAP* min_heap = (MIN_HEAP*)malloc(sizeof(MIN_HEAP));
    min_heap->array = (NODE**)malloc(sizeof(NODE*) * capacity);
    min_heap->size = 0;
    return min_heap;
}

void swap(NODE** a, NODE** b) {
    NODE* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(MIN_HEAP* heap, int i) {
    int smallest = i, left = 2 * i + 1, right = 2 * i + 2;
    if (left < heap->size && heap->array[left]->symbol.frequency < heap->array[smallest]->symbol.frequency) 
        smallest = left;
    if (right < heap->size && heap->array[right]->symbol.frequency < heap->array[smallest]->symbol.frequency) 
        smallest = right;
    if (smallest != i) {
        swap(&heap->array[i], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

void insert(MIN_HEAP* heap, NODE* node) {
    heap->array[heap->size] = node;
    int i = heap->size++;
    while (i && heap->array[(i - 1) / 2]->symbol.frequency > heap->array[i]->symbol.frequency) {
        swap(&heap->array[i], &heap->array[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

NODE* extract_min(MIN_HEAP* heap) {
    swap(&heap->array[0], &heap->array[--heap->size]);
    heapify(heap, 0);
    return heap->array[heap->size];
}

NODE* construct_huffman_tree(SYMBOL* symbols, int n) {
    MIN_HEAP* heap = create_min_heap(n);
    for (int i = 0; i < n; i++) insert(heap, create_node(symbols[i]));
    while (heap->size > 1) {
        NODE *left = extract_min(heap), *right = extract_min(heap);
        SYMBOL symbol = {'\0', left->symbol.frequency + right->symbol.frequency};
        NODE* newNode = create_node(symbol);
        newNode->left = left; newNode->right = right;
        insert(heap, newNode);
    }
    return extract_min(heap);
}

void print_huffman_codes(NODE* root, char* code) {
    if (!root) return;
    if (!root->left && !root->right) printf("%c: %s\n", root->symbol.alphabet, code);
    char new_code[100];
    strcpy(new_code, code);
    if (root->left) {
        strcat(new_code, "0");
        print_huffman_codes(root->left, new_code);
    }
    strcpy(new_code, code);
    if (root->right) {
        strcat(new_code, "1");
        print_huffman_codes(root->right, new_code);
    }
}

int main() {
    SYMBOL symbols[] = {{'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}};
    NODE* root = construct_huffman_tree(symbols, sizeof(symbols) / sizeof(symbols[0]));
    char code[100] = "";
    print_huffman_codes(root, code);
    return 0;
}
