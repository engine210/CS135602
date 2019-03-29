//
//  main.c
//  10954 - Prefix to truth table
//
//  Created by engine210 on 2019/3/28.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {ID, OP_AND, OP_OR} TokenSet;

typedef struct _Node {
    TokenSet dataType;
    int value;
    struct _Node *left, *right;
} Node;

int amount[4]; //the node amount of A, B, C, D
Node* variable[4][30];

Node* buildTree() {
    Node* root = NULL;
    char c = getchar();
    switch (c) {
        case '|':
            root = (Node*)malloc(sizeof(Node));
            root->dataType = OP_OR;
            root->left = buildTree();
            root->right = buildTree();
            break;
        case '&':
            root = (Node*)malloc(sizeof(Node));
            root->dataType = OP_AND;
            root->left = buildTree();
            root->right = buildTree();
            break;
        case 'A':
            root = (Node*)malloc(sizeof(Node));
            variable[0][amount[0]] = root;
            amount[0]++;
            root->dataType = ID;
            root->value = 0;
            root->left = NULL;
            root->right = NULL;
            break;
        case 'B':
            root = (Node*)malloc(sizeof(Node));
            variable[1][amount[1]] = root;
            amount[1]++;
            root->dataType = ID;
            root->value = 0;
            root->left = NULL;
            root->right = NULL;
            break;
        case 'C':
            root = (Node*)malloc(sizeof(Node));
            variable[2][amount[2]] = root;
            amount[2]++;
            root->dataType = ID;
            root->value = 0;
            root->left = NULL;
            root->right = NULL;
            break;
        case 'D':
            root = (Node*)malloc(sizeof(Node));
            variable[3][amount[3]] = root;
            amount[3]++;
            root->dataType = ID;
            root->value = 0;
            root->left = NULL;
            root->right = NULL;
            break;
    }
    
    return root;
}

void show(Node* root) {
    if (root != NULL) {
        show(root->left);
        if (root->dataType == OP_OR) {
            printf("|");
        }
        else if (root->dataType == OP_AND) {
            printf("&");
        }
        else {
            printf("%d", root->value);
        }
        show(root->right);
    }
}

int cal(Node* root) {
    if (root->dataType == OP_AND) {
        return cal(root->left) & cal(root->right);
    }
    else if (root->dataType == OP_OR) {
        return cal(root->left) | cal(root->right);
    }
    else {
        return root->value;
    }
}

int main(int argc, const char * argv[]) {
    
    int i, j, bin;
    Node* root;
    memset(amount, 0, sizeof(amount));
    //getchar();
    root = buildTree();
    
    for (bin = 0; bin < 16; bin++) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < amount[3-i]; j++) {
                (variable[3-i][j])->value = (bin >> i) % 2;
            }
        }
        for (i = 3; i >= 0; i--) {
            printf("%d ", (bin >> i) % 2);
        }
        printf("%d\n", cal(root));
    }
    
    return 0;
}
