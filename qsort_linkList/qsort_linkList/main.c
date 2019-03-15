//
//  main.c
//  qsort_linkList
//
//  Created by engine210 on 2019/3/12.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* left;
    struct _Node* right;
} Node;

void insertNode(Node*, int);
void showTree(Node*);

int main(int argc, const char * argv[]) {
    
    int num;
    Node* root = (Node*) malloc(sizeof(Node));
    root->left = NULL;
    root->right = NULL;
    scanf("%d", &num);
    root->data = num;
    
    while (scanf("%d", &num)) {
        insertNode(root, num);
    }
    
    showTree(root);
    
    
    return 0;
}

void insertNode(Node* root, int num) {
    
    if (num < root->data) {
        if (root->left == NULL) {
            root->left = (Node*) malloc(sizeof(Node));
            root->left->data = num;
            root->left->left = NULL;
            root->left->right = NULL;
        }
        else {
            insertNode(root->left, num);
        }
    }
    else if (num > root->data) {
        if (root->right == NULL) {
            root->right = (Node*) malloc(sizeof(Node));
            root->right->data = num;
            root->right->left = NULL;
            root->right->right = NULL;
        }
        else {
            insertNode(root->right, num);
        }
    }
    
}

void showTree(Node* root) {
    if (root != NULL) {
        showTree(root->left);
        printf("%d ", root->data);
        showTree(root->right);
    }
}
