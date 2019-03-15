//
//  main.c
//  11270 - reverse linked list
//
//  Created by engine210 on 2019/3/5.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

void printList(Node *head);
void freeList(Node*);

int main(int argc, char* argv[]) {
    Node *head = NULL;
    Node *temp;
    int data;
    
    head = createList();
    head = reverse(head);
    printList(head);
    freeList(head);
    return 0;
}

Node* createList() {
    
    Node *head, *cur;
    int num;
    scanf("%d", &num);
    if (num == -1) {
        return NULL;
    }
    head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    head->data = num;
    cur = head;
    scanf("%d", &num);
    while (num != -1) {
        cur->next = (Node*) malloc(sizeof(Node));
        cur = cur->next;
        cur->data = num;
        cur->next = NULL;
        scanf("%d", &num);
    }
    return head;
}

Node* reverse(Node* head) {
    Node *pre, *cur, *next;
    pre = NULL;
    cur = head;
    next = head->next;
    while (next != NULL) {
        cur->next = pre;
        pre = cur;
        cur = next;
        next = next->next;
    }
    cur->next = pre;
    return cur;
}

void freeList(Node *head) {
    Node *temp;
    for(temp=head; temp!=NULL; temp=head) {
        head = head->next;
        free(temp);
    }
}

void printList(Node *head) {
    Node *temp;
    for(temp = head; temp!=NULL; temp=temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");
}

