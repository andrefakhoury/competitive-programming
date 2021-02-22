#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

/** Möbius function
 - mu(n) = 1 if n is square-free w/ even prime factors
 - mu(n) = -1 if n is square-free w/ odd prime factors
 - mu(n) = 0 if has squared prime factor
 	(n is square-free if each prime appears only once)
*/

int mu[MAXN];

int main() {
	mu[1] = 1;
	for (int i = 1; i < MAXN; i++)
		for (int j = i + i; j < MAXN; j += i)
			mu[j] -= mu[i];
}