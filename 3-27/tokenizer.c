#include "tokenizer.h"

#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static int token_array_init(TokenArray* arr) {
    if (arr == NULL) {
        return 0;
    }

    arr->count = 0;
    arr->capacity = 8;
    arr->tokens = (Token*)malloc(arr->capacity * sizeof(Token));

    return arr->tokens != NULL;
}

static char* copy_substring(const char* start, size_t length) {
    char* s = (char*)malloc(length + 1);
    if (s == NULL) {
        return NULL;
    }

    memcpy(s, start, length);
    s[length] = '\0';
    return s;
}

static int token_array_push(TokenArray* arr, TokenType type, const char* start,
                            size_t length) {
    Token* new_tokens;
    char* lexeme;

    if (arr == NULL || start == NULL) {
        return 0;
    }

    if (arr->count == arr->capacity) {
        size_t new_capacity = arr->capacity * 2;

        new_tokens = (Token*)realloc(arr->tokens, new_capacity * sizeof(Token));
        if (new_tokens == NULL) {
            return 0;
        }

        arr->tokens = new_tokens;
        arr->capacity = new_capacity;
    }

    lexeme = copy_substring(start, length);
    if (lexeme == NULL) {
        return 0;
    }

    arr->tokens[arr->count].type = type;
    arr->tokens[arr->count].lexeme = lexeme;
    arr->count++;

    return 1;
}

/*
 * peek:
 * Returns the character that is "offset" positions ahead of p
 * without moving p itself.
 *
 * Example:
 *   peek(p, 0) -> current character
 *   peek(p, 1) -> next character
 *
 * If p is NULL, return '\0'.
 */
static char peek(const char* p, size_t offset) {
    if (p == NULL) {
        return '\0';
    }

    return p[offset];
}

int tokenize(const char* input, TokenArray* out_tokens) {
    const char* p;

    if (input == NULL || out_tokens == NULL) {
        return 0;
    }

    if (!token_array_init(out_tokens)) {
        return 0;
    }

    p = input;

    while (peek(p, 0) != '\0') {
        /* Skip whitespace */
        if (isspace((unsigned char)peek(p, 0))) {
            p++;
            continue;
        }

        /* PIPE */
        if (peek(p, 0) == '|') {
            if (!token_array_push(out_tokens, TOKEN_PIPE, p, 1)) {
                free_tokens(out_tokens);
                return 0;
            }
            p++;
            continue;
        }

        /* REDIRECT_OUT or REDIRECT_APPEND */
        if (peek(p, 0) == '>') {
            if (peek(p, 1) == '>') {
                if (!token_array_push(out_tokens, TOKEN_REDIRECT_APPEND, p,
                                      2)) {
                    free_tokens(out_tokens);
                    return 0;
                }
                p += 2;
            } else {
                if (!token_array_push(out_tokens, TOKEN_REDIRECT_OUT, p, 1)) {
                    free_tokens(out_tokens);
                    return 0;
                }
                p++;
            }
            continue;
        }

        /* REDIRECT_IN */
        if (peek(p, 0) == '<') {
            if (!token_array_push(out_tokens, TOKEN_REDIRECT_IN, p, 1)) {
                free_tokens(out_tokens);
                return 0;
            }
            p++;
            continue;
        }

        /* WORD */
        {
            const char* start = p;

            while (peek(p, 0) != '\0' && !isspace((unsigned char)peek(p, 0)) &&
                   peek(p, 0) != '|' && peek(p, 0) != '>' &&
                   peek(p, 0) != '<') {
                p++;
            }

            if (!token_array_push(out_tokens, TOKEN_WORD, start,
                                  (size_t)(p - start))) {
                free_tokens(out_tokens);
                return 0;
            }
        }
    }

    return 1;
}

void free_tokens(TokenArray* tokens) {
    size_t i;

    if (tokens == NULL) {
        return;
    }

    for (i = 0; i < tokens->count; i++) {
        free(tokens->tokens[i].lexeme);
    }

    free(tokens->tokens);
    tokens->tokens = NULL;
    tokens->count = 0;
    tokens->capacity = 0;
}

const char* token_type_to_string(TokenType type) {
    switch (type) {
        case TOKEN_WORD:
            return "WORD";
        case TOKEN_PIPE:
            return "PIPE";
        case TOKEN_REDIRECT_OUT:
            return "REDIRECT_OUT";
        case TOKEN_REDIRECT_APPEND:
            return "REDIRECT_APPEND";
        case TOKEN_REDIRECT_IN:
            return "REDIRECT_IN";
        default:
            return "UNKNOWN";
    }
}