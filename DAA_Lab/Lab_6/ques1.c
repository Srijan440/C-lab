#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100  // Maximum number of vertices

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int V)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed MST stored in parent[] and calculate the total weight
int printMST(int parent[], int graph[MAX][MAX], int V)
{
    int totalWeight = 0;
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i] + 1, i + 1, graph[i][parent[i]]);
        totalWeight += graph[i][parent[i]];
    }
    return totalWeight;
}

// Function to implement Prim's algorithm for MST
void primMST(int graph[MAX][MAX], int V, int startVertex)
{
    int parent[MAX];  // Array to store the MST
    int key[MAX];     // Key values used to pick minimum weight edges
    bool mstSet[MAX]; // To represent set of vertices included in the MST

    // Initialize all keys as infinite and mstSet[] as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    // Start with the chosen starting vertex
    key[startVertex] = 0;
    parent[startVertex] = -1;  // Root of the MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);  // Pick the minimum key vertex
        mstSet[u] = true;                // Add the picked vertex to the MST set

        // Update the key values for adjacent vertices
        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the MST and calculate its total weight
    int totalWeight = printMST(parent, graph, V);
    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
}

int main()
{
    int V, startVertex;
    int graph[MAX][MAX];

    // Input the number of vertices
    printf("Enter the Number of Vertices: ");
    scanf("%d", &V);

    // Input the starting vertex
    printf("Enter the Starting Vertex (1 to %d): ", V);
    scanf("%d", &startVertex);
    startVertex--;  // To match 0-based index

    // Input the adjacency matrix
    printf("Enter the Adjacency Matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Run Prim's algorithm
    primMST(graph, V, startVertex);

    return 0;
}