#include <stdio.h>
#include <stdlib.h>

// structure for node
struct Node {
    int dest;
    struct Node* next;
};

// structure for array of nodes
struct Child {
    struct Node *head;
};

//structure for the graph
struct Graph {
    int V;
    struct Child* array;
};

// Create a new adjacency list node
struct Node* newnode(int dest) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct Child*) malloc(V * sizeof(struct Child));
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = newnode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newnode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}


void BFS(struct Graph* graph, int startVertex) {
    // Mark all the vertices as not visited
    int* visited = (int*) malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
        visited[i] = 0;

    // queue for BFS
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
        struct Node* Child = graph->array[currentVertex].head;
        while (Child != NULL) {
            int adjVertex = Child->dest;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(queue, adjVertex);
            }
            Child = Child->next;
        }
    }

    free(visited);
    free(queue->array);
    free(queue);
}

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

    BFS(graph, startVertex);

    // Freeing memory
    for (int i = 0; i < V; i++) {
        struct Node* head = graph->array[i].head;
        while (head != NULL) {
            struct Node* temp = head;
            head = head->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);

    return 0;
}
