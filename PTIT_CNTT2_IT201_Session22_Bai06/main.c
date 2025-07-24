#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int v, e;

void addEdge(int u, int w) {
    graph[u][w] = 1;
    graph[w][u] = 1;
}

void DFS(int u) {
    printf("%d ", u);
    visited[u] = 1;

    for (int i = 0; i < v; i++) {
        if (graph[u][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &v, &e);

    if (v <= 0 || v >= 100 || e <= 0 || e >= 100) {
        printf("Gia tri khong hop le!\n");
        return 1;
    }
    for (int i = 0; i < v; i++) {
        visited[i] = 0;
        for (int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }
    printf("Nhap %d canh:\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        printf("\n");
        if (u >= 0 && u < v && w >= 0 && w < v) {
            addEdge(u, w);
        } else {
            printf("Canh khong hop le. Bo qua.\n");
        }
    }
    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);

    if (start < 0 || start >= v) {
        printf("Dinh bat dau khong hop le!\n");
        return 1;
    }

    printf("Cac dinh duoc duyet theo DFS bat dau tu %d: ", start);
    DFS(start);
    printf("\n");

    return 0;
}
