#include <stdio.h>
#include <string.h>
int main(void) {
    /* 1. " " automatically includes a null terminator */
    /* A sequence of characters enclosed in double quotes (" ") is called a
     * string literal. */
    char str1[] = "hello";  // {'h','e','l','l','o','\0'}

    /* 2. ' ' does NOT include a null terminator */
    char str2[5] = {'h', 'e', 'l', 'l', 'o'};  // NOT a valid C string

    /* 3. Character array larger than the string - totally fine */
    char str3[10] = "hi";  // only uses 3 chars: 'h','i','\0'

    /* 4. Null terminator placed early */
    char str4[10] = {'h', 'i', '\0', 'X', 'Y', 'Z', '\0'};

    /* Print strings */
    printf("str1: \"%s\" (strlen = %lu)\n", str1, strlen(str1));
    /* WARNING: Uncommenting this causes undefined behavior */
    // printf("str2: \"%s\"\n", str2);
    printf("str3: \"%s\" (strlen = %lu)\n", str3, strlen(str3));
    printf("str4: \"%s\" (strlen = %lu)\n", str4, strlen(str4));

    /* 5. Demonstrating array size vs string length */
    printf("Array size of str3: %lu\n", sizeof(str3));
    printf("String length of str3: %lu\n", strlen(str3));
    return 0;
}
