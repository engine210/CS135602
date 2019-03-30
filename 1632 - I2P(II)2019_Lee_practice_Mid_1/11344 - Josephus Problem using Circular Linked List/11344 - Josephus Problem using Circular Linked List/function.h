//
//  function.h
//  11344 - Josephus Problem using Circular Linked List
//
//  Created by engine210 on 2019/3/30.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef FUNCTION_H
#define FUNCTION_H

typedef struct node{
    int data;
    struct node *next;
} Node;
Node* create(int n);
void josephus(int m,Node *head);

#endif /* function_h */
