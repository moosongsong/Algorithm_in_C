//
// Created by songe on 2020-08-27.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARY_SIZE (100)
int ary[ARY_SIZE];

typedef struct _pos_{
    int s;
    int e;
} pos_t;
pos_t stack[ARY_SIZE];
int top = -1;

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
    //스텍초기화
    top = -1;
    //스텍에 s,e를 넣었다
    //S<-{s,e}
    pos_t p = {sIdx, eIdx};
    stack[++top] = p;
    while (top>-1){
        pos_t v = stack[top--];
        if (v.s >=v.e)continue;
        int i = v.s -1;
        int j = v.e;

        while (i<j){
            while (ary[v.e]>ary[++i]);
            //앞쪽에서 피벗보다 큰값을 검색
            while (ary[v.e]<ary[--j] && j>v.s);
            // 뒤쪽에서 피벗보다 작은 값을 검색
            if (i<j){
                int temp = ary[i];
                ary[i]=ary[j];
                ary[j]=temp;
            }
            // i<j라면 두 위치의 값을 교환
        }
        int temp = ary[v.e];
        ary[v.e] = ary[i];
        ary[i]=temp;
        //피벗과 i의 값을 교환

        pos_t p1 ={v.s, i-1};
        pos_t p2 ={i+1, v.e};
        stack[++top] = p1;
        stack[++top] = p2;
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