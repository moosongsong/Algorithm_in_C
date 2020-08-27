//
// Created by songe on 2020-08-27.
//
#include <stdio.h>

#define MAX (100)
int c1[4]; //부모를 인덱스로 하여 왼쪽 자식을 저장
int c2[4]; //부모를 인덱스로 하여 오른쪽 자식을 저장
int pt[MAX];
int edge;

int top;
int stack[MAX];

void initStack(int n){
    top = -1;
    stack[++top] = n;
    while (top>-1){
        int v = stack[top--];
        printf("%d ", v);
        if (c1[v] != 0){
            stack[++top] = c1[v];
        }
        if (c2[v] != 0){
            stack[++top] = c2[v];
        }
    }
}

int main() {
    freopen("C:\\project\\Algorithm_in_C\\20200827_sorting_tree\\200827_02_data.txt", "r", stdin);
    scanf("%d", &edge);
    for (int i = 0; i < edge; ++i) {
        int p, c;
        scanf("%d %d", &p, &c);
        if (c1[p] == 0) {
            c1[p] = c;
        } else {
            c2[p] = c;
        }
        pt[c] = p;
    }

//    printf("%d", edge);
    for (int i = 0; i < 10; ++i) {
        printf("%d ", c1[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", c2[i]);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        printf("%d ", pt[i]);
    }
    initStack(5);

    return 0;
}