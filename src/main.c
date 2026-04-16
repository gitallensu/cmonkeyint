#include "token.h"
#include <assert.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 64
#define SAMPLE_FOLDER "sample_monkeys/"

typedef struct Node Node;
enum ast_type{
  AST_ASSIGNMENT,
  AST_SEQUENCE,
  AST_,
  AST_LITERAL,
  AST_EXPRESSION,
  AST_T_COUNT,
};

struct Node{
  enum ast_type a_type;
  Token *t;
  Node *left;
  Node *rght;
};

char *keywords[] = {
  "fn", "let", "true", "false", "if", "else", "return",
};

typedef struct lexer {
  char *buf;
  size_t buf_size;
  size_t col;
  size_t row;
  Token *tokens; 
} Lexer;

int readFile(char *filename, Lexer *l) {
  FILE *fptr;
  fptr = fopen(filename, "r");
  if (fptr == NULL) {
    perror("open");
    return 1;
  }
  while (fgets(l->buf, l->buf_size, fptr) != NULL) {
    l->row ++;
    size_t len = strlen(l->buf);
    while (len > 0 && l->buf[len - 1] != '\n') {
      size_t new_size = l-> buf_size * 2;
      char *temp_buf = realloc(l->buf, new_size);
      if (temp_buf == NULL) {
        perror("Is RAM really that expensive?");
        goto error;
      }
      l->buf = temp_buf;
      l->buf_size = new_size;
      if (fgets(l->buf + len - 1, l->buf_size - len, fptr) == NULL)
        goto null_handle;
      len = strlen(l->buf);
    }
    char *cur = l->buf;
    while (*cur != '\0') {
      Token tok = generateToken(cur);
      cur += tok.length;
      printToken(tok);
    }
  }
null_handle:
  if (feof(fptr))
    return 0;
  if (ferror(fptr)) {
    perror("fgets");
    goto error;
  }
  free(l->buf);
  fclose(fptr);

error:
  if (fptr)
    fclose(fptr);
  free(l->buf);
  return 1;
}

int main(void) {
  Lexer l = {0};
  l.buf_size = BUFF_SIZE;
  l.buf = calloc(l.buf_size, sizeof(char));
  readFile(SAMPLE_FOLDER "028_example.mnky", &l);
  return 0;
}
