Calculadora Simples em C

Descrição:

Este é um programa simples em C que funciona como uma calculadora interativa. Ele permite ao usuário inserir dois números reais (float) e escolher entre cinco opções de operações matemáticas: soma, subtração, multiplicação, divisão ou exibir todos os resultados de uma vez. O programa inclui tratamento básico de erros, como evitar divisão por zero.

Funcionalidades:

Lê dois números reais fornecidos pelo usuário.
Oferece cinco opções de operação:
Soma
Subtração
Multiplicação
Divisão (com verificação de divisão por zero)
Todas as operações acima
Exibe os resultados com duas casas decimais.

Requisitos:

Um compilador C (ex.: GCC, DEVC++).

Um ambiente com entrada/saída de terminal (ex.: Linux, Windows)

Como Compilar:

Salve o código em um arquivo chamado calculator.c.
Abra o terminal na pasta onde o arquivo está salvo.
Compile o programa com o comando:
gcc calculator.c -o calculator

Isso gera um executável chamado calculator (ou calculator.exe no Windows).

Como Executar:

Após compilar, execute o programa com:
./calculator (No Windows, use calculator.exe).

Siga as instruções exibidas no terminal:
Digite o primeiro número e pressione Enter.
Digite o segundo número e pressione Enter.
Escolha uma operação (1 a 5) e pressione Enter.

Exemplo:

I'm your personal calculator!
Enter your first number: 10.5
Enter your second number: 2.5

Select an operation:
1 - Sum
2 - Subtraction
3 - Multiplication
4 - Division
5 - All of them
Enter your choice (1-5): 5
The sum of 10.50 + 2.50 = 13.00
The difference of 10.50 - 2.50 = 8.00
The product of 10.50 * 2.50 = 26.25
The division of 10.50 / 2.50 = 4.20


Código:
Aqui está o código completo para referência:

#include <stdio.h>

int main() {
    float a, b;
    int choice;

    printf("I'm your personal calculator!\nEnter your first number: ");
    scanf("%f", &a);
    while (getchar() != '\n');
    printf("Enter your second number: ");
    scanf("%f", &b);
    while (getchar() != '\n');

    float m = a * b;
    float d = (b != 0) ? a / b : 0;
    float s = a + b;
    float x = a - b;

    printf("\nSelect an operation:\n");
    printf("1 - Sum\n2 - Subtraction\n3 - Multiplication\n4 - Division\n5 - All of them\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);
    while (getchar() != '\n');

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


Licença:
Este é um projeto de código aberto. Sinta-se à vontade para usá-lo, modificá-lo e distribuí-lo como desejar!

