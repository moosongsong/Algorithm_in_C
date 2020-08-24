//
// Created by songe on 2020-08-24.
// N의 값이 주어질 댸 각자리의 값을 출력하는 프로그램을 작성하세요.
#include <stdio.h>
int getTotalCount(int temp);
int main(){
    int n = 512;
    int totalCount = getTotalCount(n);
    int temp = 1;
    for (int i = 1; i < totalCount; ++i) {
        temp = temp * 10;
    }

    for (int i = 1; i < totalCount; ++i) {
        printf("%d\n", n/temp);
        n = n%temp;
        temp = temp /10;
    }
    printf("%d\n", n);
    return 0;
}

int getTotalCount(int temp){
    int count = 1;
    while (1){
        temp = temp /10;
        if (temp!=0){
            count++;
        }else{
            break;
        }
    }
    return count;
}