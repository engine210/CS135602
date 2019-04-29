//
//  function.hpp
//  12224 - Doubly Linked List
//
//  Created by engine210 on 2019/4/29.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef function_h
#define function_h

#include <iostream>

class ListNode{
private:
    int data;
    ListNode *next;
    ListNode *prev;
public:
    ListNode():data(0),next(nullptr), prev(nullptr){};
    ListNode(int a):data(a),next(nullptr), prev(nullptr){};
    
    friend class List;
};

class List {
private:
    ListNode* head;  // head of the doubly linked list
    ListNode* tail;  // tail of the doubly linked list
    ListNode* middle; // middle of the list
    int       cnt;   // total count of the elements in the list
    int       pos;   // the position of middle
    
    void reset(){
        head = nullptr;
        tail = nullptr;
        middle = nullptr;
        cnt = 0;
        pos = 0;
    }
    
    void clean(){
        ListNode* temp;
        while(head!=nullptr){
            temp = head;
            head = head->next;
            delete temp;
        }
    }
    
public:
    // constructor and destructor
    List(){
        reset();
    }
    
    ~List(){
        clean();
    }
    
    void InsertHead(int data);
    int  RemoveHead();
    void InsertTail(int data);
    int  RemoveTail();
    void Swap();
    int  getSize();
    int  getMiddle();
    
    void show() {
        ListNode* cur = head;
        std::cout << "List: ";
        while (cur != nullptr) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << std::endl;
    }
};

#endif /* function_hpp */
