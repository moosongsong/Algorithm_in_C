//
// Created by songe on 2020-08-27.
//
#include <stdio.h>
#include <stdlib.h>

int findRoot(int *nodes, int count, int starter) {
    int parent = 0;
    while (parent != nodes[parent]) {
        parent = nodes[starter];
        starter = parent;
    }
}

void printNodes(int *nodes, int count) {
    for (int i = 1; i <= count; ++i) {
        printf("%d ", nodes[i]);
    }
}

int getGroup(int *result, int count) {
    int cnt = 0;
    for (int i = 1; i <= count; ++i) {
        if (result[i] == i) {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    int count;
    int start;
    int dest;
    freopen("C:\\project\\Algorithm_in_C\\20200827_sorting_tree\\200827_05_data.txt", "r", stdin);
    scanf("%d", &count);
    scanf("%d", &start);
    scanf("%d", &dest);

    int root_start = start;
    int root_dest = dest;
    int cnt = 0;
    while (root_start != root_dest){
        if (root_start>root_dest){
            root_start/=2;
        }
        if (root_start<root_dest){
            root_dest/=2;
        }
        cnt++;
    }

    printf("%d %d %d %d \n", count, start, dest, cnt);


    return 0;
}