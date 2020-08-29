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

void bfs(pos_t p) {
    front = -1;
    rear = -1;
    QUEUE[++rear] = p;

    while (front < rear) {
        pos_t u = QUEUE[++front];
        for (int i = 0; i < 4; ++i) {
            pos_t n = {u.r + D[i].r, u.c + D[i].c};
            if (n.r >= 0 && n.r < rows && n.c >= 0 && n.c < cols && GRID[n.r][n.c] == -2) {
                GRID[n.r][n.c] = GRID[u.r][u.c] + 1;
                QUEUE[++front] = n;
            }
        }
    }
}

int main() {
    freopen("C:\\project\\test\\Algorithm_in_C\\20200828_tree\\200828_04_data.txt", "r", stdin);
    scanf("%d %d", &rows, &cols);
    create(rows, cols);
    print(rows, cols);
    bfs(start);
    printf("\n");
    print(rows, cols);
    printf("%d\n", GRID[end.r][end.c]);
    return 0;
}