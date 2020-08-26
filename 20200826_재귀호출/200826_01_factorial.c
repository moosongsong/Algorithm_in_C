//
// Created by songe on 2020-08-26.
//
#include <stdio.h>

#define MAX 11
unsigned long long fact[MAX] = {[0]=1};

int main() {
    for (int i = 0; i < MAX; ++i) {
        fact[i] = i*fact[i-1];
    }
    printf("%I64u", fact[MAX-1]);
    return 0;
}