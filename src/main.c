#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "token.h"

#define BUFF_SIZE 1024
#define SAMPLE_FOLDER "sample_monkeys/"


int readFile(char *filename){
    FILE *fptr;
    char buf[BUFF_SIZE];
    fptr = fopen(filename, "r"); 
    if (fptr == NULL){
        perror("open");
        return 1;
    }
    int readchars = fread(buf, 1, BUFF_SIZE, fptr);
    char *cur = buf;
    while (*cur != '\0'){
        Token tok = generateToken(cur);
        cur = tok.end +1;
        printf("%s: %.*s\n", tokentypes[tok.type], (int)(cur - tok.start), tok.start);
    }
    fclose(fptr);
    return 0; 
}

int main(){

    readFile(SAMPLE_FOLDER"028_example.mnky");
    return 0;
}
