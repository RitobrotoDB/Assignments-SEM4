#include <stdio.h>
#include <stdlib.h>

// Define the structure for the adjacency list node
struct AdjListNode {
    int dest;
    struct AdjListNode* next;
};

// Define the structure for the adjacency list
struct AdjList {
    struct AdjListNode *head;
};

// Define the structure for the graph
struct Graph {
    int V;
    struct AdjList* array;
};

// Create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest) {
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

// Add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // Since the graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to perform DFS on the graph
void DFSUtil(struct Graph* graph, int v, int* visited) {
    // Mark the current node as visited and print it
    visited[v] = 1;
    printf("Visited %d\n", v);

    // Recur for all the vertices adjacent to this vertex
    struct AdjListNode* adjList = graph->array[v].head;
    while (adjList != NULL) {
        int adjVertex = adjList->dest;
        if (!visited[adjVertex]) {
            DFSUtil(graph, adjVertex, visited);
        }
        adjList = adjList->next;
    }
}

// DFS traversal of the vertices reachable from v
void DFS(struct Graph* graph, int startVertex) {
    // Mark all the vertices as not visited
    int* visited = (int*) malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    // Call the recursive helper function to print DFS traversal
    DFSUtil(graph, startVertex, visited);

    free(visited);
}

// Main function
int main() {
    int V, E;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V);

    printf("Enter the edges (source and destination):\n");
    for (int i = 0; i < E; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for DFS: ");
    scanf("%d", &startVertex);

    // Perform DFS
    DFS(graph, startVertex);

    // Free allocated memory
    for (int i = 0; i < V; i++) {
        struct AdjListNode* head = graph->array[i].head;
        while (head != NULL) {
            struct AdjListNode* temp = head;
            head = head->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);

    return 0;
}
