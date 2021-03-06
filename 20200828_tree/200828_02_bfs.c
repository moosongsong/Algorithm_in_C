#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX (101)
#define INF (-1)
int AD[MAX][MAX];
int USED[MAX];
int vertex, edge;
int queue[MAX];
int front, rear;

void enQueue(){

}


void init(int n) {
    for (int i = 1; i <= n; ++i) {
        USED[i] = 0;
        for (int j = 1; j <= n; ++j) {
            if (i == j) {
                AD[i][j] = 0;
            } else {
                AD[i][j] = INF;
            }
        }
    }
}

void print(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%2d ", AD[i][j]);
        }
        printf("\n");
    }
}

void create(int e) {
    for (int i = 0; i < e; ++i) {
        int to, from;
        scanf("%d %d", &to, &from);
        AD[to][from] = 1;
        AD[from][to] = 1;
    }
}

void bfs(int n) {
    front = -1;
    rear = -1;
    for (int i = 1; i <= vertex; ++i) {
        USED[i]=0;
    }
    USED[n] = 1;
    queue[++rear] = n;
    while (front != rear){
        int u = queue[++front];
        printf("%d ", u);
        for (int i = 1; i <=vertex; ++i) {
            if (AD[u][i] == 1 && USED[i] == 0){
                USED[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    freopen("C:\\project\\test\\Algorithm_in_C\\20200828_tree\\200828_01_data.txt", "r", stdin);
    scanf("%d %d", &vertex, &edge);
    init(vertex);
    create(edge);
    print(vertex);
    bfs(1);

    return 0;
}