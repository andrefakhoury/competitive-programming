/** Eratosthenes sive. O(n loglogn) */
bool comp[MAXN];
void sieve(int N = MAXN-1) {
	for (int i = 2; i <= N; i++) {
		if (comp[i]) continue;
		for (int j = i * i; j <= N; j += i) comp[j] = true;
	}
}