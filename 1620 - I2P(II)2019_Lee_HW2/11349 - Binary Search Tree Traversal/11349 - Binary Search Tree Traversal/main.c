//
//  main.c
//  11349 - Binary Search Tree Traversal
//
//  Created by engine210 on 2019/3/12.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "function.h"
void destroyTree(Node *root)
{
    if(root != NULL)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
}
int main(void)
{
    int n;
    Node *root = NULL;
    scanf("%d",&n);
    create_tree(&root, n);
    print_tree(root);
    destroyTree(root);
    return 0;
}

