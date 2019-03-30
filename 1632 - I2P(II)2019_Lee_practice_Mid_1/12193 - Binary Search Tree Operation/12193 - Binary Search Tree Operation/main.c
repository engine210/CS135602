//
//  main.c
//  12193 - Binary Search Tree Operation
//
//  Created by engine210 on 2019/3/21.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int data;
    struct _Node* left;
    struct _Node* right;
} Node;

int maxHeight, level, sum, amount;

Node* createTree(int);
void do_P(Node*);
void do_G(Node*, int);
void do_S(Node*, int);
void do_A(Node*, int);

int main(int argc, const char * argv[]) {
    
    int n, m;
    char ins[20];
    Node* root;
    scanf("%d", &n);
    root = createTree(n);
    scanf("%d", &m);
    while (m--) {
        scanf("%s", ins);
        switch (ins[0]) {
            case 'P':
                if (root == NULL) {
                    printf("NULL");
                }
                else {
                    do_P(root);
                }
                printf("\n");
                break;
            case 'G':
                maxHeight = 0;
                do_G(root, 0);
                printf("%d\n", maxHeight);
                break;
            case 'S':
                scanf("%d", &level);
                sum = 0;
                do_S(root, 1);
                printf("%d\n", sum);
                break;
            case 'A':
                scanf("%d", &level);
                sum = 0;
                amount = 0;
                do_A(root, 1);
                if (amount == 0) {
                    printf("0\n");
                }
                else {
                    printf("%.3f\n", (float)sum/(float)amount);
                }
                break;
        }
    }
    
    return 0;
}

Node* createTree(int n) {
    if (!n) {
        return NULL;
    }
    Node* root = (Node*) malloc(sizeof(Node));
    Node* cur;
    int num;
    scanf("%d", &(root->data));
    root->left = NULL;
    root->right = NULL;
    
    while (n > 1) {
        cur = root;
        scanf("%d", &num);
        while (1) {
            if (num > cur->data) {
                if (cur->right == NULL) {
                    cur->right = (Node*) malloc(sizeof(Node));
                    cur = cur->right;
                    cur->data = num;
                    cur->left = NULL;
                    cur->right = NULL;
                    break;
                }
                else {
                    cur = cur->right;
                }
            }
            else if (num < cur->data){
                if (cur->left == NULL) {
                    cur->left = (Node*) malloc(sizeof(Node));
                    cur = cur->left;
                    cur->data = num;
                    cur->left = NULL;
                    cur->right = NULL;
                    break;
                }
                else {
                    cur = cur->left;
                }
            }
            else {
                break;
            }
        }
        n--;
    }
    return root;
}

void do_P(Node* root) {
    if (root != NULL) {
        do_P(root->left);
        printf("%d ", root->data);
        do_P(root->right);
    }
}

void do_G(Node* root, int h) {
    if (root != NULL) {
        do_G(root->left, h+1);
        do_G(root->right, h+1);
    }
    else {
        if (h > maxHeight) {
            maxHeight = h;
        }
    }
}

void do_S(Node* root, int h) {
    if (root != NULL) {
        if (h == level) {
            sum += root->data;
        }
        else {
            do_S(root->left, h+1);
            do_S(root->right, h+1);
        }
    }
}

void do_A(Node* root, int h) {
    if (root != NULL) {
        if (h == level) {
            sum += root->data;
            amount++;
        }
        else {
            do_A(root->left, h+1);
            do_A(root->right, h+1);
        }
    }
}
