#ifndef TOKEN_H
#define TOKEN_H
enum token_type{
    TT_SYMBOL,
    TT_WHITESPACE,
    TT_INVALID,
    TT_SPECIAL,
    TT_WORD,
    TT_STRING,
    COUNT_TT,
};

typedef struct token{
    enum token_type type;
    const char *start;
    const char *end;
}Token;
#define TOKEN_INIT(cur) ({\
    Token *tok = (Token *) malloc(sizeof(Token));\
    tok->start = cur;\
    tok->end = cur +1;\
    tok;\
})

Token* generateToken_String(char *cur);
Token generateToken(char *cur);

#endif
