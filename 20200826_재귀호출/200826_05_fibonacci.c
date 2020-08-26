//
// Created by songe on 2020-08-26.
//
#include <stdio.h>
#define MAX 101
long long ar[MAX] = {[0]=0, [1]=1};
int L[3];
int S[3] = {2,5,8};
int D[5] = {1,2,3,4,5};
int f(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return f(n - 1) + f(n - 2);
    }
}

void ff(int n, int k){
    if (n==k){
        for (int i = 0; i < k; ++i) {
            printf("%d ", L[i]);
        }
        printf("\n");
    }else{
        for (int i = 0; i < k; ++i) {
//            L[n]=i+1;
            L[n]=S[i];
            ff(n+1, k);
        }
    }
}

void fff(int n, int k, int c){
    if (n==c){
        for (int i = 0; i < c; ++i) {
            printf("%d ", L[i]);
        }
        printf("\n");
    }else{
        for (int i = 0; i < k; ++i) {
            L[n]=D[i];
            fff(n+1, k, c);
        }
    }
}

int main() {
//    for (int i = 2; i < MAX; ++i) {
//        ar[i] = ar[i-1] + ar[i-2];
//    }
//    printf("%I64d", ar[50]);

//ff(0,3);
    fff(0, 5, 3);
    return 0;
}