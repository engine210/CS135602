//
//  main.c
//  mini_project_1_v2_submit
//
//  Created by engine210 on 2019/4/14.
//  Copyright © 2019 engine210. All rights reserved.
//


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLEN 256
#define TBLSIZE 65535

typedef enum {UNKNOWN, END, INT, ID, ADDSUB, MULDIV, ASSIGN, LPAREN, RPAREN, AND, OR, XOR} TokenSet;

typedef struct {
    TokenSet token; //ID: contain x, y or z; INT: is a number;
    int value;
} NodeVal;

typedef struct {
    TokenSet token; //ID: contain x, y or z; INT: is a number;
    int reg;
    int value;
} assert;

typedef struct {
    char name[MAXLEN];
    int hasVal;
    int val;
} Symbol;

typedef struct _Node {
    char lexeme[MAXLEN];
    TokenSet token;
    int val;
    struct _Node *left, *right;
} BTNode;


//function from lex
int match (TokenSet token);
void advance(void);
char* getLexeme(void);
TokenSet getToken(void);
TokenSet lookahead = UNKNOWN;

//recursion function to build syntax tree
void statement(void);
BTNode* bit_or(void);
BTNode* bit_xor(void);
BTNode* bit_and(void);
BTNode* expr(void);
BTNode* term(void);
BTNode* factor(void);

//assistant function
BTNode* makeNode(TokenSet, const char*);
int getval(void);
int setval(char*, int);
void freeTree(BTNode*);
void printPrefix(BTNode*);
void table_init(void);
assert printAssemble(BTNode* root);

//some local variable
char lexeme[MAXLEN];
Symbol table[TBLSIZE];
int sbcount = 0;
int reg_available[8]; //indicate r0~r7 is available or not
int syntax_error = 0;
int firstID; //this ID is first ID appear in this expression or not
int firstAssign;
int firstExpr;

int main(int argc, char* argv[]) {
    char c;
    int i;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    table_init();
    firstExpr = 1;
    while (scanf("%c", &c) != EOF) {    //to determine whether the input is end
        ungetc(c, stdin);
        firstID = 1;
        firstAssign = 1;
        for (i = 0; i < 3; i++) reg_available[i] = 0;
        for (i = 3; i < 8; i++) reg_available[i] = 1;   //set all register usable
        statement();
        if (syntax_error) {
            printf("EXIT 1\n");
            break;
        }
        
    }
    
    if (!syntax_error) {
        printf("EXIT 0\n");
    }
    
    return 0;
}

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
        return ASSIGN;
    }
    else if (c == '(') {
        lexeme[0] = c;
        lexeme[1] = '\0';
        return LPAREN;
    }
    else if (c == ')') {
        lexeme[0] = c;
        lexeme[1] = '\0';
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

//set x, y, z to the table
void table_init() {
    table[0].name[0] = 'x';
    table[0].name[1] = '\0';
    table[0].val = 0;
    table[0].hasVal = 0;
    table[1].name[0] = 'y';
    table[1].name[1] = '\0';
    table[1].val = 0;
    table[1].hasVal = 0;
    table[2].name[0] = 'z';
    table[2].name[1] = '\0';
    table[2].val = 0;
    table[2].hasVal = 0;
    sbcount = 3;
}

void statement(void) {
    BTNode* retp;
    if (match(END)) {
        advance();
    }
    else {
        retp = bit_or();
        if (match(END)) {
            if (retp->token != ASSIGN || retp->left->token != ID) {
                syntax_error = 1;
            }
            if (!syntax_error) {
                if (firstExpr) {
                    printf("MOV r0 [0]\n");
                    printf("MOV r1 [4]\n");
                    printf("MOV r2 [8]\n");
                    firstExpr = 0;
                }
                printAssemble(retp);
            }
            
            freeTree(retp);
            advance();
        }
    }
}

BTNode* bit_or() {
    BTNode *retp, *left;
    retp = left = bit_xor();
    while (match(OR)) { // tail recursion => while
        retp = makeNode(OR, getLexeme());
        advance();
        retp->right = bit_xor();
        retp->left = left;
        left = retp;
    }
    return retp;
}

BTNode* bit_xor() {
    BTNode *retp, *left;
    retp = left = bit_and();
    while (match(XOR)) { // tail recursion => while
        retp = makeNode(XOR, getLexeme());
        advance();
        retp->right = bit_and();
        retp->left = left;
        left = retp;
    }
    return retp;
}

BTNode* bit_and() {
    BTNode *retp, *left;
    retp = left = expr();
    while (match(AND)) { // tail recursion => while
        retp = makeNode(AND, getLexeme());
        advance();
        retp->right = expr();
        retp->left = left;
        left = retp;
    }
    return retp;
}

//  expr        := term expr_tail
//  expr_tail   := ADDSUB term expr_tail | NIL
BTNode* expr(void) {
    BTNode *retp, *left;
    retp = left = term();
    while (match(ADDSUB)) { // tail recursion => while
        retp = makeNode(ADDSUB, getLexeme());
        advance();
        retp->right = term();
        retp->left = left;
        left = retp;
    }
    return retp;
}

//  term        := factor term_tail
//  term_tail := MULDIV factor term_tail | NIL
BTNode* term(void) {
    BTNode *retp, *left;
    retp = left = factor();
    while (match(MULDIV)) { // tail recursion => while
        retp = makeNode(MULDIV, getLexeme());
        advance();
        retp->right = factor();
        retp->left = left;
        left = retp;
    }
    return retp;
}

BTNode* factor(void) {
    BTNode* retp = NULL;
    char tmpstr[MAXLEN];
    
    if (match(INT)) {
        retp = makeNode(INT, getLexeme());
        retp->val = getval();
        advance();
    }
    else if (match(ID)) {
        BTNode* left = makeNode(ID, getLexeme());
        left->val = getval();
        firstID = 0;
        strcpy(tmpstr, getLexeme());
        advance();
        if (match(ASSIGN)) {
            if (firstAssign) {
                firstAssign = 0;
            }
            else {
                syntax_error = 1;
            }
            retp = makeNode(ASSIGN, getLexeme());
            advance();
            retp->right = bit_or();
            retp->left = left;
        }
        else {
            retp = left;
        }
    }
    else if (match(ADDSUB)) {
        strcpy(tmpstr, getLexeme());
        advance();
        if (match(ID) || match(INT)) {
            retp = makeNode(ADDSUB, tmpstr);
            if (match(ID)) {
                retp->right = makeNode(ID, getLexeme());
            }
            else {
                retp->right = makeNode(INT, getLexeme());
            }
            retp->right->val = getval();
            retp->left = makeNode(INT, "0");
            retp->left->val = 0;
            advance();
        }
        else {
            syntax_error = 1;
        }
    }
    else if (match(LPAREN)) {
        advance();
        retp = bit_or();
        if (match(RPAREN)) {
            advance();
        }
        else {
            syntax_error = 1;
        }
    }
    else {
        syntax_error = 1;
    }
    return retp;
}

/* create a node without any child */
BTNode* makeNode(TokenSet tok, const char *lexe) {
    BTNode *node = (BTNode*) malloc(sizeof(BTNode));
    strcpy(node->lexeme, lexe);
    node->token= tok;
    node->val = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* clean a tree */
void freeTree(BTNode *root) {
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

/* print a tree by pre-order */
void printPrefix(BTNode *root) {
    if (root != NULL) {
        printf("%s ", root->lexeme);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/*get the value of the token, if the token is an interger, then return it's value
 if the token is an ID, then return it's value, or add this ID to table */
int getval(void) {
    int i, retval = 0, found;
    
    if (match(INT)) {
        retval = atoi(getLexeme());
    }
    else if (match(ID)) {
        i = 0;
        found = 0;
        retval = 0;
        while (i<sbcount && !found) {
            if (strcmp(getLexeme(), table[i].name) == 0) {
                retval = table[i].val;
                found = 1;
                break;
            }
            else {
                i++;
            }
        }
        if (!found) {
            if (!firstID) {
                syntax_error = 1;
            }
            if (sbcount < TBLSIZE) {
                strcpy(table[sbcount].name, getLexeme());
                table[sbcount].val = 0;
                table[sbcount].hasVal = 0;
                sbcount++;
            }
            else {
                syntax_error = 1;
            }
        }
    }
    return retval;
}

int setval(char *str, int val) {
    int i, retval = 0;
    i = 0;
    while (i < sbcount) {
        if (strcmp(str, table[i].name) == 0) {
            table[i].val = val;
            retval = val;
            break;
        }
        else {
            i++;
        }
    }
    return retval;
}

assert printAssemble(BTNode* root) {
    
    char c = root->lexeme[0];
    /*
     reg1 is the first register appear after the OP,
     and reg2 is the second.
    */
    int i, j;
    assert reg1, reg2;
    
    if (root->token == INT) {
        reg1.token = INT;
        reg1.value = root->val;
        return reg1;
    }
    
    if (c == '|') {
        reg1 = printAssemble(root->left);
        reg2 = printAssemble(root->right);
        
        if (reg1.token == INT && reg2.token == INT) {
            reg1.token = INT;
            reg1.value = reg1.value | reg2.value;
            return reg1;
        }
        else if (reg1.token == INT && reg2.token == ID) {
            //to find which register is available to use
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            printf("MOV r%d %d\n", i, reg1.value);
            printf("OR r%d r%d\n", reg2.reg, i);
            return reg2;
        }
        else if (reg1.token == ID && reg2.token == INT) {
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            printf("MOV r%d %d\n", i, reg2.value);
            printf("OR r%d r%d\n", reg1.reg, i);
            return reg1;
        }
        else {
            printf("OR r%d r%d\n", reg1.reg, reg2.reg);
            reg_available[reg2.reg] = 1;
            reg1.token = ID;
            return reg1;
        }
    }
    else if (c == '^') {
        reg1 = printAssemble(root->left);
        reg2 = printAssemble(root->right);
        
        if (reg1.token == INT && reg2.token == INT) {
            reg1.token = INT;
            reg1.value = reg1.value ^ reg2.value;
            return reg1;
        }
        else if (reg1.token == INT && reg2.token == ID) {
            //to find which register is available to use
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            printf("MOV r%d %d\n", i, reg1.value);
            printf("XOR r%d r%d\n", reg2.reg, i);
            return reg2;
        }
        else if (reg1.token == ID && reg2.token == INT) {
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            printf("MOV r%d %d\n", i, reg2.value);
            printf("XOR r%d r%d\n", reg1.reg, i);
            return reg1;
        }
        else {
            printf("XOR r%d r%d\n", reg1.reg, reg2.reg);
            reg_available[reg2.reg] = 1;
            return reg1;
        }
    }
    else if (c == '&') {
        reg1 = printAssemble(root->left);
        reg2 = printAssemble(root->right);
        
        if (reg1.token == INT && reg2.token == INT) {
            reg1.token = INT;
            reg1.value = reg1.value & reg2.value;
            return reg1;
        }
        else if (reg1.token == INT && reg2.token == ID) {
            //to find which register is available to use
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            printf("MOV r%d %d\n", i, reg1.value);
            printf("AND r%d r%d\n", reg2.reg, i);
            return reg2;
        }
        else if (reg1.token == ID && reg2.token == INT) {
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            printf("MOV r%d %d\n", i, reg2.value);
            printf("AND r%d r%d\n", reg1.reg, i);
            return reg1;
        }
        else {
            printf("AND r%d r%d\n", reg1.reg, reg2.reg);
            reg_available[reg2.reg] = 1;
            return reg1;
        }
    }
    else if (c == '+') {
        reg1 = printAssemble(root->left);
        reg2 = printAssemble(root->right);
        
        if (reg1.token == INT && reg2.token == INT) {
            reg1.token = INT;
            reg1.value = reg1.value + reg2.value;
            return reg1;
        }
        else if (reg1.token == INT && reg2.token == ID) {
            //to find which register is available to use
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            printf("MOV r%d %d\n", i, reg1.value);
            printf("ADD r%d r%d\n", reg2.reg, i);
            return reg2;
        }
        else if (reg1.token == ID && reg2.token == INT) {
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            printf("MOV r%d %d\n", i, reg2.value);
            printf("ADD r%d r%d\n", reg1.reg, i);
            return reg1;
        }
        else {
            printf("ADD r%d r%d\n", reg1.reg, reg2.reg);
            reg_available[reg2.reg] = 1;
            return reg1;
        }
    }
    else if (c == '-') {
        reg1 = printAssemble(root->left);
        reg2 = printAssemble(root->right);
        
        if (reg1.token == INT && reg2.token == INT) {
            reg1.token = INT;
            reg1.value = reg1.value - reg2.value;
            return reg1;
        }
        else if (reg1.token == INT && reg2.token == ID) {
            //to find which register is available to use
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            reg_available[i] = 0;
            printf("MOV r%d %d\n", i, reg1.value);
            printf("SUB r%d r%d\n", i, reg2.reg);
            reg_available[reg2.reg] = 1;
            reg1.token = ID;
            reg1.reg = i;
            return reg1;
        }
        else if (reg1.token == ID && reg2.token == INT) {
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            printf("MOV r%d %d\n", i, reg2.value);
            printf("SUB r%d r%d\n", reg1.reg, i);
            return reg1;
        }
        else {
            printf("SUB r%d r%d\n", reg1.reg, reg2.reg);
            reg_available[reg2.reg] = 1;
            return reg1;
        }
    }
    else if (c == '*') {
        reg1 = printAssemble(root->left);
        reg2 = printAssemble(root->right);
        
        if (reg1.token == INT && reg2.token == INT) {
            reg1.token = INT;
            reg1.value = reg1.value * reg2.value;
            return reg1;
        }
        else if (reg1.token == INT && reg2.token == ID) {
            //to find which register is available to use
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            printf("MOV r%d %d\n", i, reg1.value);
            printf("MUL r%d r%d\n", reg2.reg, i);
            return reg2;
        }
        else if (reg1.token == ID && reg2.token == INT) {
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            printf("MOV r%d %d\n", i, reg2.value);
            printf("MUL r%d r%d\n", reg1.reg, i);
            return reg1;
        }
        else {
            printf("MUL r%d r%d\n", reg1.reg, reg2.reg);
            reg_available[reg2.reg] = 1;
            return reg1;
        }
    }
    else if (c == '/') {
        reg1 = printAssemble(root->left);
        reg2 = printAssemble(root->right);
        
        if (reg1.token == INT && reg2.token == INT) {
            reg1.token = INT;
            if (reg2.value == 0) {
                syntax_error = 1;
                printf("EXIT 1\n");
                exit(0);
            }
            reg1.value = reg1.value / reg2.value;
            return reg1;
        }
        else if (reg1.token == INT && reg2.token == ID) {
            //to find which register is available to use
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            reg_available[i] = 0;
            printf("MOV r%d %d\n", i, reg1.value);
            printf("DIV r%d r%d\n", i, reg2.reg);
            reg_available[reg2.reg] = 1;
            reg1.token = ID;
            reg1.reg = i;
            return reg1;
        }
        else if (reg1.token == ID && reg2.token == INT) {
            for (i = 0; i < 8; i++) {
                if (reg_available[i]) break;
            }
            if (reg2.value == 0) {
                syntax_error = 1;
                printf("EXIT 1\n");
                exit(0);
            }
            printf("MOV r%d %d\n", i, reg2.value);
            printf("DIV r%d r%d\n", reg1.reg, i);
            return reg1;
        }
        else {
            printf("DIV r%d r%d\n", reg1.reg, reg2.reg);
            reg_available[reg2.reg] = 1;
            return reg1;
        }
    }
    else if (c == '=') {
        //find the memory address of the variable appear before '='
        for (i = 0; i < sbcount; i++) {
            if (strcmp(root->left->lexeme, table[i].name) == 0) {
                break;
            }
        }
        reg2 = printAssemble(root->right);
        if (reg2.token == ID) {
            if (i < 3) {
                printf("MOV r%d r%d\n", i, reg2.reg);
            }
            else {
                printf("MOV [%d] r%d\n", i*4, reg2.reg);
            }
            table[i].hasVal = 0;
        }
        else {
            for (j = 0; j < 8; j++) {
                if (reg_available[j]) break;
            }
            printf("MOV r%d %d\n", j, reg2.value);
            if (i < 3) {
                printf("MOV r%d r%d\n", i, j);
            }
            else {
                printf("MOV [%d] r%d\n", i*4, j);
            }
            table[i].hasVal = 1;
            table[i].val = reg2.value;
        }
    }
    else if (isalpha(c) || c == '_') {
        for (j = 0; j < sbcount; j++) {
            if (strcmp(root->lexeme, table[j].name) == 0) {
                break;
            }
        }
        
        if (table[j].hasVal) {
            reg1.token = INT;
            reg1.value = table[j].val;
            return reg1;
        }
        
        for (i = 0; i < 8; i++) {
            if (reg_available[i]) break;
        }
        reg_available[i] = 0;
        if (strcmp(root->lexeme, "x") == 0) {
            printf("MOV r%d r0\n", i);
        }
        else if (strcmp(root->lexeme, "y") == 0) {
            printf("MOV r%d r1\n", i);
        }
        else if (strcmp(root->lexeme, "z") == 0) {
            printf("MOV r%d r2\n", i);
        }
        else {
            printf("MOV r%d [%d]\n", i, j*4);
        }
        reg1.reg = i;
        reg1.token = ID;
        return reg1;
    }
    
    reg1.token = INT;
    reg1.value = 0;
    return reg1;
}
