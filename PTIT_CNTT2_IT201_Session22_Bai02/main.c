#include <stdio.h>
#include <stdlib.h>
int n;
typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) {
        printf("Cap phat bo nho that bai\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}
void initGraph(Node* graph[]) {
    for (int i=0; i<n; i++) {
        graph[i] = NULL;
    }
}
void addEdge(Node* graph[], int node1, int node2) {
    Node* newNode1 = createNode(node1);
    newNode1->next = graph[node2];
    graph[node2] = newNode1;

    Node* newNode2 = createNode(node2);
    newNode2->next = graph[node1];
    graph[node1] = newNode2;
}

void printGraph(Node* graph[]) {
    for(int i = 0; i < n; i++) {
        printf("%d :", i);
        Node* node = graph[i];
        while (node != NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}
int main(void) {
    scanf("%d",&n);
    Node* graph[n];
    initGraph(graph);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    return 0;
}