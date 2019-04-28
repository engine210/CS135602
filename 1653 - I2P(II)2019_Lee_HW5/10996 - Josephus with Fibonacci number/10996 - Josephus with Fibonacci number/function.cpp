//
//  function.cpp
//  10996 - Josephus with Fibonacci number
//
//  Created by engine210 on 2019/4/23.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.hpp"

Josephus::Josephus(const int &num) {
    noOfPeople = num;
    generatecircularlinkedList(num);
    generateFib(num);
}

void Josephus::generateFib(const int &num) {
    int i = 2;
    sequence[0] = 1;
    sequence[1] = 1;
    while (i <= num) {
        sequence[i] = sequence[i-1] + sequence[i-2];
        i++;
    }
}

void Josephus::generatecircularlinkedList(const int &num) {
    int i = 1;
    head = new Node(i++);
    Node* cur = head;
    
    while (i <= num) {
        cur->next = new Node(i++);
        cur = cur->next;
    }
    cur->next = head;
    head = cur;
}

int Josephus::kill() {
    int i, j, k;
    Node* cur = head;
    Node* freetemp;
    
    i = 0;
    while (noOfPeople != 1) {
        j = 1;
        k = (sequence[i] % noOfPeople);
        if (k == 0) {
            k = noOfPeople;
        }
        while (j < k) {
            cur = cur->next;
            j++;
        }
        freetemp = cur->next;
        cur->next = cur->next->next;
        delete freetemp;
        i++;
        noOfPeople--;
    }
    head = cur;
    return cur->number;
}

Josephus::~Josephus() {
    delete head;
}
