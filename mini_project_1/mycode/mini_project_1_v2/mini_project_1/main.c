//
//  main.c
//  mini_project_1
//
//  Created by engine210 on 2019/4/5.
//  Copyright © 2019 engine210. All rights reserved.
//

#include "lex.h"

/*
 the only type: integer
 everything is an expression
 statement   := END | expr END
 expr        := term expr_tail
 expr_tail   := ADDSUB term expr_tail | NIL
 term        := factor term_tail
 term_tail := MULDIV factor term_tail | NIL
 factor      := INT | ADDSUB INT | ADDSUB ID | ID ASSIGN expr | ID | LPAREN expr RPAREN
 */

Symbol table[TBLSIZE];
int sbcount = 0;

void statement(void);
BTNode* bit_or(void);
BTNode* bit_xor(void);
BTNode* bit_and(void);
BTNode* expr(void);
BTNode* term(void);
BTNode* factor(void);
int getval(void);
int setval(char*, int);
BTNode* makeNode(TokenSet, const char*);
void freeTree(BTNode*);
void printPrefix(BTNode*);
int evaluateTree(BTNode*);
void error(ErrorType errorNum);

void printAssemble(BTNode* root);

int syntax_error = 0;
int firstID;
int first = 1;


int main(int argc, char* argv[]) {
    char c;
    freopen("input.txt", "r", stdin);
    
    //set x, y, z to table
    table[0].name[0] = 'x';
    table[0].name[1] = '\0';
    table[1].name[0] = 'y';
    table[1].name[1] = '\0';
    table[2].name[0] = 'z';
    table[2].name[1] = '\0';
    sbcount = 3;
    
    while (scanf("%c", &c) != EOF) {
        ungetc(c, stdin);
        firstID = 1;
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

/* traverse the syntax tree by pre-order
 and evaluate the underlying expression */
int evaluateTree(BTNode *root) {
    int retval = 0, lv, rv;
    if (root != NULL) {
        switch (root->token) {
            case ID:
            case INT:
                retval = root->val;
                break;
            case OR:
            case XOR:
            case AND:
            case ASSIGN:
            case ADDSUB:
            case MULDIV:
                lv = evaluateTree(root->left);
                rv = evaluateTree(root->right);
                if (strcmp(root->lexeme, "|") == 0) {
                    retval = lv | rv;
                }
                else if (strcmp(root->lexeme, "^") == 0) {
                    retval = lv ^ rv;
                }
                else if (strcmp(root->lexeme, "&") == 0) {
                    retval = lv & rv;
                }
                else if (strcmp(root->lexeme, "+") == 0) {
                    retval = lv + rv;
                }
                else if (strcmp(root->lexeme, "-") == 0) {
                    retval = lv - rv;
                }
                else if (strcmp(root->lexeme, "*") == 0) {
                    retval = lv * rv;
                }
                else if (strcmp(root->lexeme, "/") == 0) {
                    if (rv == 0) {
                        error(NAN);
                    }
                    else {
                        retval = lv / rv;
                    }
                }
                else if (strcmp(root->lexeme, "=") == 0) {
                    retval = setval(root->left->lexeme, rv);
                }
                break;
            default:
                retval = 0;
        }
    }
    return retval;
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
            if (strcmp(getLexeme(), table[i].name)==0) {
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
                sbcount++;
            }
            else {
                error(RUNOUT);
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
            error(NOTNUMID);
        }
    }
    else if (match(LPAREN)) {
        advance();
        retp = bit_and();
        if (match(RPAREN)) {
            advance();
        }
        else {
            error(MISPAREN);
        }
    }
    else {
        error(NOTNUMID);
    }
    return retp;
}

void error(ErrorType errorNum) {
    /*
    switch (errorNum) {
        case MISPAREN:
            fprintf(stderr, "Mismatched parenthesis\n");
            break;
        case NOTNUMID:
            fprintf(stderr, "Number or identifier expected\n");
            break;
        case NOTFOUND:
            fprintf(stderr, "%s not defined\n", getLexeme());
            break;
        case RUNOUT:
            fprintf(stderr, "Out of memory\n");
            break;
        case NAN:
            fprintf(stderr, "Not a number\n");
    }
    */
    syntax_error = 1;
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
                printf("EXIT 1\n");
                syntax_error = 1;
            }
            if (!syntax_error) {
                if (first) {
                    printf("MOV r0 [0]\n");
                    printf("MOV r1 [4]\n");
                    printf("MOV r2 [8]\n");
                    first = 0;
                }
                
                printAssemble(retp);
                printf("\n");
            }
            
            freeTree(retp);
            advance();
        }
    }
}

void printAssemble(BTNode* root) {
    
    char c = root->left->lexeme[0];
    if (c == 'x' || c == 'y' || c == 'z') {
        printf("MOV ");
        if (c == 'x') {
            printf("r0");
        }
        else if (c == 'y') {
            printf("r1");
        }
        else if (c == 'z') {
            printf("r2");
        }
        printf(" %d", evaluateTree(root));
    }
}
