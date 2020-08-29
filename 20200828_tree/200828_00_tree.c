#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
int min = INT32_MAX;
int R[3];
int L[3];
void nCk(int n, int k, int * array, int totalTime){
    if (k==0){
        int result = 0;
        for (int i = 0; i < 3; ++i) {
            result = result+L[i];
        }
        if (result <= totalTime && result < min){
//            for (int i = 0; i < 3; ++i) {
//                printf("%d ", L[i]);
//            }
//            printf("\n%d\n", result);
            min=result;
            for (int i = 0; i < 3; ++i) {
                R[i] = L[i];
            }
        }
    }else if(n<k){
        return;
    }else{
        L[k-1] = array[n-1];
        nCk(n-1, k-1, array, totalTime);
        nCk(n-1, k, array, totalTime);
    }
}
int main() {
    freopen("C:\\project\\Algorithm_in_C\\20200828_tree\\200828_00_data.txt", "r", stdin);
    int promise, out, count;
    scanf("%d %d %d", &promise, &out, &count);

    int *array = calloc(sizeof(int), count);
    for (int i = 0; i < count; ++i) {
        scanf("%d", &array[i]);
    }

    int totalTime = (promise-out)*60;
    nCk(8,3, array, totalTime);

    printf("%d %d %d %d\n", R[0], R[1], R[2], min);

    free(array);
    return 0;
}