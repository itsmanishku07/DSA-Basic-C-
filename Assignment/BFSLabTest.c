#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 100
struct Queue
{
    int items[MAX];
    int front;
    int rear;
};
struct Graph
{
    int vertices;
    int adj[MAX][MAX];
};
void initQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}
bool isEmpty(struct Queue *q)
{
    return q->front == -1;
}
void enqueue(struct Queue *q, int value)
{
    if (q->rear == MAX - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}
int dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
        return item;
    }
}
void initGraph(struct Graph *g, int vertices)
{
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            g->adj[i][j] = 0; 
        }
    }
}
void addEdge(struct Graph *g, int src, int dest)
{
    g->adj[src][dest] = 1;
    g->adj[dest][src] = 1; 
}
void BFS(struct Graph *g, int start)
{
    struct Queue q;
    initQueue(&q);
    bool visited[MAX] = {false};
    visited[start] = true;
    enqueue(&q, start);
    printf("BFS Traversal starƟng from vertex %d: ", start);
    while (!isEmpty(&q))
    {
        int vertex = dequeue(&q);
        printf("%d ", vertex);
        for (int i = 0; i < g->vertices; i++)
        {
            if (g->adj[vertex][i] == 1 && !visited[i])
            {
                visited[i] = true;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}
int main()
{
    struct Graph g;
    int vertices, edges, src, dest;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initGraph(&g, vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges \n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &src, &dest);
        addEdge(&g, src, dest);
    }
    
    BFS(&g, 0);
    return 0;
}