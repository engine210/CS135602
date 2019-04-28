//
//  function.hpp
//  11431 - String Operation
//
//  Created by engine210 on 2019/4/27.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>
using namespace std;

class Char{
    friend class Str;
private:
    Char(char text):next(NULL){
        this->text=text;
    }
    
    ~Char(){
        if(next)
            delete next;
    }
    
    void print(){
        cout<<text;
        if(next)
            next->print();
    }
    
    char text;
    Char *next;
};

class Str{
public:
    // construct a new Str by linked list of Char
    Str(char*);
    
    // copy constructor
    // have to copy all Chars of another Str
    Str(const Str &);
    
    // equality operator
    bool operator==( const Str & ) const;
    
    
    /** the following methods are already implemented **/
    Str():head(NULL),tail(NULL){} // default constructor
    
    ~Str(){
        if(head)
            delete head;
    }
    
    Str& strInsert(const Str &s){
        Str tmp(s);
        
        tail->next=tmp.head;
        tail=tmp.tail;
        
        tmp.head=NULL;
        return *this;
    }
    
    Str& strSwap(Str &s){
        Str tmp(*this);
        this->~Str();
        
        *this=s;
        s=tmp;
        
        tmp.head=NULL;
        return *this;
    }
    
    void strPrint(){
        if(head)
            head->print();
        cout<<endl;
    }
    
private:
    Char *head;
    Char *tail;
};

#endif /* function_hpp */
