#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stddef.h>

typedef enum {
    TOKEN_WORD,
    TOKEN_PIPE,
    TOKEN_REDIRECT_OUT,
    TOKEN_REDIRECT_APPEND,
    TOKEN_REDIRECT_IN
} TokenType;

typedef struct {
    TokenType type;
    char* lexeme;
} Token;

typedef struct {
    Token* tokens;
    size_t count;
    size_t capacity;
} TokenArray;

int tokenize(const char* input, TokenArray* out_tokens);
void free_tokens(TokenArray* tokens);
const char* token_type_to_string(TokenType type);

#endif