//
//  main.cpp
//  11020 - Binary search trees using polymorphism
//
//  Created by engine210 on 2019/5/3.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <string.h>
#include "function.hpp"

using namespace std;

void BSTManipulator(BST& bstobj1,BST& bstobj2, char cmd ){
    int n;
    if (cmd == 'I') {
        cin >> n;
        bstobj1.insert(n);
        bstobj2.insert(n);
    }else if (cmd == 'S'){
        cin >> n;
        if (bstobj1.search(n)) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
        
        if (bstobj2.search(n)) {
            cout << "yes" << endl;
        }else{
            cout << "no" << endl;
        }
        
    }else if (cmd == 'H'){
        cout << bstobj1.height() << endl;;
        cout << bstobj2.height() << endl;;
        
    }else if (cmd == 'P'){
        bstobj1.print();
        cout << endl;
        bstobj2.print();
        cout << endl;
    }
}
int main(){
    Array_BST A_bst;
    List_BST B_bst;
    char cmd;
    
    while (cin >> cmd)
        BSTManipulator(A_bst, B_bst, cmd);
    
    return 0;
}
