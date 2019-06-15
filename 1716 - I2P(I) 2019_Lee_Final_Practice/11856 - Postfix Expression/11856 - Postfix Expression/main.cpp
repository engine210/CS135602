//
//  main.cpp
//  11856 - Postfix Expression
//
//  Created by engine210 on 2019/6/13.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, const char * argv[]) {
    
    string in;
    stack<int> s;
    int x, y;
    
    cin >> in;
    while (in != "0") {
        
        if (in == "+") {
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            s.push(x+y);
        }
        else if (in == "-") {
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            s.push(y-x);
        }
        else if (in == "*") {
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            s.push(x*y);
        }
        else if (in == "/") {
            x = s.top();
            s.pop();
            y = s.top();
            s.pop();
            s.push(y/x);
        }
        else {
            s.push(stoi(in));
        }
        cin >> in;
    }
    
    cout << s.top() << endl;
    
    return 0;
}
