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

Esse código não faz nada, porém podemos melhorar ele. Para isso, importaremos *bibliotecas*, que possuem algumas funções já implementadas, por exemplo, para a entrada e saída de dados.

```c
#include <stdio.h> //biblioteca "standart input and output"

int main() {
  printf("Aoba\n");
  return 0;
}
```

O código acima reproduz a mensagem "AOBA" de saída, com uma quebra de linha no final (falaremos mais sobre as máscaras do printf mais a frente). Portanto, o comando *printf()* serve para imprimir coisas na tela. E para ler algum input do usuário?

Primeiramente, vamos falar um pouco sobre variáveis.

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
  
  int n = 23; //também é possível fazer isso
  
  return 0;
}
```
