#include <stdio.h>

/* Function prototypes (declarations) */
int Addition(int a, int b);
int Subtraction(int a, int b);
int Multiplication(int a, int b);
int Division(int a, int b);

int main(void)
{
    int a, b, choice, result;

    printf("Please choose operation:\n");
    printf("1) Addition\n");
    printf("2) Subtraction\n");
    printf("3) Multiplication\n");
    printf("4) Division\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    switch (choice)
    {
        case 1:
            result = Addition(a, b);
            printf("The sum is %d\n", result);
            break;

        case 2:
            result = Subtraction(a, b);
            printf("The subtraction is %d\n", result);
            break;

        case 3:
            result = Multiplication(a, b);
            printf("The multiplication is %d\n", result);
            break;

        case 4:
            if (b == 0) {
                printf("Division by zero is not allowed\n");
            } else {
                result = Division(a, b);
                printf("The division is %d\n", result);
            }
            break;

        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}

/* Function definitions */
int Addition(int a, int b) {
    return a + b;
}

int Subtraction(int a, int b) {
    return a - b;
}

int Multiplication(int a, int b) {
    return a * b;
}

int Division(int a, int b) {
    return a / b;   // integer division
}
