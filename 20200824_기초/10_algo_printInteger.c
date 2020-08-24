//
// Created by songe on 2020-08-24.
// 1부터 10까지의 값을 아래의 순서로 출력하는 프로그램을 작성하세용.
// 1 10 2 9 3 8 4 7 5 6
#include <stdio.h>
int main(){
    int n = 11;
    for (int i = 1; i <= n/2; ++i) {
        printf("%d %d ", i, n-i+1);
    }
    if (n%2 != 0){
        printf("%d", n/2+1);
    }

    return 0;
}