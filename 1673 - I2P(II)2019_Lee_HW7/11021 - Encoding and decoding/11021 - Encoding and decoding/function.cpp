//
//  function.cpp
//  11021 - Encoding and decoding
//
//  Created by engine210 on 2019/5/8.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
#include "function.hpp"

void RleCodec::encode() {
    std::ostringstream os;
    char pre = code_str[0];
    int cnt = 0;
    char strNum;
    
    for (auto c : code_str) {
        if (cnt == 26) {
            os << 'Q' << 'Z' << pre;
            cnt = 1;
            pre = c;
        }
        else if (c == pre) {
            cnt++;
        }
        else {
            os << 'Q';
            strNum = 'A' + cnt - 1;
            os << strNum;
            os << pre;
            cnt = 1;
            pre = c;
        }
    }
    os << 'Q';
    strNum = 'A' + cnt - 1;
    os << strNum;
    os << pre;
    code_str = os.str();
    encoded = true;
}

void RleCodec::decode() {
    std::stringstream os;
    std::string int_str;
    char q = 'A';
    char number = ' ';
    int cnt = 0;
    for (auto c : code_str) {
        if (q=='A') {
            q = c;
        }else if(number == ' '){
            number = c;
        }
        else {
            int_str.push_back(c);
            int cnt = 0;
            cnt = number - 'A' +1;
            for (int i=0; i<cnt; ++i)
                os << c;
            int_str.clear();
            number = ' ';
            q = 'A';
        }
    }
    
    code_str = os.str();
    encoded = false;
}
