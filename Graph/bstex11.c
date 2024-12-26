#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct Graph
{
    int numVertices;
    Node *adjLists[MAX];
    bool visited[MAX];
} Graph;

typedef struct Queue
{
    int items[MAX];
    int front;
    int rear;
} Queue;

Node *createNode(int vertex);
Graph *createGraph(int vertices);
void addEdge(Graph *graph, int src, int dest);
void bfs(Graph *graph, int startVertex);
Queue *createQueue();
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
bool isQueueEmpty(Queue *q);

Node *createNode(int vertex)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    for (int i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

void bfs(Graph *graph, int startVertex)
{
    Queue *q = createQueue();

    graph->visited[startVertex] = true;
    enqueue(q, startVertex);

    while (!isQueueEmpty(q))
    {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        Node *temp = graph->adjLists[currentVertex];

        while (temp)
        {
            int adjVertex = temp->vertex;

            if (!graph->visited[adjVertex])
            {
                graph->visited[adjVertex] = true;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

Queue *createQueue()
{
    Queue *q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isQueueEmpty(Queue *q)
{
    return q->rear == -1;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue is full\n");
        return;
    }

    if (q->front == -1)
        q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(Queue *q)
{
    if (isQueueEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }

    int item = q->items[q->front];
    q->front++;

    if (q->front > q->rear)
    {
        q->front = q->rear = -1;
    }

    return item;
}

int main()
{
    int data, src;
    Graph *graph = createGraph(6);
    int ch;

    while (1)
    {
        printf("Press 1 For Enter Edege\nPress 2 for Treaverse\nPress 3 For Exit:\n\nOption: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Enter Destination: ");
            scanf("%d", &data);
            printf("Enter Source: ");
            scanf("%d", &src);

            addEdge(graph, src, data);
            break;
        }
        case 2:
        {
            bfs(graph, 0);
            break;
        }
        case 3:
            exit(1);
            break;
        default:
            printf("Invalid Input....");
        }
    }

    // addEdge(graph, 0, 1);
    // addEdge(graph, 0, 2);
    // addEdge(graph, 1, 3);
    // addEdge(graph, 1, 4);
    // addEdge(graph, 2, 4);
    // addEdge(graph, 3, 5);
    // addEdge(graph, 4, 5);

    return 0;
}