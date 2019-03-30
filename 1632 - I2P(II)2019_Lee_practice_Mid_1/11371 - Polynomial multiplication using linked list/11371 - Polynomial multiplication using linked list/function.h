//
//  function.h
//  11371 - Polynomial multiplication using linked list
//
//  Created by engine210 on 2019/3/29.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

typedef struct _Node{
    long data;  //the value of coefficient
    int power; //the value of power
    struct _Node *next;
    struct _Node *prev;
}Node;
void printNode(Node* head);         //the function which will print the output
Node* create(void);                     //create polynomial linked list
void destroy(Node *node);           //destroy polynomial linked list
Node* multiple(Node* p1, Node* p2); //input two polynomial linked list and return the result

#endif /* function_h */
