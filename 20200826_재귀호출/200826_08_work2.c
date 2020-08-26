//
// Created by songe on 2020-08-26.
//
#include <stdio.h>
#include <stdint.h>
#define MAX 10
int N[MAX][MAX];
int L[3];
int U[3];
int minV = INT32_MAX;

void f(int n, int k){
    if (n==k){
        int time = 0;
        for (int i = 0; i < k; ++i) {
            time += N[i][L[i]-1];
        }
        if (time < minV){
            minV = time;
        }
    }else{
        for (int i = 0; i < k; ++i) {
            if (U[i]==0){
                U[i]=1;
                L[i]=i+1;
                f(n+1, k);
                U[i]=0;
            }
        }
    }
}

int main(){
    freopen("data.txt", "r", stdin);
    int job = 0;
    scanf("%d", &job);
    for (int i = 0; i < job; ++i) {
        for (int j = 0; j < job; ++j) {
            scanf("%d",&N[i][j]);
        }
    }
    f(0, job);
    printf("%d", minV);
    return 0;
}