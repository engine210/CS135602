//
//  function.h
//  10966 - Infix to syntax tree
//
//  Created by engine210 on 2019/3/18.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#define MAXEXPR 256
#define NUMSYM 6

extern char expr[MAXEXPR];  // string to store the input expression.
extern int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
extern char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR(void);
BTNode* FACTOR(void);
BTNode* makeNode(char c);
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

#endif
/* function_h */
