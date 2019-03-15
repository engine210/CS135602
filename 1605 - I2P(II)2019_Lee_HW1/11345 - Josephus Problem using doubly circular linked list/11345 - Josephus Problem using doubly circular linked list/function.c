//
//  function.c
//  11345 - Josephus Problem using doubly circular linked list
//
//  Created by engine210 on 2019/3/7.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "function.h"


man* createList(int n) {
    int i;
    man* cur;
    head = (man*)malloc(sizeof(man));
    cur = head;
    cur->id = 1;
    for (i = 2; i <= n; i++) {
        cur->next = malloc(sizeof(man));
        cur->next->prev = cur;
        cur = cur->next;
        cur->id = i;
    }
    cur->next = head;
    head->prev = cur;
    return head;
}

int solveJosephus(int step) {
    int dir = 1; //1:clock-wise, -1:anticlock-wise.
    int i;
    man *free_temp;
    while (head->next != head) {
        if (dir == 1) {
            for (i = 1; i < step; i++) {
                head = head->next;
            }
            free_temp = head;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->prev;
            free(free_temp);
        }
        else {
            for (i = 1; i < step; i++) {
                head = head->prev;
            }
            free_temp = head;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            free(free_temp);
        }
        dir *= -1;
    }
    return head->id;
}
