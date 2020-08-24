//
// Created by songe on 2020-08-24.
//
#include <stdio.h>
#define MAX 6

int main(){
//    freopen("C:\\project\\algorithm\\data.txt", "r", stdin);
//    scanf("%d", &n);

    int ary[MAX][MAX]={0,};
    int n = MAX;
    int temp = 0;

//    for (int i = 0; i < n; ++i) {
//        ary[i][i]=++temp;
//    }
//    for (int i = 0; i < n-1; ++i) {
//        ary[i][i+1]=++temp;
//    }
//    for (int i = 0; i < n - 2; ++i) {
//        ary[i][i+2]=++temp;
//    }
//    for (int i = 0; i < n - 3; ++i) {
//        ary[i][i+3]=++temp;
//    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            ary[j][j+i]=++temp;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d ", ary[i][j]);
        }
        printf("\n");
    }

    return 0;
}