//
//  function.cpp
//  11495 - Missionaries and Cannibals - 6 points
//
//  Created by engine210 on 2019/5/31.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "function.hpp"

using namespace std;

void Crossing::solve() {
    State init = {_npeople[0], _npeople[1], 0, 0, 1};
    Go(init, 0, 0);
    _explored.clear();
}

set<State> Crossing::extend(State s) {
    set<State> temp;
    return temp;
}

State Crossing::Go(State s, int missionary, int cannibal) {
    static list<State> paths;
    
    s[0] += missionary * s[4];
    s[1] += cannibal * s[4];
    s[2] -= missionary * s[4];
    s[3] -= cannibal * s[4];
    
    if (found(s)) {
        paths.push_back(s);
        _solutions.insert(paths);
        paths.pop_back();
    }
    else if (valid(s)) {
        _explored.insert(s);
        paths.push_back(s);
        s[4] *= -1;
        Go(s, 0, 1);
        Go(s, 0, 2);
        Go(s, 1, 1);
        Go(s, 2, 0);
        Go(s, 1, 0);
        s[4] *= -1;
        _explored.erase(s);
        paths.pop_back();
    }
    
    return {0};
}

bool Crossing::valid(State s) {
    for (int i = 0; i < 4; i++) {
        if (s[i] < 0) {
            return false;
        }
    }
    if (s[0] > _npeople[0] || s[1] > _npeople[1] || s[2] > _npeople[0] || s[3] > _npeople[1]) {
        return false;
    }
    if (_explored.find(s) != _explored.end()) {
        return false;
    }
    if (s[0] != 0 && s[0] < s[1]) {
        return false;
    }
    if (s[2] != 0 && s[2] < s[3]) {
        return false;
    }
    
    return true;
}

bool Crossing::found(State s) {
    if (s[0] == 0 && s[1] == 0 && s[2] == _npeople[0] && s[3] == _npeople[1] && s[4] == -1) {
        return true;
    }
    else {
        return false;
    }
}
