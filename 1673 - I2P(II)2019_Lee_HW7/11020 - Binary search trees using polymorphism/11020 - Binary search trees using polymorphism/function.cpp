//
//  function.cpp
//  11020 - Binary search trees using polymorphism
//
//  Created by engine210 on 2019/5/3.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifdef ONLINE_JUDGE
#include "function.h"
#else
#include "function.hpp"
#endif

#include <string.h>

Array_BST::Array_BST() {
    memset(array, 0, sizeof(array));
}

void Array_BST::insert(const int& data) {
    
    int i = 1;
    int h = 1;
    while (array[i]) {
        if (data == array[i]) {
            return;
        }
        else if (data < array[i]) {
            i *= 2;
        }
        else {
            i = i * 2 + 1;
        }
        h++;
    }
    array[i] = data;
    if (h > Height) {
        Height = h;
    }
}

bool Array_BST::search(const int& data) const {
    int k = pow(2, height());
    for (int i = 1; i <= k-1; i++) {
        if (data == array[i]) {
            return true;
        }
    }
    return false;
}

List_BST::List_BST() {
    root = nullptr;
}

void List_BST::deleteTree(ListNode *root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

ListNode* List_BST::createLeaf(int key) const {
    ListNode* p = new ListNode(key);
    return p;
}

void List_BST::insert(const int& data) {
    
    if (root == nullptr) {
        root = createLeaf(data);
        Height = 1;
        return;
    }
    
    ListNode* cur = root;
    ListNode* parent = root;
    int h = 1;
    
    while (cur) {
        parent = cur;
        if (data == cur->key) {
            return;
        }
        else if (data < cur->key) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
        h++;
    }
    
    if (h > Height) {
        Height = h;
    }
    
    if (data < parent->key) {
        parent->left = createLeaf(data);
    }
    else {
        parent->right = createLeaf(data);
    }
}

bool List_BST::search(const int& data) const {
    ListNode* cur = root;
    while (cur) {
        if (data == cur->key) {
            return true;
        }
        else if (data < cur->key) {
            cur = cur->left;
        }
        else {
            cur = cur->right;
        }
    }
    return false;
}
