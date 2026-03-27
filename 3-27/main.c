#include <stdio.h>

#include "tokenizer.h"

int main(void) {
    const char* input = "cat file.txt | grep hello >> out.txt < input.txt";
    // const char* input = "cat \"hello world\"";
    TokenArray tokens;
    size_t i;

    if (!tokenize(input, &tokens)) {
        fprintf(stderr, "Tokenization failed.\n");
        return 1;
    }

    printf("Input: %s\n\n", input);

    for (i = 0; i < tokens.count; i++) {
        printf("%s(\"%s\")\n", token_type_to_string(tokens.tokens[i].type),
               tokens.tokens[i].lexeme);
    }

    free_tokens(&tokens);
    return 0;
}