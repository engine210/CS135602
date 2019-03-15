//
//  main.h
//  11270 - reverse linked list
//
//  Created by engine210 on 2019/3/5.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef main_h
#define main_h

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* createList(void);
Node* reverse(Node*);

#endif /* main_h */
