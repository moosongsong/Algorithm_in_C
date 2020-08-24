//
// Created by songe on 2020-08-24.
// N의 값이 주어질때 1이상 N이하의 값에서 2승의 값이 N을 초과하지 않는 값을 출력
#include <stdio.h>
int main(){
    int n = 10;
    int i = 1;
    while (1){
        if ((2<<(i-1)) <= n){
            printf("%d ", i++);
        }else{
            break;
        }
    }
    return 0;
}