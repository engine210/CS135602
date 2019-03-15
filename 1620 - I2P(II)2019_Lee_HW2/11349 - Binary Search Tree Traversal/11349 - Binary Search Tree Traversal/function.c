
//
//  function.c
//  11349 - Binary Search Tree Traversal
//
//  Created by engine210 on 2019/3/12.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include "function.h"


void create_tree(Node **root, int n) {
    int i, num;
    Node *cur;
    if (n == 0) {
        return;
    }
    *root = (Node*) malloc(sizeof(Node));
    (*root)->left = NULL;
    (*root)->right = NULL;
    scanf("%d", &num);
    (*root)->data = num;
    
    for (i = 1; i < n; i++) {
        cur = *root;
        scanf("%d", &num);
        while (1) {
            if (num < cur->data) {
                if (cur->left == NULL) {
                    cur->left = (Node*) malloc(sizeof(Node));
                    cur->left->data = num;
                    cur->left->left = NULL;
                    cur->left->right = NULL;
                    break;
                }
                cur = cur->left;
            }
            else if (num > cur->data) {
                if (cur->right == NULL) {
                    cur->right = (Node*) malloc(sizeof(Node));
                    cur->right->data = num;
                    cur->right->left = NULL;
                    cur->right->right = NULL;
                    break;
                }
                cur = cur->right;
            }
            else {
                break;
            }
        }
    }
}

void showPreorder(Node* root) {
    if (root != NULL) {
        printf("% d", root->data);
        showPreorder(root->left);
        showPreorder(root->right);
    }
}

void showInorder(Node* root) {
    if (root != NULL) {
        showInorder(root->left);
        printf(" %d", root->data);
        showInorder(root->right);
    }
    
}

void showPostorder(Node* root) {
    if (root != NULL) {
        showPostorder(root->left);
        showPostorder(root->right);
        printf(" %d", root->data);
    }
}

void print_tree(Node *root) {
    printf("preorder:");
    showPreorder(root);
    printf("\n");
    printf("inorder:");
    showInorder(root);
    printf("\n");
    printf("postorder:");
    showPostorder(root);
    printf("\n");
}
