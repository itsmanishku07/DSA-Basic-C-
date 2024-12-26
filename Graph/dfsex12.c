#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists; 
    int* visited;    
} Graph;

Node* createNode(int v) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int vertices) {
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void DFSForward(Graph* graph, int vertex) {
    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFSForward(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

void DFSBackward(Graph* graph, int vertex) {
    graph->visited[vertex] = 1; 

    Node* adjList = graph->adjLists[vertex];
    Node* temp = adjList;

    while (temp != NULL) {
        int connectedVertex = temp->vertex;

        if (graph->visited[connectedVertex] == 0) {
            DFSBackward(graph, connectedVertex);
        }
        temp = temp->next;
    }

    printf("%d ", vertex);
}


int main() {
    int vertices = 6;

    Graph* graph = createGraph(vertices);
    addEdge(graph, 0 , 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    printf("DFS Forward Traversal:\n");
    DFSForward(graph, 0);

    for (int i = 0; i < vertices; i++) {
        graph->visited[i] = 0;
    }

    printf("\nDFS Backward Traversal:\n");
    DFSBackward(graph, 0);

    return 0;
}
