#include <stdio.h>

int main() {
    int age;
    double height;
    char name[20];

    printf("Enter your name, age, and height: ");

    // Read multiple inputs: a string, an integer, and a double
    int result = scanf("%s %d %lf", name, &age, &height);

    if (result == 3) {
        printf("Hello, %s! Your age is %d and your height is %.2lf feet.\n",
               name, age, height);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}