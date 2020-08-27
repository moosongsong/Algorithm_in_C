//
// Created by songe on 2020-08-27.
//
#include <stdio.h>

#define MAX (100)
int queue[MAX];
int last = 0;

void upHeap();

void downHeap();

void enQueue(int n){
    queue[++last] = n;
    upHeap();
}

int deQueue(){
    int temp = queue[1];
    queue[1] = queue[last--];
    downHeap();
    return temp;
}

void downHeap() {
    int parent = 1;
    while (parent<last){
        int l_child = parent*2;
        int r_child = parent*2+1;
        int child = parent;
        if (l_child < last){
            break;
        }else{
            if (r_child <=last){
                child = queue[l_child] < queue[r_child] ?l_child:r_child;
            }else{
                child = l_child;
            }
        }

        if (queue[child]<queue[parent]){

        }
    }
}

void upHeap() {
    int child = last;
    while (child > 1){
        int parent = child / 2;
        if (queue[parent] > queue[child]){
            int temp = queue[parent];
            queue[parent] = queue[child];
            queue[child] =temp;
        }else{
            break;
        }
        child = parent;
    }
}


int main() {
    int count;
    int ary[MAX]={0,};
    freopen("C:\\project\\Algorithm_in_C\\20200827_sorting_tree\\200827_03_data.txt", "r", stdin);
    scanf("%d", &count);
    for (int i = 0; i < count; ++i) {
        scanf("%d", &ary[i]);
    }
    for (int i = 0; i < count; ++i) {
        enQueue(ary[i]);
    }
    for (int i = 1; i <= count; ++i) {
        printf("%d ", queue[i]);
    }

    return 0;
}