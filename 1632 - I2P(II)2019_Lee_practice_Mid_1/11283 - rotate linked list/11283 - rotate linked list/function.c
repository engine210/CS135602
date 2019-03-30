//
//  function.c
//  11283 - rotate linked list
//
//  Created by engine210 on 2019/3/29.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.h"
#include <stdlib.h>
void rotateList(Node** head, int k) {
    Node* cur = *head;
    Node* new_head = *head;
    while (k > 1) {
        cur = cur->next;
        k--;
    }
    new_head = cur->next;
    cur->next = NULL;
    cur = new_head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = *head;
    
    *head = new_head;
}
