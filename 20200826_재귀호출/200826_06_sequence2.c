//
// Created by songe on 2020-08-26.
//
#include <stdio.h>

int N[] = {2, 3, 4};
int L[3];
int U[3];

void f(int n, int k) {
    if (n == k) {
        for (int i = 0; i < k; ++i) {
            printf("%d ", L[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < k; ++i) {
            if (U[i]==0){
                U[i]=1;
                L[n] = N[i];
                f(n + 1, k);
                U[i]=0;
            }
        }
    }
}

int main() {
    f(0, 3);
    return 0;
}