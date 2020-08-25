//
// Created by songe on 2020-08-25.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
void printArray(int ** ary, int row, int col);
int main(){
    freopen("C:\\Users\\songe\\DataStructure_in_CLion\\untitled1\\200825_01_data.txt", "r", stdin);
    int row, col;
    scanf("%d", &row);
    scanf("%d", &col);
    int r, c;
    scanf("%d", &r);
    scanf("%d", &c);

    int** ary = calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        ary[i] = calloc(sizeof(int), col);
    }

    for (int j = 0; j < row; ++j) {
        for (int i = 0; i < col; ++i) {
            scanf("%d", &ary[j][i]);
        }
    }

    int min_value = INT32_MAX;
    int min_row = 0;
    int min_col = 0;

    for (int l = 0; l < row - r + 1; ++l) {
        for (int i = 0; i < col - c + 1; ++i) {
            int result = 0;
            for (int j = 0; j < r; ++j) {
                for (int k = 0; k < c; ++k) {
                    result += ary[l+j][i+k];
                }
            }
            if (result<min_value){
                min_value = result;
                min_row=l;
                min_col=i;
            }
        }
    }

    printArray(ary, row, col);

    for (int m = 0; m < r; ++m) {
        for (int i = 0; i < c; ++i) {
            printf("%d ", ary[min_row+m][min_col+i]);
        }
        printf("\n");
    }
    printf("%d", min_value);

    for (int k = 0; k < row; ++k) {
        free(ary[k]);
    }
    free(ary);

    return 0;
}

void printArray(int ** ary, int row, int col){
    for (int j = 0; j < row; ++j) {
        for (int i = 0; i < col; ++i) {
            printf("%d ", ary[j][i]);
        }
        printf("\n");
    }
}