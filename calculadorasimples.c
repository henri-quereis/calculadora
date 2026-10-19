#include <stdio.h>

int soma(int n1, int n2);
int sub(int n1, int n2);
int mult(int n1, int n2);
double div(int n1, int n2);

int main()
{
    int primeiroValor, segundoValor = 0;
    char operacao;
    double resultado;

    printf("Informe o primeiro valor: ");
    scanf("%d", &primeiroValor);

    while (segundoValor == 0)
    {
        printf("Informe o segundo valor: ");
        scanf("%d", &segundoValor);

        if (segundoValor == 0)
        {
            printf("\nNão é possível dividir por zero.\n");
            
        }
    }

    do
    {
        printf("Informe a operação (+ - * /): ");
        scanf(" %c", &operacao);

        if (operacao == '+')
        {
            resultado = soma(primeiroValor, segundoValor);
            break;
        }
        else if (operacao == '-')
        {
            resultado = sub(primeiroValor, segundoValor);
            break;
        }
        else if (operacao == '*')
        {
            resultado = mult(primeiroValor, segundoValor);
            break;
        }
        else if (operacao == '/')
        {
            resultado = div(primeiroValor, segundoValor);
            break;
        }
        else
        {
            printf("\nNão corresponde a nenhum símbolo permitido.\n");
        }
    } while (operacao != '+' && operacao != '-' && operacao != '*' && operacao != '/');

    printf("%d %c %d = %.1f\n", primeiroValor, operacao, segundoValor, resultado);
    
    return 0;
}

int soma(int n1, int n2)
{
    return n1+n2;
}

int sub(int n1, int n2)
{
    return n1-n2;
}

int mult(int n1, int n2)
{
    return n1*n2;
}

double div(int n1, int n2)
{
    return (double)n1/n2;
}