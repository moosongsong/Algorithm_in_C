#include <stdio.h>

#define MAX (100)
typedef struct _pos {
    int r;
    int c;
} pos_t;

int GRID[MAX][MAX];
int rows, cols;
pos_t QUEUE[MAX * MAX];
int front, rear;

pos_t start;
pos_t end;
pos_t D[] = {{0,  1},
             {0,  -1},
             {1,  0},
             {-1, 0}};

void create(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char ch;
            scanf(" %c", &ch);
            switch (ch) {
                case 'S':
                    start.r = i;
                    start.c = j;
                    GRID[i][j] = 0;
                    break;
                case 'G':
                    start.r = i;
                    start.c = j;
                    GRID[i][j] = -2;
                    break;
                case '#':
                    start.r = i;
                    start.c = j;
                    GRID[i][j] = -1;
                    break;
                case '.':
                    start.r = i;
                    start.c = j;
                    GRID[i][j] = -2;
                    break;
            }
        }
    }
}

void print(int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            switch (GRID[i][j]) {
                case -2:
                    if (i == end.r && j == end.c) {
                        printf("%3c", 'G');
                    } else {
                        printf("%3c", '.');
                    }
                    break;
                case -1:
                    printf("%3c", '#');
                    break;
                case 0:
                    printf("%3c", 'S');
                    break;
                default:
                    printf("%3d", GRID[i][j]);
                    break;
            }
        }
        printf("\n");
    }
}

int cnt = 0;

void dfs(pos_t p) {
    if (p.r == end.r && p.c == end.c) {
        cnt++;
    } else {
        for (int i = 0; i < 4; ++i) {
            pos_t n = {p.r + D[i].r, p.c + D[i].c};
            if (n.r >= 0 && n.r < rows && n.c >= 0 && n.c < cols) {
                if (GRID[n.r][n.c] == -2) {
                    GRID[n.r][n.c] = GRID[p.r][p.c] + 1;
                    dfs(n);
                    GRID[n.r][n.c] = -2;
                }
            }
        }
    }
}

int main() {
    freopen("C:\\project\\test\\Algorithm_in_C\\20200828_tree\\200828_05_data.txt", "r", stdin);
    scanf("%d %d", &rows, &cols);
    create(rows, cols);
    print(rows, cols);
    return 0;
}