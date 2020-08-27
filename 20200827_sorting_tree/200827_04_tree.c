//
// Created by songe on 2020-08-27.
//
#include <stdio.h>
#include <stdlib.h>

int findRoot(int * nodes, int count, int starter){
    int parent = 0;
    while (parent != nodes[parent]){
        parent = nodes[starter];
        starter = parent;
    }
}

void printNodes(int * nodes, int count){
    for (int i = 1; i <= count; ++i) {
        printf("%d ", nodes[i]);
    }
}

int getGroup(int * result, int count){
    int cnt = 0;
    for (int i = 1; i <= count; ++i) {
        if (result[i] == i){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int count;
    int edge;
    freopen("C:\\project\\Algorithm_in_C\\20200827_sorting_tree\\200827_04_data.txt", "r", stdin);
    scanf("%d", &count);
    scanf("%d", &edge);

    int *nodes = calloc(sizeof(int), count+1);
    nodes[0]=-1;
    int parent = 0;
    int child = 0;
    while (1){
        scanf("%d %d", &parent, &child);
        nodes[child]=parent;
        if (child == count){
            break;
        }
    }
    for (int i = 1; i <= count; ++i) {
        if (nodes[i]==0){
            nodes[i]=i;
        }
    }


    int * result = calloc(sizeof(int), count+1);

    for (int i = 1; i <=count ; ++i) {
        result[i] = findRoot(nodes, count, i);
    }

    printNodes(nodes, count);
    printf("\n");
    printNodes(result, count);
    printf("\n그룹 개수 : %d", getGroup(result, count));

    free(nodes);
    free(result);

    return 0;
}