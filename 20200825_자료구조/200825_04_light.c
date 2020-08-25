//
// Created by songe on 2020-08-25.
//
#include <stdio.h>
#include <stdlib.h>
int main(){
    freopen("C:\\Users\\songe\\DataStructure_in_CLion\\untitled1\\200825_04_data.txt", "r", stdin);
    int count;
    scanf("%d", &count);

    int * ary = calloc(sizeof(int), count);

    for (int j = 0; j < count; ++j) {
        char ch;
        scanf(" %c", &ch);
        ary[j]=ch-'0';
    }

    for (int i = 0; i < count; ++i) {
        printf("%d ", ary[i]);
    }

    int max=0;
    int max_start=0;
    int max_end=0;

    for (int k = 0; k < count-1; ++k) {
        int temp = 0;
        for (int i = k; i < count-1; ++i) {
            if (ary[i] != ary[i+1]){
                temp++;
            }else{
                if (temp>max){
                    max=temp;
                    max_start=k;
                    max_end=i;
                }
                break;
            }
        }
    }
    printf("\n%d, %d, %d\n", max, max_start, max_end);

    for (int l = max_start; l <= max_end; ++l) {
        if (ary[l]==0){
            ary[l]=1;
        }else if (ary[l]==1){
            ary[l]=0;
        }
    }
    for (int k = 0; k < count-1; ++k) {
        int temp = 0;
        for (int i = k; i < count-1; ++i) {
            if (ary[i] != ary[i+1]){
                temp++;
            }else{
                if (temp>max){
                    max=temp;
                    max_start=k;
                    max_end=i;
                }
                break;
            }
        }
    }
    printf("\n%d, %d, %d\n", max, max_start, max_end);

    free(ary);

    return 0;
}
