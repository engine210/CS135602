//
//  function.h
//  11345 - Josephus Problem using doubly circular linked list
//
//  Created by engine210 on 2019/3/7.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef function_h
#define function_h

typedef struct man {
    int id;
    struct man* next;
    struct man* prev;
} man;

extern man* head;
man* createList(int n);
int solveJosephus(int step);

#endif /* function_h */
