//
//  function.c
//  10966 - Infix to syntax tree
//
//  Created by engine210 on 2019/3/18.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.h"
#include <stdlib.h>

BTNode* EXPR() {
    BTNode* right = FACTOR();
    if (expr[pos] == '&' || expr[pos] == '|') {
        BTNode* root = makeNode(expr[pos--]);
        root->right = right;
        root->left = EXPR();
        return root;
    }
    else {
        return right;
    }
}

BTNode* FACTOR() {
    BTNode* root;
    if (expr[pos] == ')') {
        pos--;
        root = EXPR();
        pos--;
        return root;
    }
    else {
        root = makeNode(expr[pos--]);
        return root;
    }
}

BTNode* makeNode(char c) {
    BTNode* root = (BTNode*) malloc(sizeof(BTNode));
    int i;
    for (i = 0; i < 6; i++) {
        if (c == sym[i]) {
            root->data = i;
            break;
        }
    }
    root->left = NULL;
    root->right = NULL;
    return root;
}

