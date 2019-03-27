//
//  main.c
//  12183 - Fairy Testing
//
//  Created by engine210 on 2019/3/26.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int value; // This is the value of the subtree, not the ID number
    int tokentype; //0: number, 1:'|', 2:'&'
    struct node *leftchild;
    struct node *rightchild;
    struct node *parent; //pointing to the parent node
} Node;

Node* variable[100001];

Node* buildTree(Node* parent) {
    char c = getchar();
    Node* root = malloc(sizeof(Node));
    
    root->parent = parent;
    root->value = 0;
    
    if (c == '|') {
        root->tokentype = 1;
        root->leftchild = buildTree(root);
        root->rightchild = buildTree(root);
    }
    else if (c == '&') {
        root->tokentype = 2;
        root->leftchild = buildTree(root);
        root->rightchild = buildTree(root);
    }
    else if (c == '[') {
        int index;
        scanf("%d", &index);
        variable[index] = root;
        root->leftchild = NULL;
        root->rightchild = NULL;
        root->tokentype = 0;
        getchar();
    }
    
    return root;
}

void flip(Node* root) {
    
    int index;
    Node* cur;
    scanf("%d", &index);
    cur = variable[index];
    cur->value = !cur->value;
    
    while (cur->parent != NULL) {
        if (cur->parent->tokentype == 1) {
            if (cur->parent->value == 0 && cur->value == 0) {
                printf("%d\n", root->value);
                return;
            }
            else if (cur->parent->value == 0 && cur->value == 1) {
                cur->parent->value = 1;
            }
            else if (cur->parent->value == 1 && cur->value == 0) {
                if (cur->parent->leftchild->value || cur->parent->rightchild->value) {
                    printf("%d\n", root->value);
                    return;
                }
                else {
                    cur->parent->value = 0;
                }
            }
            else if (cur->parent->value == 1 && cur->value == 1) {
                printf("%d\n", root->value);
                return;
            }
        }
        else if (cur->parent->tokentype == 2) {
            if (cur->parent->value == 0 && cur->value == 0) {
                printf("%d\n", root->value);
                return;
            }
            else if (cur->parent->value == 0 && cur->value == 1) {
                if (cur->parent->leftchild->value && cur->parent->rightchild->value) {
                    cur->parent->value = 1;
                }
                else {
                    printf("%d\n", root->value);
                    return;
                }
            }
            else if (cur->parent->value == 1 && cur->value == 0) {
                cur->parent->value = 0;
            }
            else if (cur->parent->value == 1 && cur->value == 1) { // impossible situation
                printf("%d\n", root->value);
                return;
            }
        }
        cur = cur->parent;
    }
    
    printf("%d\n", root->value);
    return;
    
}

int main(int argc, const char * argv[]) {
    
    
    int T;
    int n, m;
    int i;
    Node* root;
    
    scanf("%d", &T);
    
    while (T--) {
        
        scanf("%d%d", &n, &m);
        getchar();
        root = buildTree(NULL);
        root->parent = NULL;
        for (i = 0; i < m; i++) {
            flip(root);
        }
        
    }
    
    
    return 0;
}
