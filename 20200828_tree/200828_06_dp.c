#include <stdio.h>

#define MAX (101)
int OG[MAX][MAX];
int DP[MAX][MAX];
int DD[MAX][MAX];
int rows, cols;
int rs[MAX * MAX];
int cs[MAX * MAX];
int top = -1;

void create(int r, int c) {
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            scanf("%d", &OG[i][j]);
        }
    }
}

void print(int r, int c) {
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            printf("%3d ", OG[i][j]);
        }
        printf("\n");
    }
}

void printDP(int r, int c) {
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            printf("%3d ", DP[i][j]);
        }
        printf("\n");
    }
}

void printDD(int r, int c) {
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            printf("%3d ", DD[i][j]);
        }
        printf("\n");
    }
}

void dp(int r, int c) {
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            DP[i][j] = 0;
        }
    }

    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            DP[i][j] = (DP[i - 1][j] > DP[i][j - 1] ? DP[i - 1][j] : DP[i][j - 1]) + OG[i][j];
            if (DP[i - 1][j] > DP[i][j - 1]) { // 위로부터
                DD[i][j] = 1;
            } else if (DP[i - 1][j] < DP[i][j - 1]) { // 좌로부터
                DD[i][j] = 2;
            } else if (DP[i - 1][j] == DP[i][j - 1] && DP[i - 1][j] != 0) { // 노상관
                DD[i][j] = 3;
            }
        }
    }
}

void printPath(int r, int c) {
    while (DD[r][c] != 0){
        ++top;
        rs[top] = r;
        cs[top] = c;
        if (DD[r][c] == 2){
            c--;
        }else if (DD[r][c] == 1){
            r--;
        } else if (DD[r][c] == 3){
            r--;
        }
    }
    printf("%d, %d", 1,1);
    while (top > -1){
        int u = rs[top];
        int v = cs[top];
        top--;
        printf(" >> %d, %d", u, v);
    }
}

int main() {
    freopen("C:\\project\\test\\Algorithm_in_C\\20200828_tree\\200828_06_data.txt", "r", stdin);
    scanf("%d %d", &rows, &cols);
    create(rows, cols);
    print(rows, cols);
    dp(rows, cols);
    printDP(rows, cols);
    printDD(rows, cols);
    printPath(rows, cols);
}