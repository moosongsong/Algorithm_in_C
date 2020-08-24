#include <stdio.h>
#define MAX 100
int ary[MAX]; // 정수를 저장하기 위한 공간
int cnt; // 읽어들일 정수의 수

int main() {
    freopen("C:\\project\\algorithm\\data.txt", "r", stdin);
    scanf("%d", &cnt);
    for (int i = 0; i < cnt; ++i) {
        scanf("%d", &ary[i]);
    }
    for (int i = 0; i < cnt; ++i) {
        printf("%d ", ary[i]);
    }
    return 0;
}
