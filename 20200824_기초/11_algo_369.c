//
// Created by songe on 2020-08-24.
// 369 게임할때 총 몇번 박수 칠까?
#include <stdio.h>
int getCount(int temp);
int main(){
    int n = 40;
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        count = count + getCount(i);
    }
    printf("%d", count);
    return 0;
}

int getCount(int temp){
    int count = 0;
    while (1){
        if ((temp%10)!=0 && (temp % 10)%3 == 0){
            count++;
        }
        temp = temp /10;
        if (temp == 0){
            break;
        }
    }
    return count;
}