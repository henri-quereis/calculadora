# Calculadora simples com dois valores.

def simplesMensagem():
    print("Calculadora Simples")
    print("-" * 20)

def informarOperacao():
    op = str(input("Informe a operação: "))
    return op

def resultado(operacao, a, b):
    if operacao == "+":
        return a+b
    
simplesMensagem()
valor1 = int(input("Insira o primeiro número: "))
print(valor1)
operacao = informarOperacao()

while operacao != "+":
    print("Caractere inválido. Digite novamente.")
    operacao = informarOperacao()

print(valor1, operacao)

valor2 = int(input("Insira o segundo número: "))

resultadoFinal = resultado(operacao, valor1, valor2)
print(valor1, operacao, valor2, "=", resultadoFinal)