#include <stdio.h>

#define MAX 10
int scr[MAX] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int dest[MAX];

void f(int n, int k) {
    if (n == k) {
        return;
    } else {
        printf("%d ", n);
        f(n + 1, k);
    }
}

void ff(int n, int k) {
    if (n == k) {
        return;
    } else {
        printf("%d ", n);
        ff(n - 1, k);
    }
}

void fff(int n, int k) {
    if (n == k) {
        return;
    } else {
        fff(n + 1, k);
        printf("%d ", n);
    }
}

void ffff(int n, int k) {
    if (n >= k) {
        return;
    }
    if (n % 2 == 0) {
        ffff(n + 1, k);
    } else {
        printf("%d ", n);
        ffff(n + 2, k);
    }
}

void copy(int n, int k) {
    if (n >= k) {
        for (int i = 0; i < MAX; ++i) {
            printf("%d ", dest[i]);
        }
    } else {
        dest[n] = scr[n];
        copy(n + 1, k);
    }
}

int find(int n, int k, int findNum) {
    if (n >= k) {
        return -1;
    } else if (scr[n] == findNum) {
        return n;
    } else {
        return find(n + 1, k, findNum);
    }
}

long long factorial(int n){
    if (n == 0){
        return 1;
    }else{
        return n * factorial(n-1);
    }
}

int main() {
//    f(0, 10);
//    fff(0, 10);
//    ff(9,0);
//    ffff(0, 100);

//    copy(0, 10);

//    printf("%d", find(0, 10, 11));

    printf("%d",factorial(4));
    return 0;
}