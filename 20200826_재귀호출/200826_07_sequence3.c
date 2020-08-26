//
// Created by songe on 2020-08-26.
//
#include <stdio.h>

int N[] = {1, 2, 3, 4, 5};
int L[3];
int U[5];

void f(int n, int k, int t) {
    if (n == k) {
        for (int i = 0; i < k; ++i) {
            printf("%d ", L[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < t; ++i) {
            if (U[i]==0){
                U[i]=1;
                L[n] = N[i];
                f(n + 1, k, t);
                U[i]=0;
            }
        }
    }
}

int main() {
    f(0, 3, 5);
    return 0;
}