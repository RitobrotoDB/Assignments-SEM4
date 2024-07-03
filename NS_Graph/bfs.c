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

// Queue structure for BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

// Function to create a queue of given capacity
struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

// Queue is full when size becomes equal to the capacity
int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

// Add an item to the queue
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

// Remove an item from the queue
int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to perform BFS on the graph
void BFS(struct Graph* graph, int startVertex) {
    // Mark all the vertices as not visited
    int* visited = (int*) malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    // Create a queue for BFS
    struct Queue* queue = createQueue(graph->V);

    // Mark the current node as visited and enqueue it
    visited[startVertex] = 1;
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(queue);
        printf("Visited %d\n", currentVertex);

        // Get all adjacent vertices of the dequeued vertex
        // If an adjacent vertex has not been visited, mark it visited and enqueue it
        struct AdjListNode* adjList = graph->array[currentVertex].head;
        while (adjList != NULL) {
            int adjVertex = adjList->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            adjList = adjList->next;
        }
    }

    free(visited);
    free(queue->array);
    free(queue);
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
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    // Perform BFS
    BFS(graph, startVertex);

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
