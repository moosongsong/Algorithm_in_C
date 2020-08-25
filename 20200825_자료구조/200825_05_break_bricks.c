//
// Created by songe on 2020-08-25.
//
#include <stdio.h>
#include <stdlib.h>
void printArray(int ** ary, int row, int col);
int search(int ** ary, int ** r_ary, int row, int col);
void delete(int ** ary, int ** r_ary, int row, int col);

int main(){
    freopen("C:\\Users\\songe\\DataStructure_in_CLion\\untitled1\\200825_05_data.txt", "r", stdin);
    int row, col;
    scanf("%d %d", &row, &col);

    int ** ary = calloc(sizeof(int*), row);
    for (int i = 0; i < row ; ++i) {
        ary[i] = calloc(sizeof(int), col);
    }

    int ** r_ary = calloc(sizeof(int*), row);
    for (int m = 0; m < row; ++m) {
        r_ary[m] = calloc(sizeof(int), col);
    }

    for (int j = 0; j < row; ++j) {
        for (int i = 0; i < col; ++i) {
            scanf("%d", &ary[j][i]);
        }
    }


    int totalCount = 0;


    while (1){
        printArray(ary, row, col);
        int count = 0;
        count = search(ary, r_ary, row, col);
        if (count == 0){
            break;
        }
        totalCount+=count;
        printArray(r_ary, row, col);
        printf("삭제될 개수 : %d\n", count);
        delete(ary, r_ary, row, col);
    }


    for (int k = 0; k < row; ++k) {
        free(ary[k]);
    }
    free(ary);
    for (int k = 0; k < row; ++k) {
        free(r_ary[k]);
    }
    free(r_ary);

    return 0;
}

void printArray(int ** ary, int row, int col){
    for (int j = 0; j < row; ++j) {
        for (int i = 0; i < col; ++i) {
            printf("%d ", ary[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

//void sort(int ** ary, int row, int col){
//    for (int i = 0; i < row; ++i) {
//        int start = -1;
//        int end = -1;
//        while (row > end){
//            while (++s < r && ary[++start] != 0);
//            while (++e < r && ary[++end] ==0);
//            if (end<row && start<row){
//                int tempt = ary[start][i];
//                ary[start][i] = ary[end][i];
//            }
//        }
//    }
//}

void sort(int ** ary, int row, int col){
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            if (ary[j][i] == 0){
                for (int k = 0; k < j; ++k) {

                }
            }
        }
    }
}

int search(int ** ary, int ** r_ary, int row, int col){
    int count = 0;

    for (int l = 0; l < row - 1; ++l) {
        for (int i = 0; i < col - 1; ++i) {
            if ( (ary[l][i] == ary[l][i+1])
                 && (ary[l][i] == ary[l+1][i])
                 && (ary[l][i] == ary[l+1][i+1])){
                r_ary[l][i]=1;
                r_ary[l][i+1]=1;
                r_ary[l+1][i]=1;
                r_ary[l+1][i+1]=1;
            }
        }
    }

    for (int j = 0; j < row; ++j) {
        for (int i = 0; i < col; ++i) {
            printf("%d ", r_ary[j][i]);
            if (r_ary[j][i] == 1){
                count++;
            }
        }
        printf("\n");
    }
    return count;
}

void delete(int ** ary, int ** r_ary, int row, int col){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (r_ary[i][j]==1){
                ary[i][j] = 0;
            }
        }
    }
}