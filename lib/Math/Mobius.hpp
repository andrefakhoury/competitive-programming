namespace Mobius {
	/** Möbius function
	 - mu(n) = 1 if n is square-free w/ even prime factors
	 - mu(n) = -1 if n is square-free w/ odd prime factors
	 - mu(n) = 0 if has squared prime factor
		(n is square-free if each prime appears only once)
	*/
	vector<int> init_mu(const int MAXN) {
		vector<int> mu(MAXN);
		mu[1] = 1;
		for (int i = 1; i < MAXN; i++)
			for (int j = i + i; j < MAXN; j += i)
				mu[j] -= mu[i];
		return mu;
	}
}