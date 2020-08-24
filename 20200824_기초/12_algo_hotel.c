//
// Created by songe on 2020-08-24.
// A호텔의 요금은 3일동안 숙박할 수 있는 기간요금n과 당일 하루만 숙박할 수 있는 일일 요금 M이 있습니다.
// 가장 저렴하게 10일 동안 투숙할 수 있는 요금을 구하는 프로그램을 작성하세요.
// 10 투숙예정일수 3 기간일수 3000기간요금 900 일일 요금
#include <stdio.h>
int main(){
    int totalDay = 10;
    int day_ticket = 1100;
//    int day_ticket = 900;
    int days_ticket = 3000;
    int days = 3;
    int totalFee = 0;

    if (days*day_ticket > days_ticket){
        totalFee = (totalDay/days)*days_ticket;
        totalFee += (totalDay%days)*day_ticket;
    }else{
        totalFee = totalDay*day_ticket;
    }
    printf("답 : %d", totalFee);

    return 0;
}