#include "token.h"

typedef struct Node Node;
enum ast_type{
  AST_SEQUENCE,
  AST_ASSIGNMENT,
  AST_STATEMENT,
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


/**
(Node *) (Token *t) nodeFactories{
    
}
//*/

