# Introdução à Linguagem C/C++


Introduziremos agora à linguagem C++ (e também um pouco da linguagem C), normalmente utilizada em programação competitiva pela sua eficiência e simplicidade.

Antes de começar, é bom dizer que o que fazemos em C (e que estará mais a frente) também pode ser feito em C++, ou seja, se simplesmente pegarmos um código em C, e compilá-lo e salvá-lo como se fosse C++, tudo executaria normalmente.

As partes de código precedidas de *\\* são comentários, ignorados no processo de compilação e execução do código.

# Estrutura básica em C

```c
int main() { //função principal do código, onde será baseada a sua execução
    return 0; //simplesmente retorna o valor 0 para o sistema operacional
}
```

Falaremos agora sobre variáveis.

Variáveis são tipos de dados, que podem armazenar determinados valores, de acordo com suas especificações. Os principais tipos de dados são:
1. *int* - armazena números inteiros, no intervalo de -2^32-1 até +2^32-1 - 1.
2. *char* - armazena números pequenos (-128 a 127) ou caracteres do tipo ASCII.
3. *float* - armazena valores reais.
4. *double* - armazena valores reais, com maior capacidade de precisão.

Para declarar uma variavel, deve-se fazer o seguinte:

```c
#include <stdio.h>

int main() {
    //tipo_da_variavel nome_da_variavel
    int x;
    char c;
  
    x = 10;
    c = 'a'; // caracteres são representados por aspas simples
  
    int n = 23; //também é possível iniciar o valor da variável assim
  
    return 0;
}
```

Esse código não faz nada, apenas declara algumas variáveis e assinala algum valor à elas. Porém, podemos melhorar ele. Para isso, importaremos *bibliotecas*, que possuem algumas funções já implementadas, por exemplo, para a entrada e saída de dados.

```c
#include <stdio.h> //biblioteca "standart input and output"

int main() {
    printf("Aoba\n");
    return 0;
}
```

O código acima reproduz a mensagem "AOBA" de saída, com uma quebra de linha no final (o *\n* pula a linha da saída - falaremos mais sobre as máscaras do printf mais a frente). Portanto, o comando *printf()* serve para imprimir coisas na tela. E para ler algum input do usuário?

```c
#include <stdio.h>

int main() {
    int x;
    printf("Digite um número: ");
    scanf("%d", &x); //lendo o valor de x
    
    printf("O número lido foi: %d\n", x); //imprime uma frase com o valor de x, com uma quebra de linha no final
    return 0;
}
```

Essas funções podem parecer confusas no começo, porém elas funcionam assim: com "máscaras". Por exemplo, tempos as máscaras de formatação de alguma variável para a saída, como esse *%d* no printf e scanf. Isso representa um *sinal* à função, que saberá que deve imprimir um valor do tipo inteiro naquela parte do código. Essas são as principais máscaras:

1. *%d* tipo inteiro
2. *%f* tipo float
3. *%lf* tipo double (long float)
4. *%c* tipo char

Para ler e imprimir mais de uma variável ao mesmo tempo:

```c
#include <stdio.h>

int main() {
    int x, y; //cria uma variavel x e outra y - poderia ser em duas linhas separadas, mas podemos separar por vírgulas também.
    scanf("%d%d", &x, &y); //lendo o valor de x e de y
    
    printf("Você digitou %d e %d\n", x, y);
    return 0;
}
```

Sem crise até aqui, certo? Vamos falar agora sobre operações q podemos fazer com variáveis. As principais são:
1. a + b, soma a e b
2. a - b, subtrai a e b
3. a * b, multiplica a e b
4. a / b, divide a por b
5. a % b, retorna o resto da divisão de a por b

```c
int main() {
    int x = 15, y = 2;
    
    int a = x + y; //a = 15+2, ou seja, a = 17
    int b = x - y; //b = 13
    int c = x * y; //c = 30
    
    int d = x / y; //d = 15/2, ou seja, d = 7 (hm... blz né, é inteiro...)
    float dd = x / y; //dd = 7 (eita, mas agora é float... não deveria ser 7.5??)
    
    int e = x % y; //d = 15%2, ou seja, d = 1 (pois 15 dividido por 2 retorna resto 1)
    
    return 0;
}
```

Simples, não? Agora, por que 15/2 retornou 7?

Estamos falando de operações com **números inteiros**. Ou seja, não podemos considerar números reais. Quando vamos mexer com variáveis inteiras em C, ele sempre irá mexer com tudo em inteiro. Portanto, se quisermos que 15/2 retorna algo como 7.5, devemos converter algum número inicial (15 ou 2) para um tipo real (float ou double). Desse jeito:

```c
int main() {
    int x = 15;
    double y = 2; 
    
    double a = x / y; //agora sim, a = 7.5
    
    //também seria possível esse jeito:
    int xx = 15, yy = 2;
    double aa = xx / (double)yy; //aqui, damos um "cast" de yy para o tipo double, fazendo com que ele vire um número real, possibilitando o resultado desejado.
    
    return 0;
}
```

# Comandos Condicionais

Também podemos fazer linhas de código que apenas executam caso alguma condição seja satisfeita. Desse jeito:


```c
#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    
    if (x == 1) {
        printf("Você digitou o valor 1\n");
    } else {
        printf("Você digitou algum valor que não é 1\n");
    }
    
    return 0;
}
```

Deu pra ter uma base, certo? O comando *if* é executado caso a condição que está dentro dele é verdadeira. Caso contrário, poderemos adicionar também um comando *else* (senão). Essa condição é estabelecida de acordo com alguns operadores:
1. a == b -> retorna *true* caso a seja **igual** a b 
2. a != b -> retorna *true* caso a seja **diferente** a b
3. a < b -> retorna *true* caso a seja **menor** que b
4. a > b -> retorna *true* caso a seja **maior** que b
5. a <= b -> retorna *true* caso a seja **menor ou igual** a b
6. a >= b -> retorna *true* caso a seja **maior ou igual** a b


```c
#include <stdio.h>

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    
    if (a + b == 10) {
        printf("A soma é 10\n");
    } else if (a + b == 15) {
        printf("A soma é 15\n");
    } else {
        printf("A soma não dá isso não\n");
    }
    
    if (a * b == 32)
        printf("A multiplicação dá 32.\n");
    
    return 0;
}
```

Podemos também aprimorar as condições com as cláusulas and e or.

```c
#include <stdio.h>

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    
    if (x == 1 && y == 1) { // && é o comando de AND em C
        printf("Tanto x quanto y são 1.\n");
    } else if (x == 1 || y == 1) { // || é OR em C
        printf("Algum dos dois vale 1\n");
    } else {
        printf("Nenhum valor vale 1.\n");
    }
    
    return 0;
}
```

Bom, essa é uma introdução à programação em C. Agora, vamos ver algumas coisas que podemos fazer em C++, e que ajudarão na maratona de programação.

```c++
#include <bits/stdc++.h> //vamos incluir essa biblioteca aqui, que possui todas as funções que precisaremos
using namespace std; //indicaremos que estamos usando o namespace std - você entenderá isso mais pra frente

int main() {
    int x;
    cin >> x; //equivalente à scanf("%d", &x);
    
    cout << "X vale: " << x << "\n"; //equivalente ao printf("X vale %d\n", x);
    
    int a, b;
    cin >> a >> b; //lendo a e b
    if (a == 2 and b == 3) { //em C++, podemos usar "and" e "or"
        printf("a é 2 e b é 3.\n");
    }
    
    return 0;
}
```
