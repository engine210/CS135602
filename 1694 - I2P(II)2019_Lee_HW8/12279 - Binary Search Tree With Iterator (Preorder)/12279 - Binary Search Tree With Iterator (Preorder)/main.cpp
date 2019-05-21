//
//  main.cpp
//  12279 - Binary Search Tree With Iterator (Preorder)
//
//  Created by engine210 on 2019/5/17.
//  Copyright © 2019 engine210. All rights reserved.
//
/*
#include <iostream>
#include "function.hpp"

using namespace std;

int main()
{
    
    int G, N, tmp;
    
    BST bst;
    
    cin>>N>>G;
    
    for(int i=0;i<N;++i)
    {
        cin>>tmp;
        bst.push_back(tmp);
    }
    
    auto it = bst.begin();
    auto end = bst.end();
    while( it != end )
    {
        cout << *it + G << endl;
        it++;
    }
    
    return 0;
}
*/
#include <iostream>
#include "function.hpp"

using namespace std;

int main()
{
    
    int G, N, tmp;
    
    BST bst;
    
    cin>>N>>G;
    
    for(int i=0;i<N;++i)
    {
        cin>>tmp;
        bst.push_back(tmp);
    }
    
    auto it = bst.begin();
    auto it2 = bst.begin();
    auto end = bst.end();
    while( it != end )
    {
        if( it2 != end ) it2++;
        if( it2 != end ) it2++;
        cout << *it + G << endl;
        it++;
    }
    
    return 0;
}
