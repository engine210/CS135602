//
//  lex.h
//  mini_project_1_v2
//
//  Created by engine210 on 2019/4/7.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef lex_h
#define lex_h

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLEN 256
#define TBLSIZE 65535

typedef enum {UNKNOWN, END, INT, ID, ADDSUB, MULDIV, ASSIGN, LPAREN, RPAREN, AND, OR, XOR} TokenSet;

typedef enum {MISPAREN, NOTNUMID, NOTFOUND, RUNOUT, NAN} ErrorType;

typedef struct {
    char name[MAXLEN];
    int val;
} Symbol;

typedef struct _Node {
    char lexeme[MAXLEN];
    TokenSet token;
    int val;
    struct _Node *left, *right;
} BTNode;

extern int match (TokenSet token);
extern void advance(void);
extern char* getLexeme(void);


#endif /* lex_h */
