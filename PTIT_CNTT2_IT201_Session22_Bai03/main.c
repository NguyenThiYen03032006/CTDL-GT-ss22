#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* creatNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) {
        printf("Cap phat o nho that bai\n");
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}
void addEdge(Node* graph[], int node1, int node2) {
    Node* newNode1 = creatNode(node1);
    newNode1->next = graph[node2];
    graph[node2] = newNode1;

}

void display(Node* graph[]) {
    for (int i=0;i<5; i++) {
        Node* node = graph[i];
        printf("%d: ",i);
        while (node != NULL) {
            printf("%d->",node->data);
            node = node->next;
        }
        printf("NULL\n");
    }
}
int main(void) {
    int graph1[5][5]={
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,1,0},
        {0,1,1,0,1},
        {0,0,0,1,0}
    };
    Node* graph2[5]={NULL};
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            if (graph1[i][j]==1) {
                addEdge(graph2,i,j);
            }
        }
    }
    display(graph2);
    return 0;
}