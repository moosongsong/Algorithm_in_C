//
// Created by songe on 2020-08-25.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct _queue_{
    int front;
    int rear;
    int size;
    int * ary;
} QUEUE;

int isEmpty(QUEUE q){
    return q.front=q.rear;
}

int isFull(QUEUE q){
    return (((q.rear+1)%q.size) == q.front);
}

int enQueue(QUEUE * temp, int n){
    QUEUE* q=temp;
    q->ary[q->rear++] = n;
    q->rear = q->rear%q->size;
}

int deQueue(QUEUE * t){
    QUEUE *q=t;
    int temp = q->ary[q->front++];
    q->front = q->front %q->size;
    return temp;
}

int main(){
    freopen("C:\\Users\\songe\\DataStructure_in_CLion\\untitled1\\200825_07_data.txt", "r", stdin);
    QUEUE q;
    scanf("%d", &q.size);
    int order = 0;
    scanf("%d", &order);
    int me = 0;
    scanf("%d", &me);

    q.front = 0;
    q.rear = 0;
    q.ary = calloc(sizeof(int), q.size);

    printf("%d %d %d\n", q.size, order, me);

    for (int i = 1; i <= q.size; ++i) {
        enQueue(&q, i);
    }

    int count = 0;
    int temp = 0;
    int cnt = 0;
    while (1){
        temp = deQueue(&q);
        count++;
        if (count%order != 0){
            enQueue(&q, temp);
        }else{
            cnt++;
            printf("%d ", temp);
            if (temp == me) break;
        }
    }

    printf("\n%d\n", cnt);



    free(q.ary);
    return 0;
}