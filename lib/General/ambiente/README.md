# Auto test para a regional

## Preparando o ambiente

O ambiente a ser utilizado será o seguinte:

```bash
/root
.../tasks
....../<id_problema>   # A, B, C...
.........sol.cpp
.........test.sh
.........N.in          # 0.in, 1.in, ... (criado manualmente)
.........N.out         # 0.in, 0.out, ... (criado manualmente)
.../output
......sol.cpp          # ultimo arquivo .cpp usado em ./test.sh
```

Para preparar este ambiente, basta executar o arquivo `prep.sh <max_prob=Z>` (por exemplo, `./prep.sh M`).

Caso queira mudar o template, basta alterar o arquivo `template.cpp`.

## O arquivo `test.sh`

Para utilizar o arquivo `test.sh`:

- Se o executável chamar `sol.cpp`, basta executar ./test.sh
- Se tiver outro nome, execute ./test <nome_arquivo>

O executável irá testar todas as entradas `N.in`, mapeando com a respectiva `N.out`.

- Se alguma `N.out` não estiver disponível para alguma `N.in`, a entrada será executada com o veredito final "UNKNOWN".
- Se a saída `N.out` existir, será conferida (`diff -w`) e retornará **AC** ou **WA**.
- Também será informado o tempo necessário em cada caso de teste, e a memória utilizada (MAXRESIDENT), utilizando o comando `\time`.
