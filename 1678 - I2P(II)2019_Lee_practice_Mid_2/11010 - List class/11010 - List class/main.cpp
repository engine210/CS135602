//
//  main.cpp
//  11010 - List class
//
//  Created by engine210 on 2019/5/13.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <string>
#include "function.hpp"
using namespace std;
int main()
{
    TWList integerList;
    int command;
    int value; // store node value
    freopen("11010_sampleIn.txt", "r", stdin);
    while (cin >> command)
    {
        switch(command)
        {
            case 1: // insert at beginning
                cin >> value;
                integerList.insertAtFront(value);
                break;
            case 2: // insert at end
                cin >> value;
                integerList.insertAtBack(value);
                break;
            case 3: // remove from beginning
                integerList.removeFromFront();
                break;
            case 4: // remove from end
                integerList.removeFromBack();
                break;
        }
    }
    integerList.print();
    cout<<endl;
}

