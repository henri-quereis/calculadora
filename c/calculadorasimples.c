// Calculadora Simples que insere dois valores e realiza operações matemáticas básicas (+, -, *, /) com eles.

#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

int lerInteiro(const char *mensagem, int *valor);
int soma(int n1, int n2);
int sub(int n1, int n2);
int mult(int n1, int n2);
double dividir(int n1, int n2);

int main()
{
    int primeiroValor, segundoValor;
    char operacao;
    double resultado;

    if (!lerInteiro("Informe o primeiro valor: ", &primeiroValor) ||
        !lerInteiro("Informe o segundo valor: ", &segundoValor))
    {
        printf("\nEntrada encerrada.\n");
        return 1;
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
            while (segundoValor == 0)
            {
                printf("Não é possível dividir por zero. ");
                if (!lerInteiro("Informe outro valor: ", &segundoValor))
                {
                    printf("\nEntrada encerrada.\n");
                    return 1;
                }
            }

            resultado = dividir(primeiroValor, segundoValor);
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

int lerInteiro(const char *mensagem, int *valor)
{
    char entrada[128];
    char *fim;
    long numero;

    while (1)
    {
        printf("%s", mensagem);
        if (fgets(entrada, sizeof(entrada), stdin) == NULL)
        {
            return 0;
        }

        if (strchr(entrada, '\n') == NULL)
        {
            int caractere = getchar();
            if (caractere != EOF)
            {
                while (caractere != '\n' && caractere != EOF)
                {
                    caractere = getchar();
                }
                printf("Entrada inválida. Informe um número inteiro.\n");
                continue;
            }
        }

        errno = 0;
        numero = strtol(entrada, &fim, 10);

        if (fim == entrada)
        {
            printf("Entrada inválida. Informe um número inteiro.\n");
            continue;
        }

        while (isspace((unsigned char)*fim))
        {
            fim++;
        }

        if (*fim != '\0' || errno == ERANGE || numero < INT_MIN ||
            numero > INT_MAX)
        {
            printf("Entrada inválida. Informe um número inteiro.\n");
            continue;
        }

        *valor = (int)numero;
        return 1;
    }
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

double dividir(int n1, int n2)
{
    return (double)n1/n2;
}