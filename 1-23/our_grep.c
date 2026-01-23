#include <stdio.h>
#include <string.h>

static int g_failures = 0;

int contains(const char* line, const char* pattern);

static void run_test(const char* name, const char* line, const char* pattern,
                     int expected) {
    int got = contains(line, pattern);
    if (got != expected) {
        g_failures++;
        printf("FAIL: %s\n", name);
        printf("  line    : \"%s\"\n", line);
        printf("  pattern : \"%s\"\n", pattern);
        printf("  expected: %d\n", expected);
        printf("  got     : %d\n", got);
    } else {
        printf("PASS: %s\n", name);
    }
}

int main(void) {
    /* Basics */
    run_test("empty pattern found in empty line", "", "", 1);
    run_test("empty pattern found in non-empty line", "abc", "", 1);
    run_test("non-empty pattern not found in empty line", "", "a", 0);

    /* Exact match and simple contains */
    run_test("exact match", "hello", "hello", 1);
    run_test("prefix match", "hello", "he", 1);
    run_test("suffix match", "hello", "lo", 1);
    run_test("middle match", "hello", "ell", 1);
    run_test("single char match", "hello", "e", 1);

    /* Not found */
    run_test("pattern longer than line", "hi", "hello", 0);
    run_test("no match", "hello", "world", 0);
    run_test("partial overlap no match", "aaaaa", "aaab", 0);

    /* Overlaps (common edge cases) */
    run_test("overlap match", "aaaaa", "aaa", 1);
    run_test("overlap with different tail", "abababa", "ababa", 1);
    run_test("classic overlap case", "mississippi", "issi", 1);

    /* Spaces and punctuation */
    run_test("space included", "a b c", " b ", 1);
    run_test("punctuation", "end.", ".", 1);
    run_test("punctuation absent", "end", ".", 0);

    /* Case sensitivity (should be case-sensitive) */
    run_test("case sensitive fail", "Hello", "hello", 0);
    run_test("case sensitive pass", "Hello", "Hell", 1);

    /* Newline characters inside strings */
    run_test("newline match", "a\nb\nc", "\nb\n", 1);
    run_test("newline not match", "a\nb\nc", "\nc\n", 0);

    printf("\nTotal failures: %d\n", g_failures);
    return (g_failures == 0) ? 0 : 1;
}