//
// Created by songe on 2020-08-26.
//
#include <stdio.h>

int N[] = {1, 2, 3, 4, 5};
int L[3];

void nck(int n, int k) {
    if (k == 0) {
        for (int i = 0; i < 3; ++i) {
            printf("%d ", L[i]);
        }
        printf("\n");
    } else if (n < k) {
        return;
    } else {
        L[k - 1] = N[n - 1];
        nck(n - 1, k - 1);
        nck(n-1, k);
    }
}

int main() {
    nck(5,3);

    return 0;
}