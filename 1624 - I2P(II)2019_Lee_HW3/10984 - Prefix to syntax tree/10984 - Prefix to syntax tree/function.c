//
//  function.c
//  10984 - Prefix to syntax tree
//
//  Created by engine210 on 2019/3/21.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.h"
#include <stdio.h>
void constructTree(Node** head) {
    char c = getchar();
    *head = (Node*) malloc(sizeof(Node));
    if (c == '|' || c == '&') {
        (*head)->data = c;
        constructTree(&((*head)->left));
        constructTree(&((*head)->right));
    }
    else {
        (*head)->data = c;
        (*head)->left = NULL;
        (*head)->right = NULL;
    }
}
