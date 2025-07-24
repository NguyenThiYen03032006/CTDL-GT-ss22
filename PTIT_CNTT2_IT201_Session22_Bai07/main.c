#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int v, e;
void addEdge(int u, int w) {
    graph[u][w] = 1;
    graph[w][u] = 1;
}

void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}
int isEmpty() {
    return (front == -1 || front > rear);
}
void BFS(int start) {
    visited[start] = 1;
    enqueue(start);

    printf("Duyet BFS tu dinh %d: ", start);

    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);

        for (int i = 0; i < v; i++) {
            if (graph[u][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &v, &e);

    if (v <= 0 || v >= MAX || e <= 0 || e >= MAX) {
        printf("Gia tri khong hop le!\n");
        return 1;
    }

    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Nhap danh sach canh (dinh1 dinh2):\n");
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        if (u >= 0 && u < v && w >= 0 && w < v) {
            addEdge(u, w);
        } else {
            printf("Canh khong hop le. Bo qua.\n");
        }
    }

    int start;
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);

    if (start < 0 || start >= v) {
        printf("Dinh bat dau khong hop le!\n");
        return 1;
    }

    BFS(start);

    return 0;
}
