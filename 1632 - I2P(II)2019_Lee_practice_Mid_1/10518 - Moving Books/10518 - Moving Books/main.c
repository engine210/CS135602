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
            if (books[bookA] != NULL && books[bookB] != NULL && bookA != bookB) {
                if (command[0] == 'o') {
                    if (books[bookA] == head) {
                        head = books[bookA]->next;
                        head->prev = NULL;
                        books[bookA]->next = books[bookB]->next;
                        books[bookB]->next = books[bookA];
                        if (books[bookA]->next != NULL) {
                            books[bookA]->next->prev = books[bookA];
                        }
                        books[bookA]->prev = books[bookB];
                    }
                    else {
                        books[bookA]->prev->next = books[bookA]->next;
                        books[bookA]->prev->next->prev = books[bookA]->prev;
                        books[bookA]->next = books[bookB]->next;
                        books[bookA]->prev = books[bookB];
                        books[bookB]->next = books[bookA];
                        if (books[bookA]->next != NULL) {
                            books[bookA]->next->prev = books[bookA];
                        }
                    }
                }
                else if(command[0] == 'u') {
                    if (books[bookA] == head) {
                        head = books[bookA]->next;
                        head->prev = NULL;
                        books[bookA]->next = books[bookB];
                        books[bookB]->prev->next = books[bookA];
                        if (books[bookA]->next != NULL) {
                            books[bookA]->next->prev = books[bookA];
                        }
                        books[bookA]->prev = books[bookB]->prev;
                    }
                    else {
                        books[bookA]->prev->next = books[bookA]->next;
                        books[bookA]->prev->next->prev = books[bookA]->prev;
                        books[bookA]->next = books[bookB];
                        books[bookB]->prev->next = books[bookA];
                        if (books[bookA]->next != NULL) {
                            books[bookA]->next->prev = books[bookA];
                        }
                        books[bookA]->prev = books[bookB]->prev;
                    }
                }
            }
        }
        else if (command[0] == 'r') {
            scanf("%d", &bookA);
            if (books[bookA] != NULL) {
                if (books[bookA] == head) {
                    head = head->next;
                    free(head->prev);
                    head->prev = NULL;
                }
                else {
                    books[bookA]->next->prev = books[bookA]->prev;
                    books[bookA]->prev = books[bookA]->next;
                    free(books[bookA]);
                }
            }
        }
        scanf("%s", command);
    }
    
    printList(head);
    
    return 0;
}
