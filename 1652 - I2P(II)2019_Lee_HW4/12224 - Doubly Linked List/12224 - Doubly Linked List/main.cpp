//
//  main.cpp
//  12224 - Doubly Linked List
//
//  Created by engine210 on 2019/4/15.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdexcept>
#include "function.hpp"

using namespace std;

int main(){
    List L;
    string cmd;
    int data, cnt=0, pos = 0;
    
    //freopen("12224_sampleIn.txt", "r", stdin);
    
    while(cin >> cmd){
        if(cmd=="IH"){ // insert an integer to the head
            cin >> data;
            L.InsertHead(data);
        } else if (cmd=="IT"){ // insert an integer to the end
            cin >> data;
            L.InsertTail( data);
        } else if (cmd=="RH"){   // print and remove a node from head
            try {
                cout<< L.RemoveHead() <<endl;
            } catch (const out_of_range &e){
                cout << endl;
            }
        } else if (cmd=="RT") {// print and remove a node from tail
            try {
                cout << L.RemoveTail()<<endl;
            } catch (const out_of_range &e){
                cout << endl;
            }
        } else if (cmd=="S"){
            L.Swap();
        }
        /*
        cout << cmd << endl;
        cout << "middle is: " << L.getMiddle() << endl;
        L.show();
        cout << endl;
        */
    }
}


/*

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class Node {
friend class List;
public:
    Node():data(0),next(nullptr),prev(nullptr){};
    Node(int data, Node* next, Node* prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
private:
    int data;
    Node* next;
    Node* prev;
};

class List {
public:
    List():len(0),head(nullptr),tail(nullptr),middle(nullptr){};
    void insertHead(int);
    void insertTail(int);
    void removeHead();
    void removeTail();
    void swap();
private:
    int len;
    Node* head;
    Node* tail;
    Node* middle;
};

void List::insertHead(int i) {
    if (head == nullptr) {
        len = 1;
        head = new Node(i, nullptr, nullptr);
        middle = tail = head;
    }
    else {
        len++;
        head->prev = new Node(i, head, nullptr);
        head = head->prev;
        if (len % 2) {
            middle = middle->prev;
        }
    }
}

void List::insertTail(int i) {
    if (head == nullptr) {
        len = 1;
        head = new Node(i, nullptr, nullptr);
        middle = tail = head;
    }
    else {
        len++;
        tail->next = new Node(i, nullptr, tail);
        tail = tail->next;
        if (len % 2 == 0) {
            middle = middle->next;
        }
    }
}

void List::removeHead() {
    if (head == nullptr) {
        cout << endl;
    }
    else if (head->next == nullptr) {
        cout << head->data << endl;
        delete head;
        head = tail = middle = nullptr;
    }
    else {
        cout << head->data << endl;
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        len--;
        if (len % 2 == 0) {
            middle = middle->next;
        }
    }
}

void List::removeTail() {
    if (tail == nullptr) {
        cout << endl;
    }
    else if (tail->prev == nullptr) {
        cout << tail->data << endl;
        delete tail;
        head = tail = middle = nullptr;
    }
    else {
        cout << tail->data << endl;
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        len--;
        if (len % 2) {
            middle = middle->prev;
        }
    }
}

void List::swap() {
    if (len % 2) {
        Node* newMid = tail;
        tail->next = head;
        head->prev = tail;
        tail = middle->prev;
        tail->next = nullptr;
        middle->prev = nullptr;
        head = middle;
        middle = newMid;
    }
    else {
        Node* newMid = head;
        tail->next = head;
        head->prev = tail;
        tail = middle->prev;
        tail->next = nullptr;
        middle->prev = nullptr;
        head = middle;
        middle = newMid;
    }
    
}

int main(int argc, const char * argv[]) {
    
    string cmd;
    int i;
    List data;
    
    //freopen("12224_sampleIn.txt", "r", stdin);
    
    while (cin >> cmd) {
        if (cmd == "IH") {
            cin >> i;
            data.insertHead(i);
        }
        else if (cmd == "IT") {
            cin >> i;
            data.insertTail(i);
        }
        else if (cmd == "RH") {
            data.removeHead();
        }
        else if (cmd == "RT") {
            data.removeTail();
        }
        else if (cmd == "S") {
            data.swap();
        }
    }
    
    return 0;
}

*/
