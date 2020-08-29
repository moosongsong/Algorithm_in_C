#include <stdio.h>

#define MAX (100)
int G[MAX][MAX];
int size;
int CNT[MAX * MAX / 2] = {0,};

typedef struct _pos {
    int r;
    int c;
} pos_t;
int c = 0;

//int rq[MAX * MAX];// 행번호 저장
//int cq[MAX * MAX];// 열번호 저장
pos_t Q[MAX * MAX];
int front, rear;
pos_t D[] = {{0,  1},
             {0,  -1},
             {1,  0},
             {-1, 0}};

void init(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            G[i][j] = 0;
        }
    }
}

void print(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", G[i][j]);
        }
        printf("\n");
    }
}

void create(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &G[i][j]);
        }
    }
}

void bfs(pos_t s, int mark) {
    front = -1;
    rear = -1;

    Q[++rear] = s;
    G[s.r][s.c] = mark;

    while (front < rear) {
        pos_t u = Q[++front];
        for (int i = 0; i < 4; ++i) {
            pos_t n = {u.r + D[i].r, u.c + D[i].c};
            if (n.r >= 0 && n.r < size && n.c >= 0 && n.c < size) {
                if (G[n.r][n.c] == 1) {
                    G[n.r][n.c] = mark;
                    Q[++rear] = n;
                }
            }
        }
    }
}

void getCaveCount(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            CNT[G[i][j]]++;
        }
    }
}

int getCount(int n){
    for (int i = 1; i <= n; ++i) {
        if (CNT[i] > 0){
            c++;
        }
    }
    return c;
}

int main() {
    freopen("C:\\project\\test\\Algorithm_in_C\\20200828_tree\\200828_03_data.txt", "r", stdin);
    scanf("%d", &size);
    init(size);
    create(size);
//    print(size);

    int cnt = 1;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (G[i][j] == 1) {
                pos_t s = {i, j};
                bfs(s, ++cnt);
            }
        }
    }

    print(size);
    getCaveCount(size);
    for (int i = 1; i <= size; ++i) {
        printf("%d ", CNT[i]);
    }
    getCount(size);
    printf("\n%d\n", c);
    return 0;
}