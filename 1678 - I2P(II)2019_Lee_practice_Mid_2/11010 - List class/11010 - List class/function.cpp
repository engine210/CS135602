//
//  function.cpp
//  11010 - List class
//
//  Created by engine210 on 2019/5/13.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.hpp"

OWList::OWList() {
    firstPtr = nullptr;
    lastPtr = nullptr;
}

OWList::~OWList() {
    ListNode* cur = firstPtr;
    ListNode* freeTemp;
    while (cur != lastPtr) {
        freeTemp = cur;
        cur = cur->nextPtr;
        delete freeTemp;
    }
    delete cur;
}

void OWList::insertAtFront(const int &value) {
    if (!firstPtr) {
        firstPtr = lastPtr = new ListNode(value);
        return;
    }
    ListNode* newNode = new ListNode(value);
    newNode->nextPtr = firstPtr;
    firstPtr = newNode;
}

void OWList::removeFromFront() {
    if (!firstPtr) {
        return;
    }
    else if (firstPtr == lastPtr) {
        delete firstPtr;
        firstPtr = lastPtr = nullptr;
        return;
    }
    ListNode* freeTemp = firstPtr;
    firstPtr = firstPtr->nextPtr;
    delete freeTemp;
}

bool OWList::isEmpty() const {
    if (!firstPtr) {
        return true;
    }
    return false;
}

void OWList::print() const {
    if (!firstPtr) {
        return;
    }
    auto cur = firstPtr;
    for (; cur != lastPtr; cur = cur->nextPtr) {
        std::cout << cur->data << " ";
    }
    std::cout << cur->data;
}

void TWList::insertAtBack(const int &value) {
    if (!lastPtr) {
        firstPtr = lastPtr = new ListNode(value);
        return;
    }
    lastPtr->nextPtr = new ListNode(value);
    lastPtr = lastPtr->nextPtr;
}

void TWList::removeFromBack() {
    if (!firstPtr) {
        return;
    }
    else if (firstPtr == lastPtr) {
        delete firstPtr;
        firstPtr = lastPtr = nullptr;
    }
    auto cur = firstPtr;
    for (; cur->nextPtr != lastPtr; cur = cur->nextPtr);
    delete cur->nextPtr;
    lastPtr = cur;
}
