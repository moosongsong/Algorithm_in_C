#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int array[MAX] = {0};
int main() {
    freopen("C:\\Users\\songe\\DataStructure_in_CLion\\untitled1\\200825_00_data.txt", "r", stdin);
    int cnt;
    scanf("%d", &cnt);

    int* ary = calloc(sizeof(int), cnt);

    for (int j = 0; j < cnt; ++j) {
        char ch;
        scanf(" %c", &ch);
        ary[j] = ch-'0';
    }
    int zero_start = 0;
    int find_start = 1;

    while (1){
        if (ary[find_start] == 1 && ary[zero_start] == 0){
            int temp = ary[find_start];
            ary[find_start] = ary[zero_start];
            ary[zero_start] = temp;
            zero_start++;
            find_start++;
        }else if (ary[find_start] == 0 && ary[zero_start] == 0){
            find_start++;
        } else if (ary[zero_start]==1){
            zero_start++;
        }

        if (find_start == cnt){
            break;
        }
    }

    for (int i = 0; i < cnt; ++i) {
        printf("%d ", ary[i]);
    }

    free(ary);
//    int a = -1;
//    int b = cnt;
//    while (a<b){
//        while (ary[++a] != 0);
//        while (ary[--b] != 1);
//        if (a<b){
//            int temp = ary[a];
//            ary[a] = ary[b];
//            ary[b]=temp;
//        }
//    }
    return 0;
}
