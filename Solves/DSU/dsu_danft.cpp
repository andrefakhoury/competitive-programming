#include <bits/stdc++.h>

using namespace std;

int parent[MAX];
int altura[MAX]; //AQUI GRAVA A ALTURA DE CADA ARVORE; QUANDO FOR DAR O UNION, LIGA A MENOR NA MAIOR (PRA DAR LOG AMORTIZADO MAIS AINDA)

int find(int x) {
	if (parent[x] == -1) return x;
	return parent[x] = find(parent[x]); //comprimir a arvore
}

void Union (int x, int y) {
	int p = find(x);
	int q = find(y); //SE FIZER UNS IF LOCO AQUI MELHORA A COMPLEXIDADE
	if (p != q) parent[p] = q;
}
