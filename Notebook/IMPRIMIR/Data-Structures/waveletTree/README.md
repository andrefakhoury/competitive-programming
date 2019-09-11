# Wavelet Tree

Estrutura de dados que particiona recursivamente uma sequência A em uma árvore (binária), de acordo com os valores de A. Cada nó da árvore é associado à uma subsequência de A. O nó raíz representa toda a sequência A.

Pode ser utilizada em operações de *query* e *update*, e inclusive combinada com outras estruturas de dados para obter melhor performance e mais utilidade.

OBS: ler [este paper](https://users.dcc.uchile.cl/~jperez/papers/ioiconf16.pdf) pode ajudar bastante a entender a estrutura.

## Utilidades

Operações de *query*, como:

- *Rank(i, k)* - contar a frequência do elemento *k* no intervalo [1, i]

- *RangeQuantile(i, j, k)* - valor do *k-ésimo* menor elemento no intervalo [i, j]

- *RangeCounting(i, j, x, y)* - número de elementos com valores entre x e y no intervalo [i, j]

Operações de *update*, como:

- *SwapContiguous(i)* - swap dos elementos *i* e *i+1*

- *TogglingElements(i)* - troca o estado de *i* de ativo para inativo

- *push e pop (back ou front)* - adiciona ou remove elementos do começo ou final da sequência

## Construção

Seja:

- S o nó atual

- low(S) o menor elemento existente no nó S

- high(S) o maior elemento existente em S

- mid(S) a média aritmética entre low(S) e high(S).

O filho da esquerda de S - chamado de left(S) - é a subsequência de S que possui todos os elementos *menores ou iguais* a mid(S).

O filho da direita de S - chamado de rigth(S) - é a subsequência de S que possui todos os elementos *maiores* que mid(S).

A recursão para ao chegar em um nó folha: todos os elementos são iguais - ou seja, low(S) = high(S)

## Dados sobre a árvore

Considere que o tamanho do alfabeto em questão seja σ (por exemplo, o range de elementos é 1, 2, ..., σ). A cada nó novo, ocorre a divisão do intervalo pela metade. Logo, percebe-se que a altura máxima da árvore será *log(σ)*. A cada nível, teremos no pior caso *n* elementos, portanto a construção de uma wavelet tree simples (sem a adição de estruturas adicionais) tem uma complexidade de *O(n log(σ))*. Operações de *update* e *query*, que serão vistas posteriormente, também possuirão uma complexidade média de *O(log(σ))*.

## Problemas

Aqui vai uma lista de problemas que podem ser passados com wavelet tree. Todos eles podem ser resolvidos de outras maneiras (segtree persistente, mergesort tree e afins), mas tente fazer com wavelet :)

- [MKTHNUM](https://www.spoj.com/problems/MKTHNUM/) - OBS: o range de valores é muito alto (compressão talvez ajude). [Solução](https://ideone.com/sLdGYQ)
- [Destiny](https://codeforces.com/contest/840/problem/D) - esse problema fica (bem) direto com wavelet :) [Solução](https://codeforces.com/contest/840/submission/60193131)
- [ILKQUERY](https://www.spoj.com/problems/ILKQUERY/) - problemas sugeridos pelos autores do paper [Solução](https://ideone.com/VJtUTO)
- [ILKQUERY2](https://www.spoj.com/problems/ILKQUERY2/) - precisa saber como dar toggle em elementos - O(n log^2) [Solução](https://ideone.com/M6uwpr)
- [ILKQUERY3](https://www.spoj.com/problems/ILKQUERYIII/) - precisa da nocao de swap a[i] e a[i+1]. [Solução](https://ideone.com/BDDrk3)
- [CNTINDX](https://www.spoj.com/problems/CNTINDX/) - ideia de push_back() e pop_back(). [Solução](https://ideone.com/t48OOZ)

## Referências

- [Paper da IOI](https://users.dcc.uchile.cl/~jperez/papers/ioiconf16.pdf)
- [Video-aula do Gaurav Sen](https://www.youtube.com/watch?v=CybAgVF-MMc)