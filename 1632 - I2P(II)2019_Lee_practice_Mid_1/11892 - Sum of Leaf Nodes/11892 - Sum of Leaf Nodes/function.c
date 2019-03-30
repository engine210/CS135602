//
//  function.c
//  11892 - Sum of Leaf Nodes
//
//  Created by engine210 on 2019/3/30.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.h"
#include <stdio.h>

Node* buildTree(int* inorder, int* preorder, int inorder_start, int inorder_end) {
    
    if (inorder_start > inorder_end) {
        return NULL;
    }
    static int cur = 0;
    Node *root = (Node*) malloc(sizeof(Node));
    root->data = preorder[cur++];
    if (inorder_start == inorder_end) {
        root->left = NULL;
        root->right = NULL;
    }
    else {
        //finding the position of "root->data"
        int i = inorder_start;
        while (inorder[i] != root->data) {
            i++;
        }
        root->left = buildTree(inorder, preorder, inorder_start, i - 1);
        root->right = buildTree(inorder, preorder, i + 1, inorder_end);
    }
    return root;
}

int cal(Node* root) {
    if (root->left == NULL && root->right == NULL) {
        return root->data;
    }
    else if (root->left == NULL){
        return cal(root->right);
    }
    else if (root->right == NULL) {
        return cal(root->left);
    }
    else {
        return cal(root->left) + cal(root->right);
    }
}

void caculateLeafNodesSum(Node* root) {
    printf("%d\n", cal(root));
}
