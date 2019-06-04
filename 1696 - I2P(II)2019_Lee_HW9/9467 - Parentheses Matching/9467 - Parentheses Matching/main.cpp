//
//  main.cpp
//  9467 - Parentheses Matching
//
//  Created by engine210 on 2019/5/26.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <stack>
#include <stdio.h>

using namespace std;

int main(int argc, const char * argv[]) {
    
    int N, i = 1;
    char c;
    
    freopen("9467_sampleIn.txt", "r", stdin);
    
    cin >> N;
    getchar();
    while (i <= N) {
        stack<char> s;
        c = getchar();
        while (c != '\n') {
            if (c == '{' || c == '[' || c == '(' || c == '<') {
                s.push(c);
            }
            else if (c == '}') {
                if (!s.empty() && s.top() == '{') {
                    s.pop();
                }
                else {
                    s.push(c);
                }
            }
            else if (!s.empty() && c == ']') {
                if (s.top() == '[') {
                    s.pop();
                }
                else {
                    s.push(c);
                }
            }
            else if (!s.empty() && c == ')') {
                if (s.top() == '(') {
                    s.pop();
                }
                else {
                    s.push(c);
                }
            }
            else if (!s.empty() && c == '>'){
                if (s.top() == '<') {
                    s.pop();
                }
                else {
                    s.push(c);
                }
            }
            else {
                s.push(c);
            }
            c = getchar();
        }
        if (s.empty()) {
            cout << "Case " << i << ": Yes" << endl;
        }
        else {
            cout << "Case " << i << ": No" << endl;
        }
        i++;
    }
    return 0;
}
