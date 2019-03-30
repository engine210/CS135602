//
//  main.c
//  11283 - rotate linked list
//
//  Created by engine210 on 2019/3/29.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void freeList(Node *head);
Node* createList(void);
void printList(Node *head);

int main() {
    Node *head = NULL;
    Node *temp;
    int data;
    int k;
    
    head = createList();
    scanf("%d",&k);
    rotateList(&head,k);
    printList(head);
    freeList(head);
    return 0;
}



void freeList(Node *head)
{
    Node *temp;
    for(temp=head; temp!=NULL; temp=head)
    {
        head = head->next;
        free(temp);
    }
}

Node* createList(){
    Node* head = NULL;
    Node* temp = NULL;
    int data;
    
    while(1){
        scanf("%d",&data);
        if(data>-1){
            if (temp==NULL) {
                temp = (Node*) malloc(sizeof(Node));
                head = temp;
            } else {
                temp->next = (Node*) malloc(sizeof(Node));
                temp = temp->next;
            }
            temp->data = data;
            temp->next = NULL;
        } else break;
    }
    return head;
}

void printList(Node *head)
{
    Node *temp=head;
    printf("%d", temp->data);
    temp=temp->next;
    
    for(; temp!=NULL; temp=temp->next)
    {
        printf(" %d", temp->data);
    }
    printf("\n");
}

