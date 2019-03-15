//
//  function.c
//  11339 - linked list-insert, erase and remove
//
//  Created by engine210 on 2019/3/6.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.h"
#include <stdlib.h>
#include <stdio.h>

void do_I(Node** head, size_t pos, unsigned short val) {
    
    Node* cur = *head;
    
    if (*head == NULL) {
        *head = malloc(sizeof(Node));
        (*head)->next = NULL;
        (*head)->prev = NULL;
        (*head)->val = val;
        return;
    }
    if (pos == 0) {
        (*head)->prev = malloc(sizeof(Node));
        (*head)->prev->prev = NULL;
        (*head)->prev->next = (*head);
        (*head)->prev->val = val;
        (*head) = (*head)->prev;
        return;
    }
    
    while (pos > 0 && cur->next != NULL) {
        cur = cur->next;
        pos--;
    }
        
    if (cur->next == NULL && pos != 0) {
        cur->next = malloc(sizeof(Node));
        cur->next->prev = cur;
        cur->next->next = NULL;
        cur->next->val = val;
    }
    else {
        cur->prev->next = malloc(sizeof(Node));
        cur->prev->next->next = cur;
        cur->prev->next->prev = cur->prev;
        cur->prev = cur->prev->next;
        cur->prev->val = val;
    }
    
}

void do_E(Node** head, size_t begin_pos, size_t end_pos) {
    Node* cur = *head;
    Node* begin;
    Node* free_temp;
    size_t eraseTimes = end_pos - begin_pos;
    
    if (*head == NULL) {
        return;
    }
    
    if (begin_pos == 0) {
        while (eraseTimes > 0 && cur != NULL) {
            free_temp = cur;
            cur = cur->next;
            free(free_temp);
            eraseTimes--;
        }
        if (cur != NULL) {
            cur->prev = NULL;
        }
        *head = cur;
        return;
    }
    
    while (begin_pos > 0 && cur->next != NULL) {
        cur = cur->next;
        begin_pos--;
    }
    
    if (cur->next == NULL && begin_pos != 0) {
        return;
    }
    
    begin = cur->prev;
    while (eraseTimes > 0 && cur != NULL) {
        free_temp = cur;
        cur = cur->next;
        free(free_temp);
        eraseTimes--;
    }
    begin->next = cur;
    if (cur != NULL) {
        cur->prev = begin;
    }
}

void do_P(Node* head, size_t pos) {
    if (head == NULL) {
        return;
    }
    while (pos > 0 && head->next != NULL) {
        head = head->next;
        pos--;
    }
    printf("%d ", head->val);
}

void do_R(Node** head, unsigned short val) {
    Node* cur;
    Node* free_temp;
    
    if (*head == NULL) {
        return;
    }
    
    while ((*head)->val == val) {
        free_temp = *head;
        (*head) = (*head)->next;
        free(free_temp);
        if (*head == NULL) {
            return;
        }
        (*head)->prev = NULL;
    }
    
    cur = (*head);
    
    while (cur->next != NULL) {
        if (cur->val == val) {
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            free_temp = cur;
            cur = cur->next;
            free(free_temp);
        }
        else {
            cur = cur->next;
        }
    }
    if (cur->val == val) {
        cur->prev->next = NULL;
        free(cur);
    }
}

void do_S(Node* head) {
    
    if (head == NULL) {
        return;
    }
    
    while (head->next != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("%d ", head->val);
}

