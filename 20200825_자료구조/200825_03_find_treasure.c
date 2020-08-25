//
// Created by songe on 2020-08-25.
//
#include <stdio.h>
#include <stdlib.h>
void printArray(char ** ary, int row, int col);
int main(){
    freopen("C:\\Users\\songe\\DataStructure_in_CLion\\untitled1\\200825_03_data.txt", "r", stdin);
    int row, col;
    scanf("%d", &row);
    scanf("%d", &col);

    char ** f_ary = calloc(sizeof(char *), row);
    for (int i = 0; i < row; ++i) {
        f_ary[i] = calloc(sizeof(char ), col);
    }
    char ** s_ary = calloc(sizeof(char *), row);
    for (int i = 0; i < row; ++i) {
        s_ary[i] = calloc(sizeof(char ), col);
    }
    char ** r_ary = calloc(sizeof(char *), row);
    for (int i = 0; i < row; ++i) {
        r_ary[i] = calloc(sizeof(char ), col);
    }

    for (int j = 0; j < row; ++j) {
        for (int i = 0; i < col; ++i) {
            scanf(" %c", &f_ary[j][i]);
        }
    }
    for (int j = 0; j < row; ++j) {
        for (int i = 0; i < col; ++i) {
            scanf(" %c", &s_ary[j][i]);
        }
    }

    printArray(f_ary, row, col);
    printArray(s_ary, row, col);

    int count = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (f_ary[i][j] == 'X' && s_ary[i][j]== 'X'){
                r_ary[i][j]='X';
                count++;
            }
            else{
                r_ary[i][j]='O';
            }
        }
    }
    printArray(r_ary, row, col);
    printf("%d\n", count);

    for (int k = 0; k < row; ++k) {
        free(f_ary[k]);
    }
    free(f_ary);
    for (int k = 0; k < row; ++k) {
        free(s_ary[k]);
    }
    free(s_ary);
    for (int k = 0; k < row; ++k) {
        free(r_ary[k]);
    }
    free(r_ary);

    return 0;
}

void printArray(char ** ary, int row, int col){
    for (int j = 0; j < row; ++j) {
        for (int i = 0; i < col; ++i) {
            printf("%c ", ary[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}