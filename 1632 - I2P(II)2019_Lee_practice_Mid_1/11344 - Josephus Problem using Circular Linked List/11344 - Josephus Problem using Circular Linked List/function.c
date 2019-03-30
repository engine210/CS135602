//
//  function.c
//  11344 - Josephus Problem using Circular Linked List
//
//  Created by engine210 on 2019/3/30.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.h"
#include <stdlib.h>
#include <stdio.h>

Node* create(int n) {
    if (!n) return 0;
    int i;
    Node* head = malloc(sizeof(Node));
    head->data = 1;
    head->next = NULL;
    Node* cur = head;
    
    for (i = 2; i <= n; i++) {
        cur->next = malloc(sizeof(Node));
        cur = cur->next;
        cur->data = i;
    }
    cur->next = head;
    return head;
}

void josephus(int m, Node *head) {
    int i;
    Node* cur = head;
    Node* freeTemp;
    while (cur->next != cur) {
        for (i = 0; i < m-2; i++) {
            cur = cur->next;
        }
        printf("%d ", cur->next->data);
        freeTemp = cur->next;
        cur->next = cur->next->next;
        free(freeTemp);
        cur = cur->next;
    }
    printf("%d\n", cur->data);
}
