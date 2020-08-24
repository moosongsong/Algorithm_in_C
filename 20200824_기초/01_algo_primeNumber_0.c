#include <stdio.h>
//n의 값이 소수이면 1, 소수가 아니면, -1을 출력하는 프로그램을 작성하세요.
int main(){
    int number = 31;
    int result = 1;
    for (int i = 2; i < number; ++i) {
        if (number%i==0){
            result = -1;
        }
    }

    printf("%d", result);
    return 0;
}