//
// Created by songe on 2020-08-26.
//
#include <stdio.h>
#include <stdint.h>
#define MAX (5)
#define MEMBER (3)
int U[MEMBER+1] = {0};
int L[MEMBER+1] = {0};
int minValue = INT32_MAX;
int map[MAX + 1][MAX + 1] = {0};
int distance[MEMBER + 1][MEMBER + 1] = {0};
int member[4][2] = {{1, 1},
                    {1, 4},
                    {3, 1},
                    {5, 3}};
int res_ary[MEMBER+1]={0};
void f(int n, int k) {
    if (k == n) {
        int result = 0;
        for (int i = 1; i <k; ++i) {
            result += distance[L[i-1]][L[i]];
        }
        if (result<minValue){
            minValue=result;
            if (L[0]==0){
                for (int i = 0; i < k; ++i) {
                    res_ary[i] = L[i];
                }
            }
        }
    } else {
        for (int i = 0; i < k; ++i) {
            if (U[i] == 0){
                U[i]=1;
                L[n]=i;
                f(n+1, k);
                U[i]=0;
            }
        }
    }
}

int main() {
    for (int i = 0; i <= MEMBER; ++i) {
        map[member[i][0]][member[i][1]] = 1;
    }

//    for (int i = 1; i <= MAX; ++i) {
//        for (int j = 1; j <= MAX; ++j) {
//            printf("%d ", map[i][j]);
//        }
//        printf("\n");
//    }

    for (int i = 0; i <= MEMBER; ++i) {//main
        for (int j = 0; j <= MEMBER; ++j) {//sub
            int temp1 = member[i][0]-member[j][0];
            int temp2 = member[i][1]-member[j][1];
            if (temp1 < 0){
                temp1 = temp1*(-1);
            }
            if (temp2 < 0){
                temp2 = temp2*(-1);
            }
            distance[i][j] = temp1+temp2;
        }
    }

    printf("\n");
//    for (int i = 0; i <= MEMBER; ++i) {
//        for (int j = 0; j <= MEMBER; ++j) {
//            printf("%d ", distance[i][j]);
//        }
//        printf("\n");
//    }

    f(0, MEMBER+1);
//    printf("%d", minValue);
    for (int i = 0; i < MEMBER+1; ++i) {
        printf("%d ", res_ary[i]);
    }

    return 0;
}