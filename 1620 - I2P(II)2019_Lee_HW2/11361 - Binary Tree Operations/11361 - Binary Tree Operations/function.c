//
//  function.c
//  11361 - Binary Tree Operations
//
//  Created by engine210 on 2019/3/15.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.h"

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end) {
    
    if (inorder_start > inorder_end) {
        return NULL;
    }
    
    Node *root = (Node*) malloc(sizeof(Node));
    
    if (inorder_start == inorder_end) {
        root->data = *preorder;
        root->left = NULL;
        root->right = NULL;
    }
    else {
        //finding the position of "D"
        int i = 0;
        while (*(inorder + inorder_start + i) != *preorder) {
            i++;
        }
        root->data = *preorder;
        root->left = buildTree(inorder, preorder + 1, inorder_start, inorder_start + i - 1);
        root->right = buildTree(inorder, preorder + i + 1, inorder_start + i + 1, inorder_end);
    }
    return root;
}

void showPostorder(Node* root) {
    if (root != NULL) {
        showPostorder(root->left);
        showPostorder(root->right);
        printf("%d ", root->data);
    }
}
