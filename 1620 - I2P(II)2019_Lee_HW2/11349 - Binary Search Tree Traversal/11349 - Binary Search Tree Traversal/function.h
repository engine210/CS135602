//
//  function.h
//  11349 - Binary Search Tree Traversal
//
//  Created by engine210 on 2019/3/12.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

void create_tree(Node **root, int n);
void print_tree(Node *root);
void destroyTree(Node *root);

#endif
 /* function_h */
