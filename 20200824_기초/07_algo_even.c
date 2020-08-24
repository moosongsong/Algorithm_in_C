//
// Created by songe on 2020-08-24.
//

#include <stdio.h>
int getTotalCount(int temp);
int main(){
    int number = 1234;
    int up = 0;
    int down = 0;
    int count = getTotalCount(number);

    int temp = 10;
    for (int i = 1; i < (count / 2); ++i) {
        temp = temp *10;
    }
    up = number/temp;

    temp = 10;
    for (int i = 1; i < count - (count / 2); ++i) {
        temp = temp *10;
    }


    down = number%temp;

    printf("답: %d, %d\n", up, down);
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

int expo(int n, int m){
    int r = 1;
    while (m-- >0){
        r*=n;
    }
    return r;
}