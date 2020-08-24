#if 0
#include <stdio.h>
// n 이하의 값 중 소수인 값을 출력하는 프로그램을 작성하세요.
int main(){
    int number = 31;
    int result = 1;
    for (int i = 2; i < number; ++i) {
        for (int j = 2; j < i; ++j) {
            if (i%j==0){
                result = -1;
            }
        }
        if (result == 1){
            printf("%d ", i);
        }else{
            result = 1;
        }
    }

    return 0;
}
#endif

#include <stdio.h>
#define MAX 10000
int ary[MAX];
int N;

int main(){
    freopen("C:\\project\\algorithm\\data.txt", "r", stdin);
    int tc;
    scanf("%d", &tc);
    for (int i = 0; i < tc; ++i) {
        scanf("%d", &N);
        for (int k = 2; k <= N; ++k) {
            for (int j = (k + k); j <= N; j+=j) {
                if (ary[j] == 0){
                    ary[j]=k;
                }
            }
        }
    }
    int cnt = 0;
    for (int i = 2; i <= N; ++i) {
        if (ary[i]==0){
            cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}