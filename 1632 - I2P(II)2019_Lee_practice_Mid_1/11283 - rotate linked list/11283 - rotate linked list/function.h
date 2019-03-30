//
//  function.h
//  11283 - rotate linked list
//
//  Created by engine210 on 2019/3/29.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void rotateList(Node**,int);

#endif /* function_h */
