#include <stdio.h>
#include <fcntl.h>

#define BUFF_SIZE 1024


typedef enum token{
    ILLEGAL = 128,
    FILEEND,
    IDENT,
    INT,

    ASSIGN,
    PLUS,

    COMMA,
    SEMICOLON,

    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,

    FUNCTION,
    LET
} Token;

_Bool isLetter(char c){
    return ('a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || c == '_');
}

int readFile(char *filename){
    FILE *fptr;
    char buf[BUFF_SIZE];
    fptr = fopen(filename, "r"); 
    if (fptr == NULL){
        perror("open");
        return 1;
    }
    int readchars = fread(buf, 1, BUFF_SIZE, fptr);
    for (int i = 0; i < readchars; i++){
        printf("%c: %d\n", buf[i], isLetter(buf[i]));
    }
    fclose(fptr);
    return 0; 
}

int main(){

    readFile("008_example.mnky");
    return 0;
}


