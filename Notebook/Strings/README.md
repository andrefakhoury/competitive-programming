# Strings

Sequencia de caracteres

S = S_0 S_1 .... S_n-1, |S| = n

## Substring

Sequencia consecutiva de chars na string

substr(i, j) = s_i ... s_j

## Prefixo

Substring comecando no 0
pref(i) = substr(0, i)

## Sufixo

Substring terminando em n-1
suf(i) = substr(i, n-1)

# Z-Function

Z[i] = {
	0, i = 0
	tamanho do maior prefixo comum entre s[0..n-1], s[i..n-1], cc
}


## Exemplos

```
S = a b a c a b a
Z = 0 0 1 0 3 0 1

S = a b a b a b
Z = 0 0 4 0 2 0
```

## Encontrar ocorrencia de padrao num texto

```
t = testsabctestabca
p = abc

s = p + '#' + t
s = a b c # t e s t s a b c t e s t a b c a
Z = 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 3 0 0 1
```

Para ver se tem ocorrencia: Z[i] == |P|

## Contrucao da Z-Function

### Implementacao Naive, O(n^2)

```C++
int n = s.size();
vector<int> z(n, 0);
for (int i = 1; i < n; i++) {
	while(i + z[i] < n && s[z[i]+i] == s[z[i]])
		z[i]++;
}
```

### Implementacao Linear, O(n)

```C++
int n = s.size();
vector<int> z(n, 0);
for (int i = 1, l = 0, r = 0; i < n; i++) {
	if (i <= r)
		z[i] = min(r - i + 1, z[i - l]);

	while(i + z[i] < n && s[z[i]+i] == s[z[i]])
		z[i]++;

	if (z[i] + i - 1 > r)
		l = i, r = i + z[i] - 1;
}
```

## Menor periodo de uma string

```
s = a b a b a b
z = 0 0 4 0 2 0

periodo = 2 (a b)
```

Periodo: menor `i` tal que `i + s[i] == n`, e `n%i == 0`

## Busca de texto em padrao com no maximo 1 erro

```
t = abcabcab
p = abdab

(padrao encontrado 2 vezes)
a b c(d) a b c(d) a b
```