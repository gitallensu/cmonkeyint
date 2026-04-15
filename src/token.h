#ifndef TOKEN_H
#define TOKEN_H
enum token_type{
    TT_SYMBOL = 128,
    TT_WHITESPACE,
    TT_INVALID,
    TT_SPECIAL,
    TT_WORD,
    TT_STRING_LIT,
    COUNT_TT,
};

typedef struct token{
    enum token_type type;
    const char *data;
    int length;
}Token;
#define TOKEN_INIT(cur) ({\
    Token *tok = (Token *) malloc(sizeof(Token));\
    tok->data = cur;\
    tok->length = 1;\
    tok;\
})
void printToken(Token t);
Token* generateToken_String(char *cur);
Token generateToken(char *cur);

#endif
