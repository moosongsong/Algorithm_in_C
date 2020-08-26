//
// Created by songe on 2020-08-26.
//
#include <stdio.h>
#define MAX 4
int ary[MAX]={0};
void f(int n, int k){
    if (n==k){
        printf("{");
        for (int i = 0; i < MAX; ++i) {
            if (ary[i] == 1){
                printf("%d ", i+1);
            }

        }
        printf("\b}\n");
    }else{
        for (int i = 0; i < 2; ++i) {
            ary[n]=i;
            f(n+1, k);
        }
    }
}
int main(){
    f(0, MAX);
    return 0;
}