# Introdução à Linguagem C/C++


Introduziremos agora à linguagem C++ (e também um pouco da linguagem C), normalmente utilizada em programação competitiva pela sua eficiência e simplicidade.

Antes de começar, é bom dizer que o que fazemos em C (e que estará mais a frente) também pode ser feito em C++, ou seja, se simplesmente pegarmos um código em C, e compilá-lo e salvá-lo como se fosse C++, tudo executaria normalmente.

As partes de código precedidas de *//* são comentários, ignorados no processo de compilação e execução do código.

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

Deu pra ter uma base, certo? Os comandos que estão dentro das chaves após o *if* são executados caso a condição que está dentro dos parenteses seja verdadeira. Caso contrário, poderemos adicionar também um comando *else* (senão). Essa condição é estabelecida de acordo com alguns operadores:
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
    if (a == 2 and b == 3) { //em C++, podemos também usar "and" e "or"
        printf("a é 2 e b é 3.\n");
    }
    
    return 0;
}
```

# Overflow e o tipo *long long*

Bom, como dito anteriormente nos tipos de variável, deu pra perceber que as variáveis possuem um limite para armazenar seus valores. Isso se dá devido a quantidade de bits e bytes que uma variável reserva da memória. Portanto, se eu digitar um valor muito grande (ou muito pequeno) em algum dos tipos citados anteriormente, acontece o chamado *overflow* - a sua variável não possui bits necessários para representar o valor inserido, e fica com um valor totalmente diferente do esperado.

Por exemplo, um tipo *int* possui, normalmente, 32 bits. Isso quer dizer que ele possui 32 zeros ou uns, que representarão o número desejado. Você pode saber mais sobre o sistema binário [aqui](https://pt.wikipedia.org/wiki/Sistema_de_numera%C3%A7%C3%A3o_bin%C3%A1rio).

Portanto, um *int* suporta valores até aproximadamente 2.10^9. Para valores maiores, existe o tipo *long long*, que possui 64 bits. Portanto, ele pode suportar valores até aproximadamente 9.10^18, normalmente o necessário para as contas em programação competitiva. Mesmo assim, em alguns exercícios específicos, isso pode não ser o suficiente, sendo necessário o tipo BigInt - mas não precisa se preocupar com isso (ainda).

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x; //lendo o valor de x - pode ser bem grande

    cout << x << endl; //imprimindo o valor de x do jeito c++
    printf("%lld\n", x); //imprimindo o valor de x do jeito C (a mascara do printf é %lld ou %I64d)
    return 0;
}
```

# O tipo boolean

Existe também outro tipo de variável interessante que é bastante utilizado. Esse é o tipo *bool*, que simplesmente armazena dois valores - *true* ou *false*. Ele é útil, entre outras coisas, para armazenar alguma informação que depois será usada em um comando condicional *(if e else)*. Abaixo, um exemplo (um tanto quanto inútil) de funcionamento:

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    bool flag = false;

    int x; scanf("%d", &x);
    if (x == 5)
        flag = true;

    if (flag == true)
        printf("hmm é true hein");
    else
        printf("hmm é false hein");
}
```

# Laços de Repetição

Imagine que queremos ler 5 números, e ver se algum deles vale 10. Aprendemos até aqui que isso pode ser feito da seguinte forma:

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x1, x2, x3, x4, x5;
    cin >> x1 >> x2 >> x3 >> x4 >> x5;

    if (x1 == 10 or x2 == 10 or x3 == 10 or x4 == 10 or x5 == 10)
        printf("Algum deles vale 10");
    else
        printf("Nenhum vale 10");
}
```

Certo, isso funciona. Agora, e se quisermos conferir isso para 10 números? Para 50? E para 10^5 numeros? Ficaria inviável de fazer dessa forma, certo?

Para isso, existem os laços de repetição. São eles, em C++, o **for**, o **while** e o **do while**.

## For

O comando **for** funciona da seguinte forma:

```c++
    for (int i = 0; i < 10; i = i + 1) {
        // comandos que queremos
    }
```

Um pouco confuso, certo? Nem tanto. Sempre será desse estilo:

```c++
    for (inicia_var; condicao_parada; incrementos_var) {
        // comando
    }
```

O primeiro **for** faz o seguinte: ele cria uma variável *i*, que começa com o valor 0. Depois, ele confere se *i* é *menor que* 10. Então, ele executa os "comandos que queremos". Após executar tudo, o valor de *i* é incrementado em 1, passando a valer 1. Após isso, é feito o teste novamente, *i é menor que 10?* Como *i* agora vale 1, isso é verdade, então os comandos que queremos são executados novamente. Após isso, é feito novamente o incremento de *i*, que passa a valer 2. Novamente, é feito a pergunta condicional, que ainda é verdadeira. E os comandos são executados novamente. E assim por diante.

Representando o exemplo citado anteriormente, de se ler 5 números e checar se algum vale 10:

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    bool flag = false;

    for (int i = 0; i < 5; i++) { //i++ é o mesmo de i = i+1
        int x; scanf("%d", &x);
        if (x == 10) {
            flag = true;
        }
    }

    if (flag == true)
        printf("Algum deles vale 10");
    else
        printf("Nenhum vale 10");
}
```

Agora, se quisermos aumentar o limite de variáveis lidas para 10, 100 ou 1 milhão, é bem simples, pois apenas aumentamos o valor dentro da condição do for.

## Algumas instruções para laços de repetição

Vimos anteriormente que o comando **return** na função *main* simplesmente retorna um valor para o sistema operacional, finalizando o programa, certo? Veremos agora alguns comandos que podem ser utilizados em laços de repetição:

### break;
O laço é interrompido e para imediatamente.

```c++
    for (int i = 0; i < 5; i++) {
        int x; cin >> x;
        if (x == 10) break;
    } //o for ira parar de executar quando o valor lido for igual a 10, ou quando forem lidos 5 valores.
```

### continue;
Os comandos que estão após o *continue* não executam, porém o laço não é interrompido - o sistema finge que os comandos a serem executados acabaram, e volta no incremento das variáveis.

```c++
    for (int i = 0; i < 5; i++) {
        if (i == 2) continue;

        cout << i << " ";
    }
    // output desse programa: 0 1 3 4
```

## While

O *while* fará outro tipo de laço de repetição. Ele é um pouco mais simples, tendo dentro dele apenas a condição de parada:

```c++
    while (condicao_for_verdadeira) {
        // comandos que eu quero
    }
```

Abaixo, aquele mesmo exemplo, agora usando while:

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        bool flag = false;

        int i = 0;
        while (i < 5) {
            int x; scanf("%d", &x);
            if (x == 10) flag = true;

            i++;
        }

        if (flag == true)
            printf("Algum deles vale 10");
        else
            printf("Nenhum vale 10");
    }
```

## Do While

O *do while* é um pouco diferente: ele sempre executará no mínimo uma vez, e verificará a condição apenas no final de seu escopo. 

```c++
    do {
        // comandos
    } while (condicao_existencia);    
```

Aquele mesmo exemplo:

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        bool flag = false;

        int i = 0;
        do {
            int x; scanf("%d", &x);
            if (x == 10) flag = true;

            i++;
        } while (i < 5);

        if (flag == true)
            printf("Algum deles vale 10");
        else
            printf("Nenhum vale 10");
    }
```

# Vetores

Os vetores (ou arrays) servem para armazenar várias variáveis de uma só vez. Podemos representar arrays da seguinte forma:

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        int vec[10];
        for (int i = 0; i < 10; i++) {
            int x;
            scanf("%d", &vec[i]);
        }

        for (int i = 0; i < 10; i++) {
            printf("%d ", vec[i]);
        }
    }
```

Nesse caso, lemos 10 números inteiros e os armazenamos no array *vec*. Ou seja, os arrays são representados assim:

```c++
     tipo_var nome_var[tamanho_var];
```

E as posições do array são representadas de 0 até tamanho_var. Ou seja, um array de tamanho 10 tem posições de 0 até 9.

Outro exemplo:

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        int vec[5] = {1, 2, 3, 4, 5};

        for (int i = 0; i < 5; i++) {
            printf("%d ", vec[i]);
        }
    }
```

O array acima pode ser representado da seguinte forma:

| Index: | vec[0] | vec[1] | vec[2] | vec[3] | vec[4] |
|:------:|:------:|:------:|:------:|:------:|:------:|
| Value: |    1   |    2   |    3   |    4   |    5   |


# Variáveis globais, locais e *lixo*

Anteriormente, declaramos todas as variáveis dentro da função *main*. Porém, podemos também declarar variáveis fora dela. Usar variáveis globais fará mais sentido mais a frente, quando falaremos sobre *funções* mais a fundo. Por enquanto, vou falar de apenas uma vantagem de se utilizar variáveis globais - mas, para isso, vamos falar sobre *lixo* em C.

Quando criamos uma variável e não inserimos um valor à ela, ela pode estar com qualquer valor. Como assim? Ao criarmos uma variável, é alocado um espaço para ela na memória. Porém, esse espaço em memória pode já ter sido usada por algum programa antes, ou seja, podem haver alguns 0s e 1s, quando não os queremos. É meio complicado explicar isso, então você mesmo pode fazer uns testes: crie um programa do seguinte jeito:

```c++
    #include <bits/stdc++.h>
    using namespace std;
    
    int main() {
        int x;
        cout << x << endl;
    }
```

Execute ele várias vezes, e veja os valores que x possui. Os valores diferentes representam posições diferentes em memória que foram alocadas.

Porém, quando criamos variáveis globais, além delas poderem ser utilizadas em qualquer lugar do código - novamente, falaremos sobre funções mais a frente - elas já se iniciam totalmente zeradas, o que muitas vezes é útil.

```c++
    #include <bits/stdc++.h>
    using namespace std;

    int vet_global[15]; //variavel global, array de tamanho 15 de inteiros.

    int main() {
        int vet_local[15];
        for (int i = 0; i < 15; i++) printf("%d ", vet_local[i]);
        // no meu computador, foram printados esses valores: 0 0 8 0 1 0 -1477321288 32764 -1477321272 32764 9 0 0 0 4839111

        //variavel global:
        for (int i = 0; i < 15; i++) printf("%d ", vet_global[i]);
        // no meu computador, foram printados esses valores: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 
    }
```

