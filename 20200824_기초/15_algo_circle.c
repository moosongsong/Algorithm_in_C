//
// Created by songe on 2020-08-24.
//

//9 6
//2 3 4 5 6 7 8 9 1
//1 2 3 4 5 6
#include <stdio.h>
#define MAX 100
int a[MAX];
int b[MAX];
int acnt, bcnt;

void clock(int *ap, int size,int cnt){

    for (int j = 0; j < cnt; ++j) {
        int temp = ap[0];
        for (int i = 0; i < (size-1); ++i) {
            ap[i] = ap[i+1];
        }
        ap[size-1]=temp;
    }
}

void clock2(int *ap, int size, int cnt){

}

void unclock(int *ap, int size, int cnt){

    for (int i = 0; i < cnt; ++i) {
        int temp = ap[size-1];
        for (int j = (size - 1); j >0; j--) {
            ap[i] == ap[i-1];
        }
        ap[0]=temp;
    }
}

void cu

int main(){
    freopen("C:\\project\\algorithm\\data.txt", "r", stdin);
    scanf("%d %d", &acnt, &bcnt);

    for (int i = 0; i < acnt; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < bcnt; ++i) {
        scanf("%d", &b[i]);
    }

    unclock(b, bcnt, (acnt*1)%bcnt);
    clock(a, acnt, (bcnt*2)%acnt);

    for (int i = 0; i < acnt; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < bcnt; ++i) {
        printf("%d ", b[i]);
    }

    return 0;
}