#include <stdio.h>

int count_chars(const char* s) { return 0; }

int count_lines(const char* s) { return 0; }

int count_words(const char* s) { return 0; }

int main(void) {
    const char* text = "hello world\nthis is a test\n";

    printf("chars: %d\n", count_chars(text));
    printf("lines: %d\n", count_lines(text));
    printf("words: %d\n", count_words(text));

    return 0;
}

// static int g_failures = 0;

// static void run_test(const char* name, const char* text, int exp_chars,
//                      int exp_lines, int exp_words) {
//     int got_chars = count_chars(text);
//     int got_lines = count_lines(text);
//     int got_words = count_words(text);

//     if (got_chars != exp_chars || got_lines != exp_lines ||
//         got_words != exp_words) {
//         g_failures++;
//         printf("FAIL: %s\n", name);
//         printf("  text   : \"%s\"\n", text);
//         printf("  chars  : got %d, expected %d\n", got_chars, exp_chars);
//         printf("  lines  : got %d, expected %d\n", got_lines, exp_lines);
//         printf("  words  : got %d, expected %d\n", got_words, exp_words);
//     } else {
//         printf("PASS: %s\n", name);
//     }
// }

// int main(void) {
//     /* Basics */
//     run_test("empty string", "", 0, 0, 0);
//     run_test("single word", "hello", 5, 0, 1);
//     run_test("two words", "hello world", 11, 0, 2);

//     /* Newlines */
//     run_test("single newline", "\n", 1, 1, 0);
//     run_test("two lines", "hello\nworld\n", 12, 2, 2);

//     /* Whitespace handling */
//     run_test("leading spaces", "   hi", 5, 0, 1);

//     run_test("trailing spaces", "hi   ", 5, 0, 1);

//     run_test("multiple spaces between words", "a   b", 5, 0, 2);

//     run_test("tabs and newlines", "a\tb\nc", 5, 1, 3);

//     /* Edge cases */
//     run_test("only whitespace", " \n\t", 3, 1, 0);

//     run_test("no trailing newline", "one\ntwo", 7, 1, 2);

//     printf("\nTotal failures: %d\n", g_failures);
//     return (g_failures == 0) ? 0 : 1;
// }