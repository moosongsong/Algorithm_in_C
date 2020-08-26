//
// Created by songe on 2020-08-26.
//
#include <stdio.h>
int src [3] = {};
void f(int n, int k){
    if (n == k){
        for (int i = 0; i < 3; ++i) {
            printf("%d ", src[i]);
        }
        printf("\n");
        return;
    }else{
        src[n] = 0;
        f(n+1, k);
        src[n]=1;
        f(n+1, k);
    }
}
void ff(int n, int k){
    if (n == k){
        for (int i = 0; i < 3; ++i) {
            printf("%d ", src[i]);
        }
        printf("\n");
        return;
    }else{
//        src[n] = 1;
//        ff(n+1, k);
//        src[n]=2;
//        ff(n+1, k);
//        src[n]=3;
//        ff(n+1, k);
        for (int i = 0; i < 3; ++i) {
            src[n]=i;
            ff(n+1, k);
        }
    }
}
int main(){
    f(0, 3);
    ff(0, 3);
    return 0;
}