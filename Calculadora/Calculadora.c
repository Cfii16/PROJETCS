#include <stdio.h>

int main() {
    float a, b;
    int choice;

    printf("I'm your personal calculator!\nEnter your first number: ");
    scanf("%f", &a);

    printf("Enter your second number: ");
    scanf("%f", &b);

    float m = a * b;
    float d = (b != 0) ? a / b : 0;
    float s = a + b;
    float x = a - b;

    printf("\nSelect an operation:\n");
    printf("1 - Sum\n");
    printf("2 - Subtraction\n");
    printf("3 - Multiplication\n");
    printf("4 - Division\n");
    printf("5 - All of them\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("The sum of %.2f + %.2f = %.2f\n", a, b, s);
    } else if (choice == 2) {
        printf("The difference of %.2f - %.2f = %.2f\n", a, b, x);
    } else if (choice == 3) {
        printf("The product of %.2f * %.2f = %.2f\n", a, b, m);
    } else if (choice == 4) {
        if (b != 0) {
            printf("The division of %.2f / %.2f = %.2f\n", a, b, d);
        } else {
            printf("Error: Division by zero is not allowed!\n");
        }
    } else if (choice == 5) {
        printf("The sum of %.2f + %.2f = %.2f\n", a, b, s);
        printf("The difference of %.2f - %.2f = %.2f\n", a, b, x);
        printf("The product of %.2f * %.2f = %.2f\n", a, b, m);
        if (b != 0) {
            printf("The division of %.2f / %.2f = %.2f\n", a, b, d);
        } else {
            printf("The division of %.2f / %.2f = Error (division by zero)\n", a, b);
        }
    } else {
        printf("Invalid operation selected.\n");
    }

    return 0;
}
