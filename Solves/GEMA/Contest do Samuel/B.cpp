#include <bits/stdc++.h>
using namespace std;

long long n, k, m, s;

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		scanf("%lld%lld%lld", &n, &k, &m);
		s = (n+k-1)/k;
		printf("%lld ", s);

		// I have to make S sandwiches
		// --|--|---
		// n bolas
		// s-1 paus
		// cada um de tamanho minimo k
	}
}


// 7! = 5040
// 6! = 720
// 5! = 120
// 4! = 24
// 3! = 6
// 2! = 2

// 9! /