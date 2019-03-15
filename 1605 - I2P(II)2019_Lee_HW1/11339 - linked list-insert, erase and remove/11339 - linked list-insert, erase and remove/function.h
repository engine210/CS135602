//
//  function.h
//  11339 - linked list-insert, erase and remove
//
//  Created by engine210 on 2019/3/5.
//  Copyright © 2019 engine210. All rights reserved.
//


#ifndef NODE
#define NODE
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    struct node *next;
    struct node *prev;
    unsigned short val;
} Node;

void do_I(Node **head,size_t pos,unsigned short val);
void do_E(Node **head,size_t begin_pos,size_t end_pos);
void do_P(Node  *head,size_t pos);
void do_R(Node **head,unsigned short val);
void do_S(Node  *head);

#endif /* function_h */
