//
//  main.cpp
//  10664 - easy 8 Puzzles
//
//  Created by engine210 on 2019/6/12.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

using map = vector<vector<int>>;

int min_step;

bool valid(map data) {
    if (data[0][0] == 1 && data[0][1] == 2 && data[0][2] == 3 &&
        data[1][0] == 4 && data[1][1] == 5 && data[1][2] == 6 &&
        data[2][0] == 7 && data[2][1] == 8 && data[2][2] == 0) {
        return true;
    }
    return false;
}

set<map> explored;
queue<map> path;
queue<int> step;

void insert(map cur, int cur_step) {
    if (explored.find(cur) == explored.end()) {
        path.push(cur);
        step.push(cur_step);
        explored.insert(cur);
    }
}

bool solve(map origin) {
    
    map cur;
    int cur_step;
    explored.clear();
    queue<map>().swap(path);
    queue<int>().swap(step);
    path.push(origin);
    step.push(0);
    
    while (!path.empty()) {
        cur = path.front();
        path.pop();
        cur_step = step.front();
        step.pop();
        
        if (cur_step > 14) return false;
        else if (valid(cur)) {
            min_step = cur_step;
            return true;
        }
        cur_step++;
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (cur[i][j] == 0) {
                    goto end;
                }
            }
        }
    end:
        if (i != 2) {
            swap(cur[i][j], cur[i+1][j]);
            insert(cur, cur_step);
            swap(cur[i][j], cur[i+1][j]);
        }
        if (i != 0) {
            swap(cur[i][j], cur[i-1][j]);
            insert(cur, cur_step);
            swap(cur[i][j], cur[i-1][j]);
        }
        
        if (j != 2) {
            swap(cur[i][j], cur[i][j+1]);
            insert(cur, cur_step);
            swap(cur[i][j], cur[i][j+1]);
        }
        if (j != 0) {
            swap(cur[i][j], cur[i][j-1]);
            insert(cur, cur_step);
            swap(cur[i][j], cur[i][j-1]);
        }
    }
    return false;
}


int main(int argc, const char * argv[]) {
    
    int T;
    map origin(3);
    origin[0] = vector<int>(3);
    origin[1] = vector<int>(3);
    origin[2] = vector<int>(3);
    
    cin >> T;
    
    while (T--) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> origin[i][j];
            }
        }
        
        if (solve(origin)) {
            cout << "You can solve it within " << min_step <<  " steps." << endl;
        }
        else {
            cout << "You'd better skip this game." << endl;
        }
    }
    
    return 0;
}
