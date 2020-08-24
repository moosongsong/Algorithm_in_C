//
// Created by songe on 2020-08-24.
//달팽이 나선 배열
#include <stdio.h>
#define MAX 7

int main(){
    int num = 0;
    int ary[MAX][MAX]={0,};
    int n = MAX;

    for (int i = 0; i < (n / 2); ++i) {
        for (int j = i; j < (n - i - 1); ++j) {
            ary[i][j]=++num;
        }
        for (int j = i; j < (n - i - 1); ++j) {
            ary[j][n-i-1]=++num;
        }
        for (int j = (n-i-1); j > i; j--) {
            ary[n-i-1][j]=++num;
        }
        for (int j = (n-i-1); j > i; j--) {
            ary[j][i]=++num;
        }
    }

    if ((n%2)!=0){
        ary[(n/2)][(n/2)]=++num;
    }
    

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%2d ", ary[i][j]);
        }
        printf("\n");
    }

    int slash = 0; // /
    int obil = 0; //

    for (int i = 0; i < n; ++i) {
        slash += ary[i][i];
    }

    for (int i = 0; i < n; ++i) {
        obil += ary[i][n-i-1];
    }

    printf("\n정방 : %d, 역방 : %d\n", slash, obil);

    return 0;
}
