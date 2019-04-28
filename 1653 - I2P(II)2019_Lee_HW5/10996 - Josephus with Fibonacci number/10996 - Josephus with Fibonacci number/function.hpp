//
//  function.hpp
//  10996 - Josephus with Fibonacci number
//
//  Created by engine210 on 2019/4/23.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef FUNCTION_H
#define FUNCTION_H
#include <iostream>
class Node {
friend class Josephus;
public:
    Node(): next(NULL) {
        
    }
    Node(const int &info): number(info), next(NULL) {
        
    } //end ListNode constructor
private:
    Node *next;
    int number;
};  //end class Node

class Josephus {
public:
    Josephus();
    ~Josephus();
    Josephus(const int &);
    int kill() ; // return the survival's position
    
private:
    void generatecircularlinkedList(const int &); // generate circular linked-list
    void generateFib(const int &); // generate a Fibonacci sequence table
    int sequence[50]; // store Fibonacci number
    int noOfPeople;
    Node *head;
};
#endif // FUNCTION_H

