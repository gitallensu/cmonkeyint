#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "token.h"

typedef enum {
    KEYWORD_LET,
    KEYWORD_FUNC,
    COUNT_KEYWORD,
} Keywords;

const char *tokentypes[COUNT_TT]={
    [TT_WHITESPACE] = "WHITESPACE",
    [TT_INVALID] = "INVALID",
    [TT_SPECIAL] = "SPECIAL",
    [TT_WORD] = "LITERAL",
};

void printToken(Token t){
    if (t.type < 128){
        printf("Character: %c\n", t.type);
        return;
    }
    switch (t.type){
        case TT_WHITESPACE:
            break;
        case TT_WORD:
        case TT_STRING_LIT:
            printf("%s: %.*s\n", tokentypes[t.type], t.length, t.data);
            if (t.type == TT_STRING_LIT)
                free(t.data);
            break;
        case TT_INVALID:
        default:
              printf("Invalid: %c\n", *t.data);
              break;
    }

}
/*const char *keywords[COUNT_KEYWORD]={
    [KEYWORD_LET] = "let",
    [KEYWORD_FUNC] = "func",
};*/
/*
_Bool (* tokenEndFunction[COUNT_TT]) (char c) = {
    [TT_STRING_LIT] = 
}
//*/

_Bool isLetter(char c){
    return (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || c == '_');
}
_Bool isSymbol(char c){
    return (('!' <= c && c <= '@') || ('[' <= c && c <= '^'));
}

Token* generateToken_String(char *cur){
    Token *tok = TOKEN_INIT(cur);
    char string_delim = *cur;
    while (*cur != string_delim && *cur != '\0')
        cur++;
    if (*cur != string_delim){
        fprintf(stderr, "Matching quote %c not found.", string_delim);
        return NULL;
    }
    return tok;
}

Token generateToken(char *cur){
    if (*cur == '"' || *cur == '\'')
        return *generateToken_String(cur);
    Token token = {
        .data = cur,
        .length = 1,
    };
    if (isLetter(*cur) || ('0' <= *cur && *cur <= '9')){
        while(isLetter(*(cur +1)) || ('0' <= *(cur+1) && *(cur+1) <= '9')){
            cur++;
        }
        token.length += cur - token.data;
        char *slice = strndup(token.data, token.length);
        token.data = slice;
        token.type = TT_WORD;
        return token;
    }
    if (isspace(*cur)){
        while(isspace(*(cur+1))){
            cur++;
            token.length++;
        }
        token.type = TT_WHITESPACE;
        return token;
    }
    if (isSymbol(*cur)){
        token.type = *cur;
        return token;
    }
    token.type = TT_INVALID;
    return token;
}
