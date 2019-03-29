//
//  main.c
//  10518 - Moving Books
//
//  Created by engine210 on 2019/3/26.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int value;
    struct _Node* next;
    struct _Node* prev;
} Node;

Node* books[10005];

Node* buildList(int n) {
    int i = 1;
    Node* head = malloc(sizeof(Node));
    Node* cur = head;
    books[0] = head;
    cur->next = NULL;
    cur->prev = NULL;
    cur->value = 0;
    while (i < n) {
        cur->next = malloc(sizeof(Node));
        cur->next->prev = cur;
        cur = cur->next;
        books[i] = cur;
        cur->value = i;
        i++;
    }
    cur->next = NULL;
    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

Node* move_on(Node* A, Node* B, Node* head) {
    
    //prevent illegal case
    if (A == B || A == NULL || B == NULL) {
        return head;
    }
    
    //remove node A from the original link list
    if (A == head) {            // A is the head
        head = A->next;
        head->prev = NULL;
    }
    else if (A->next == NULL){  // A is the tail
        A->prev->next = NULL;
    }
    else {
        A->prev->next = A->next;
        A->next->prev = A->prev;
    }
    
    //insert node A after node B
    if (B->next == NULL) {      // B is the tail
        B->next = A;
        A->next = NULL;
        A->prev = B;
    }
    else {
        A->next = B->next;
        B->next->prev = A;
        B->next = A;
        A->prev = B;
    }
    
    return head;
}

Node* move_under(Node* A, Node* B, Node* head) {
    
    //prevent illegal case
    if (A == B || A == NULL || B == NULL) {
        return head;
    }
    
    //remove node A from the original link list
    if (A == head) {            // A is the head
        head = A->next;
        head->prev = NULL;
    }
    else if (A->next == NULL){  // A is the tail
        A->prev->next = NULL;
    }
    else {
        A->prev->next = A->next;
        A->next->prev = A->prev;
    }
    
    //insert node A infront of node B
    if (B == head) {      // B is the tail
        A->next = B;
        B->prev = A;
        A->prev = NULL;
        head = A;
    }
    else {
        A->next = B;
        B->prev->next = A;
        A->prev = B->prev;
        B->prev = A;
    }
    
    return head;
}

Node* remove_Node(Node** A, Node* head) {
    
    //prevent illegal case
    if (*A == NULL) {
        return head;
    }
    
    //remove node A from the original link list
    if ((*A)->prev == NULL && (*A)->next == NULL) {    // if the list only has a single node
        free(*A);
        *A = NULL;
        head = NULL;
    }
    else if (*A == head) {                        // A is the head
        head = (*A)->next;
        head->prev = NULL;
        free(*A);
        *A = NULL;
    }
    else if ((*A)->next == NULL){                   // A is the tail
        (*A)->prev->next = NULL;
        free(*A);
        *A = NULL;
    }
    else {
        (*A)->prev->next = (*A)->next;
        (*A)->next->prev = (*A)->prev;
        free(*A);
        *A = NULL;
    }
    
    return head;
}

int main(int argc, const char * argv[]) {
    
    Node* head;
    int n, bookA, bookB;
    char command[10];
    scanf("%d", &n);
    head = buildList(n);
    scanf("%s", command);
    while (command[0] != 'e') {
        if (command[0] == 'm') {
            scanf("%d %s %d", &bookA, command, &bookB);
            if (bookA < n && bookB < n) {
                if (command[0] == 'o') {
                    head = move_on(books[bookA], books[bookB], head);
                }
                else if(command[0] == 'u') {
                    head = move_under(books[bookA], books[bookB], head);
                }
            }
        }
        else if (command[0] == 'r') {
            scanf("%d", &bookA);
            if (bookA < n) {
                head = remove_Node(&(books[bookA]), head);
            }
        }
        scanf("%s", command);
    }
    
    printList(head);
    
    return 0;
}
