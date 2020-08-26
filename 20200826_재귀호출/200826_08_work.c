//
// Created by songe on 2020-08-26.
//
#include <stdio.h>
#include <stdint.h>
int a[]={13, 8, 7};
int b[]={7, 10, 12};
int c[]={12, 6, 10};
int minValue = INT32_MAX;
int ua;
int ub;
int uc;
int result[3]={0};
int u[3]={0};

void work(int n, int k){
    if (n==k){
        for (int i = 0; i < k; ++i) {
            if (result[0]+result[1]+result[2]<minValue){
                minValue = result[0]+result[1]+result[2];
                ua=u[0];
                ub=u[1];
                uc=u[2];
            }
        }
    }else{
        for (int i = 0; i < k; ++i) {
            if (result[0]==0){
                result[0]=a[i];
                u[0]=i;
                work(n+1, k);
                u[0]=0;
                result[0]=0;
            }
        }
        for (int i = 0; i < k; ++i) {
            if (result[1]==0){
                result[1]=b[i];
                u[1]=i;
                work(n+1, k);
                u[1]=0;
                result[1]=0;
            }
        }
        for (int i = 0; i < k; ++i) {
            if (result[2]==0){
                result[2]=c[i];
                u[2]=i;
                work(n+1, k);
                u[2]=0;
                result[2]=0;
            }
        }
    }
}

int main(){
    work(0, 3);
    printf("%d, %d, %d, %d",minValue, ua, ub, uc);
    return 0;
}