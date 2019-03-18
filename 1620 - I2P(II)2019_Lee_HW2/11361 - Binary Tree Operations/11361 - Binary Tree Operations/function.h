//
//  function.h
//  11361 - Binary Tree Operations
//
//  Created by engine210 on 2019/3/15.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef function_h
#define function_h

#include <stdio.h>
#include <stdlib.h>
typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end);
void showPostorder(Node* root);
void freeTree(Node *root);


#endif /* function_h */
