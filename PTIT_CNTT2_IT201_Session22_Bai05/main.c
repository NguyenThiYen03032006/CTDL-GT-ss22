#include <stdio.h>
int n,m;
void initGraph(int graph[n][n]) {
    for (int i=0;i<n;i++) {
        graph[i][i] = 0;
    }
}
void addEdge(int graph[n][n], int node1,int node2) {
    if (node1<0 || node2<0 || node1>n || node2>n) {
        printf("vi tri node khong hop le\n");
        return;
    }
    graph[node1][node2]=1;
    graph[node2][node1]=1;
}
int check(int graph[n][n], int k) {
    int count=0;
    for (int i=0;i<n;i++) {
        if (graph[k][i]==1) {
            count++;
        }
    }
    return count;
}
int main(void) {

    printf("Nhap vao so dinh va so canh: ");
    scanf("%d %d",&n,&m);
    int graph[n][n];
    printf("Nhap cac canh: ");
    for (int i=0;i<m;i++) {
        int node1,node2;
        scanf("%d %d",&node1,&node2);
        addEdge(graph,node1, node2);
    }
    int k;
    printf("Nhap dinh muon ktra: ");
    scanf("%d",&k);

    printf("So dinh ke voi %d la: %d", k, check(graph, k));
    return 0;
}