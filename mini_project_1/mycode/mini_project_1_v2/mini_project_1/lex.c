//
//  lex.c
//  mini_project_1
//
//  Created by engine210 on 2019/4/5.
//  Copyright © 2019 engine210. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "lex.h"
static TokenSet getToken(void);
static TokenSet lookahead = UNKNOWN;
static char lexeme[MAXLEN];

//get a token from the input, save the token in lexeme and return the type of token
TokenSet getToken(void) {
    int i;
    char c;
    
    while ((c = fgetc(stdin)) == ' ' || c == '\t');  // eat white space and tab
    
    if (isdigit(c)) {
        lexeme[0] = c;
        c = fgetc(stdin);
        i = 1;
        while (isdigit(c) && i < MAXLEN) {
            lexeme[i] = c;
            i++;
            c = fgetc(stdin);
        }
        ungetc(c, stdin);
        lexeme[i] = '\0';
        return INT;
    }
    else if (c == '|') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return OR;
    }
    else if (c == '^') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return XOR;
    }
    else if (c == '&') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return AND;
    }
    else if (c == '+' || c == '-') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return ADDSUB;
    }
    else if (c == '*' || c == '/') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return MULDIV;
    }
    else if (c == '\n') {
        lexeme[0] = '\0';
        return END;
    }
    else if (c == '=') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        //strcpy(lexeme, "=");
        return ASSIGN;
    }
    else if (c == '(') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        //strcpy(lexeme, "(");
        return LPAREN;
    }
    else if (c == ')') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        //strcpy(lexeme, ")");
        return RPAREN;
    }
    else if (isalpha(c) || c == '_') {
        lexeme[0] = c;
        c = fgetc(stdin);
        i = 1;
        while (isalpha(c) || isdigit(c) || c == '_') {
            lexeme[i] = c;
            i++;
            c = fgetc(stdin);
        }
        ungetc(c, stdin);
        lexeme[i] = '\0';
        return ID;
    }
    else {
        return UNKNOWN;
    }
}

//get a token and set lookahead
void advance(void) {
    lookahead = getToken();
}

//to see if the lookahead is match to the given token or not
int match(TokenSet token) {
    if (lookahead == UNKNOWN) advance();
    return token == lookahead;
}

//get the golbal variable lexeme
char* getLexeme(void) {
    return lexeme;
}
