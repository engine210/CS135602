//
//  main.c
//  11361 - Binary Tree Operations
//
//  Created by engine210 on 2019/3/15.
//  Copyright © 2019 engine210. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void freeTree(Node *root) {
    if(root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(int argc, const char * argv[]) {
    
    int i,n;
    int *inorder,*preorder;
    scanf("%d",&n); // n : the size of binary tree
    /*------------Parse the input----------------*/
    inorder = (int *) malloc(n * sizeof(int));
    preorder = (int *) malloc(n * sizeof(int));
    for(i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for(i = 0; i < n; i++) scanf("%d", &preorder[i]);
    /*------------Build the binary tree----------*/
    Node *root = buildTree(inorder, preorder, 0, n-1);
    /*------------Print out the tree ------------*/
    showPostorder(root);
    freeTree(root);
    free(inorder);
    free(preorder);
    return 0;
}


