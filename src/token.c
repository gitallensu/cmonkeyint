#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include "token.h"

typedef enum {
    KEYWORD_LET,
    KEYWORD_FUNC,
    COUNT_KEYWORD,
} Keywords;

const char *tokentypes[COUNT_TT]={
    [TT_SYMBOL] = "SYMBOL",
    [TT_WHITESPACE] = "WHITESPACE",
    [TT_INVALID] = "INVALID",
    [TT_SPECIAL] = "SPECIAL",
    [TT_WORD] = "LITERAL",
    [TT_STRING] = "STRING",
};

const char *keywords[COUNT_KEYWORD]={
    [KEYWORD_LET] = "let",
    [KEYWORD_FUNC] = "func",
};

_Bool isLetter(char c){
    return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_');
}
_Bool isSymbol(char c){
    return (('!' <= c && c <= '@') || ('[' <= c && c <= '^'));
}
Token* generateToken_String(char *cur){
    Token *tok = TOKEN_INIT(cur);
    tok->type = TT_STRING;
    while (*tok->end != *tok->start && *tok->end != '\0')
        tok->end++;
    if (*tok->end != *tok->start){
        printf(stderr, "Matching quote %c not found.", tok->start);
        return NULL;
    }
    return tok;
}

Token generateToken(char *cur){
    if (*cur == '"' || *cur == '\'')
        return *generateToken_String(cur);
    Token token = {
        .start = cur,
        .end = cur,
    };
    if (isLetter(*cur)){
        while(isLetter(*(cur+1))){
            cur++;
        }
        token.type = TT_WORD;
        token.end = cur;
        return token;
    }
    if (isspace(*cur)){
        while(isspace(*(cur+1))){
            cur++;
        }
        token.type = TT_WHITESPACE;
        token.end = cur;
        return token;
    }
    if (isSymbol(*cur)){
        token.type = TT_SYMBOL;
        return token;
    }
    token.type = TT_INVALID;
    return token;
}
