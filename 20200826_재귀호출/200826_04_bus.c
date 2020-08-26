//
// Created by songe on 2020-08-26.
//
#include <stdio.h>

int st[5] = {2, 3, 1, 1, 0};
int minV = 4;

void f(int n, int k, int v) {
    if (n >= k) {
        if (v < minV){
            minV = v;
        }
        return;
    }else{
        for (int i = 1; i < (st[n] + 1); ++i) {
            f(n+i, k, v+1);
        }
    }
}

int main() {
    f(0, 4, 0);
    printf("%d", minV-1);
    return 0;
}