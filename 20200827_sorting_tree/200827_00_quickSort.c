//
// Created by songe on 2020-08-27.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARY_SIZE (100)
int ary[ARY_SIZE];

void init() {
    for (int i = 0; i < ARY_SIZE; ++i) {
        ary[i] = (i + 1);
    }
    for (int i = 0; i < ARY_SIZE; ++i) {
        for (int j = 0; j < ARY_SIZE; ++j) {
            int r = rand() % ARY_SIZE;
            int temp = ary[0];
            ary[0] = ary[r];
            ary[r] = temp;
        }
    }
}

void print() {
    for (int i = 0; i < ARY_SIZE; ++i) {
        printf("%3d", ary[i]);
        if (i > 0 && (i % 10) == 9) {
            printf("\n");
        }
    }
}

void quickSort(int sIdx, int eIdx) {
    if (sIdx >= eIdx) {
        return;
    } else {
        int i = sIdx -1;
        int j = eIdx;
        while (i<j){
            while (ary[eIdx]>ary[++i]);
            //앞쪽에서 피벗보다 큰값을 검색
            while (ary[eIdx]<ary[--j] && j>sIdx);
            // 뒤쪽에서 피벗보다 작은 값을 검색
            if (i<j){
                int temp = ary[i];
                ary[i]=ary[j];
                ary[j]=temp;
            }
            // i<j라면 두 위치의 값을 교환
        }
        int temp = ary[eIdx];
        ary[eIdx] = ary[i];
        ary[i]=temp;
        //피벗과 i의 값을 교환
        quickSort(sIdx, i-1);
        //i의 값을 기준으로 하여 앞쪽 배열의 원소의 구간을 대상으로 재귀호출
        quickSort(i+1, eIdx);
        // i의 값을 기준으로 하여 뒤쪽 배열 원소의 구간을 대상으로 하여 재귀 호출
    }
}

int main() {
    srand(time(NULL));
    init();
    print();
    printf("\n");
    quickSort(0, ARY_SIZE-1);
    print();
}