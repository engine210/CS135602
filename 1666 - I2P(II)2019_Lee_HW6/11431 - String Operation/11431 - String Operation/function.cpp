//
//  function.cpp
//  11431 - String Operation
//
//  Created by engine210 on 2019/4/27.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.hpp"

Str::Str(char* input) {
    head = new Char(input[0]);
    Char* cur = head;
    int i = 1;
    while (input[i] != '\0') {
        cur->next = new Char(input[i]);
        cur = cur->next;
        i++;
    }
    tail = cur;
}

Str::Str(const Str &B) {
    head = new Char((B.head)->text);
    Char* cur = head;
    Char* curB = (B.head)->next;
    while (curB) {
        cur->next = new Char(curB->text);
        curB = curB->next;
        cur = cur->next;
    }
    tail = cur;
}

bool Str::operator==(const Str &B) const {
    Char* cur = head;
    Char* curB = B.head;
    while (cur && curB) {
        if (cur->text != curB->text) {
            return false;
        }
        cur = cur->next;
        curB = curB->next;
    }
    if (cur || curB) {
        return false;
    }
    return true;
}
