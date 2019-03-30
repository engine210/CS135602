//
//  function.c
//  11371 - Polynomial multiplication using linked list
//
//  Created by engine210 on 2019/3/29.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.h"
#include <stdio.h>
#include <stdlib.h>

void printNode(Node* head) {
    while (head != NULL) {
        if (head->data != 0) {
            printf(" %ld %d", head->data, head->power);
        }
        head = head->next;
    }
}

Node* create() {
    Node *head, *cur;
    long cofficient;
    int power;
    scanf("%ld%d", &cofficient, &power);
    head = malloc(sizeof(Node));
    cur = head;
    cur->data = cofficient;
    cur->power = power;
    cur->next = NULL;
    while (power != 0) {
        scanf("%ld%d", &cofficient, &power);
        cur->next = malloc(sizeof(Node));
        cur = cur->next;
        cur->data = cofficient;
        cur->power = power;
        cur->next = NULL;
    }
    return head;
}

void destroy(Node *node) {
    if (node != NULL) {
        destroy(node->next);
        free(node);
    }
}

Node* insertNode(Node* head, long cofficient, int power) {
    if (head == NULL) {
        head = malloc(sizeof(Node));
        head->data = cofficient;
        head->power = power;
        head->prev = NULL;
        head->next = NULL;
    }
    else if (power > head->power) {
        Node* cur = malloc(sizeof(Node));
        cur->next = head;
        head = cur;
        head->data = cofficient;
        head->power = power;
    }
    else {
        Node* cur = head;
        while (1) {
            if (power == cur->power) {
                cur->data += cofficient;
                break;
            }
            else if (power < cur->power && cur->next == NULL) {
                cur->next = malloc(sizeof(Node));
                cur = cur->next;
                cur->next = NULL;
                cur->data = cofficient;
                cur->power = power;
                break;
            }
            else if (power < cur->power && power > cur->next->power) {
                Node* new = malloc(sizeof(Node));
                new->next = cur->next;
                cur->next = new;
                cur = cur->next;
                cur->data = cofficient;
                cur->power = power;
                break;
            }
            cur = cur->next;
        }
    }
    return head;
}

Node* multiple(Node* p1, Node* p2) {
    Node* poly_head = NULL;
    Node* p1_cur = p1;
    Node* p2_cur = p2;
    
    while (p1_cur != NULL) {
        p2_cur = p2;
        while (p2_cur != NULL) {
            if (p1_cur->data != 0 && p2_cur->data != 0) {
                poly_head = insertNode(poly_head, p1_cur->data * p2_cur->data, p1_cur->power + p2_cur->power);
            }
            p2_cur = p2_cur->next;
        }
        p1_cur = p1_cur->next;
    }
    return poly_head;
}
