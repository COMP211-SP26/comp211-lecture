#include <stdio.h>

#define NUM 10

int main(void) {
    int input;
    int arr[NUM];
    int i = 0;
    printf("Enter up to %d values:\n", NUM);
    while (i < NUM && (scanf("%d", &input)) == 1) {
        arr[i++] = input;
    }
    printf("Here are the values you entered\n");
    for (int j = 0; j < i; j++) {
        printf("%d\n", arr[j]);
    }
}
