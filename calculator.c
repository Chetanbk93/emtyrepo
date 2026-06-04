#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    double num1, num2, result;
    char op;

    printf("Simple Calculator\n");
    printf("Enter an expression like 12.5 + 3.4\n");
    printf("Supported operators: + - * /\n");
    printf("Expression: ");

    if (scanf("%lf %c %lf", &num1, &op, &num2) != 3) {
        printf("Invalid input. Use the format: number operator number\n");
        return 1;
    }

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0.0) {
                printf("Error: Division by zero is not allowed.\n");
                return 1;
            }
            result = num1 / num2;
            break;
        default:
            printf("Unsupported operator '%c'. Use +, -, *, or /.\n", op);
            return 1;
    }

    printf("Result: %.6g %c %.6g = %.6g\n", num1, op, num2, result);
    return 0;
}
