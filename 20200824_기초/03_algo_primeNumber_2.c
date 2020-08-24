#include <stdio.h>
// 2의 1승부터 N승 까지 출력하는 프로그램을 작성하세요.
int main(){
    int number = 10;
    int result = 2;
    for (int i = 1; i <= number; ++i) {
        printf("%d ", result<<(i-1));
    }

    return 0;
}
