//
// Created by songe on 2020-08-24.
//
#include <stdio.h>
int main(){
    int temp = 3;
    int student = 8;
    int fan = 2;
    int newFan;

    newFan = student/temp;
    if (student%temp != 0){
        newFan+=1;
    }

    if (newFan == fan){
        printf("no\n");
    }
    else{
        printf("yes\n");
    }

    return 0;
}
