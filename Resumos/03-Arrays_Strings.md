# Vetores, Matrizes e Strings

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

