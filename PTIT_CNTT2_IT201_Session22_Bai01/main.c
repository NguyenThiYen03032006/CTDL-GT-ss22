#include <stdio.h>

int n;
void initGraph(int graph[n][n],int n) {
    int i, j;
    for (i = 0; i <n; i++) {
        for (j = 0; j <n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int graph[n][n], int node1, int node2) {
    if (node1<0 || node2<0 || node1>n || node2>n) {
        printf("vi tri node khong hop le\n");
        return;
    }
    graph[node1][node2]=1;
    graph[node2][node1]=1;
}

void displayGraph(int graph[n][n], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    scanf("%d", &n);
    int graph[n][n];
    initGraph(graph, n);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 3,2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);
    displayGraph(graph, n);

    return 0;
}