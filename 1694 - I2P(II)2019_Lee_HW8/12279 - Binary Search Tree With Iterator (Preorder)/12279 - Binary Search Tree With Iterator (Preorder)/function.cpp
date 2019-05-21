//
//  function.cpp
//  12279 - Binary Search Tree With Iterator (Preorder)
//
//  Created by engine210 on 2019/5/17.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.hpp"
#include <iostream>
#include <stack>
using namespace std;

struct Content {
    stack<Node*> s;
};

Iterator::Iterator(Node* root) {
    data = new Content;
    ((Content*)data)->s.push(root);
}

Iterator::Iterator(const Iterator &other) {
    ((Content*)data)->s = ((Content*)other.data)->s;
}

Iterator::~Iterator() {
    delete (Content*)data;
}

int Iterator::operator*() const {
    return ((Content*)data)->s.top()->value;
}

bool Iterator::operator!=(const Iterator &it) const {
    /*
    if (((Content*)data)->s.empty()) {
        cout << "stack is empty ";
    }
    else if (((Content*)data)->s.top()) {
        cout << (((Content*)data)->s.top())->value << " ";
    }
    else {
        cout << "nullptr ";
    }
     */
    if (((Content*)data)->s.top() != ((Content*)it.data)->s.top()) {
        return true;
    }
    else {
        return false;
    }
}

void Iterator::operator++(int) {
    if (!(((Content*)data)->s.empty()) && ((Content*)data)->s.top() != nullptr) {
        Node* cur = ((Content*)data)->s.top();
        ((Content*)data)->s.pop();
        if (((Content*)data)->s.empty()) {
            ((Content*)data)->s.push(nullptr);
        }
        if (cur) {
            if (cur->right) {
                ((Content*)data)->s.push(cur->right);
            }
            if (cur->left) {
                ((Content*)data)->s.push(cur->left);
            }
        }
    }
}
