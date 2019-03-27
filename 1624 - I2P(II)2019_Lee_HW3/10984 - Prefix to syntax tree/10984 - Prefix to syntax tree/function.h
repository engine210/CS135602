//
//  function.h
//  10984 - Prefix to syntax tree
//
//  Created by engine210 on 2019/3/21.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef function_h
#define function_h

#include <stdlib.h>
typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void constructTree(Node** head);

void printInfix(Node *root);

void freeTree(Node *root);

#endif /* function_h */
