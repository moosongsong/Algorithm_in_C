//
// Created by songe on 2020-08-25.
//
#include <stdio.h>
#include <stdlib.h>
typedef struct _people_{
    int count;
    int pos;
    int speed;
} PEOPLE;

int main(){
    freopen("C:\\Users\\songe\\DataStructure_in_CLion\\untitled1\\200825_06_data.txt", "r", stdin);
    int num_of_people = 0;
    scanf("%d", &num_of_people);

    PEOPLE * team = calloc(sizeof(PEOPLE), num_of_people);

    for (int i = 0; i < num_of_people; ++i) {
        scanf("%d", &team[i].count);
        scanf("%d", &team[i].pos);
        scanf("%d", &team[i].speed);
    }

    for (int j = 0; j < num_of_people; ++j) {
        printf("%d %d %d\n", team[j].count, team[j].pos, team[j].speed);
    }

    int top = num_of_people-1;
    int group = 0;

    PEOPLE cur = team[--top];
    int pos = cur.pos - (cur.speed * 3);
    while (top >= 0){
        cur = team[--top];
        int temp = cur.pos - (cur.speed *3);;
        if (temp > pos){
            pos = temp;
            group++;
        }
    }

    printf("%d\n", group);


    free(team);
    return 0;
}