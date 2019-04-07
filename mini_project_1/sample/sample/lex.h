//
//  lex.h
//  sample
//
//  Created by engine210 on 2019/4/7.
//  Copyright © 2019 engine210. All rights reserved.
//

#ifndef lex_h
#define lex_h

#define MAXLEN 256
typedef enum {UNKNOWN, END, INT, ID, ADDSUB, MULDIV, ASSIGN, LPAREN, RPAREN} TokenSet;

extern int match (TokenSet token);
extern void advance(void);
extern char* getLexeme(void);

#endif /* lex_h */
