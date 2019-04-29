//
//  function.cpp
//  12224 - Doubly Linked List
//
//  Created by engine210 on 2019/4/29.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.hpp"
#include <stdexcept>


void List::InsertHead(int data) {
    if (cnt == 0) {
        head = new ListNode(data);
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
        middle = head;
        cnt++;
        pos = 1;
    }
    else {
        head->prev = new ListNode(data);
        head->prev->next = head;
        head = head->prev;
        head->prev = nullptr;
        cnt++;
        pos++;
        if (pos - 1 - cnt/2) {
            middle = middle->prev;
            pos--;
        }
    }
}

void List::InsertTail(int data) {
    if (cnt == 0) {
        head = new ListNode(data);
        head->next = nullptr;
        head->prev = nullptr;
        tail = head;
        middle = head;
        cnt++;
        pos = 1;
    }
    else {
        tail->next = new ListNode(data);
        tail->next->prev = tail;
        tail = tail->next;
        tail->next = nullptr;
        cnt++;
        if (1 + cnt/2 - pos) {
            middle = middle->next;
            pos++;
        }
    }
}

int List::RemoveHead() {
    if (cnt == 0) {
        throw std::out_of_range("");
    }
    if (cnt == 1) {
        int num = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
        middle = nullptr;
        cnt = 0;
        pos = 0;
        return num;
    }
    else {
        int num = head->data;
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        cnt--;
        pos--;
        if (1 + cnt/2 - pos) {
            pos++;
            middle = middle->next;
        }
        return num;
    }
}

int List::RemoveTail() {
    if (cnt == 0) {
        throw std::out_of_range("");
    }
    if (cnt == 1) {
        int num = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
        middle = nullptr;
        cnt = 0;
        pos = 0;
        return num;
    }
    else {
        int num = tail->data;
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        cnt--;
        if (pos - 1 - cnt/2) {
            pos--;
            middle = middle->prev;
        }
        return num;
    }
}

void List::Swap() {
    if (cnt == 0 || cnt == 1) {
        return;
    }
    else if (cnt == 2) {
        head->prev = tail;
        tail->next = head;
        head->next = nullptr;
        tail->prev = nullptr;
        head = tail;
        tail = head->next;
        middle = tail;
        return;
    }
    else {
        head->prev = tail;
        tail->next = head;
        ListNode* newTail = middle->prev;
        newTail->next = nullptr;
        middle->prev = nullptr;
        if (cnt % 2) {
            head = middle;
            middle = tail;
            tail = newTail;
        }
        else {
            head = middle;
            middle = tail->next;
            tail = newTail;
        }
    }
}

int List::getSize() {
    return cnt;
}

int List::getMiddle() {
    return pos;
}
