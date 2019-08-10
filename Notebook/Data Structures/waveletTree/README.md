# Wavelet Tree

Estrutura de dados que particiona recursivamente uma sequência A em uma árvore (binária), de acordo com os valores de A. Cada nó da árvore é associado à uma subsequência de A. O nó raíz representa toda a sequência A.

Pode ser utilizada em operações de *query* e *update*, e inclusive combinada com outras estruturas de dados para obter melhor performance e mais utilidade.

## Utilidades Utilidades

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

### Exemplo

![GeeksForGeeks](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/Wavelet_Tress-1.png)

## Dados sobre a árvore

Considere que o tamanho do alfabeto em questão seja σ (por exemplo, o range de elementos é 1, 2, ..., σ). A cada nó novo, ocorre a divisão do intervalo pela metade. Logo, percebe-se que a altura máxima da árvore será *log(σ)*. A cada nível, teremos no pior caso *n* elementos, portanto a construção de uma wavelet tree simples (sem a adição de estruturas adicionais) tem uma complexidade de *O(n log(σ))*. Operações de *update* e *query*, que serão vistas posteriormente, também possuirão uma complexidade média de *O(log(σ))*.