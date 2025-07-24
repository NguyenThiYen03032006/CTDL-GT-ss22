#include <stdio.h>

int count(int graph[5][5]) {
    int count = 0;
    for (int i=0;i<5;i++) {
        for (int j=5-1-i;j>0;j--) {
            if (graph[i][j]==1) {
                count ++;
            }
        }
    }
    return count;
}

int checkGraph(int graph[5][5]) {
    int check=0;
    for (int i=0;i<5;i++) {
        for (int j=0;j<5;j++) {
            if (graph[i][j]!=graph[j][i]) {
                check=1;
            }

        }
    }
    return check;
}
int main(void) {
    int graph1[5][5]={
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,1,0},
        {0,1,1,0,1},
        {0,0,0,1,0}
    };
    if (checkGraph(graph1)==1) {
        printf("Khong phai do thi vo huong\n");
    }else {
        printf("%d\n",count(graph1));
    }

    return 0;
}