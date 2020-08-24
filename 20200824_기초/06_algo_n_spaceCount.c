//
// Created by songe on 2020-08-24.
//

#include<stdio.h>

int main(){
    int n = 1000;
    int temp = n;
    int count = 1;
    while (1){
        temp = temp /10;
        if (temp!=0){
            count++;
        }else{
            break;
        }
    }
    printf("%d", count);
}