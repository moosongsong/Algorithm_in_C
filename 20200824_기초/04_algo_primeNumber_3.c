#include <stdio.h>
//n의 1승부터 M승 까지 출력하는 프로그램을 작성하세요.
int func(int n, int m);

int main(){
    int n = 2;
    int m = 3;
    printf("%d", func(n,m));
    return 0;
}

int func(int n, int m){
    int result = n;
    for (int i = 1; i < m; ++i) {
        result = result*n;
    }
    return result;
}