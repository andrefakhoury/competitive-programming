#include <bits/stdc++.h>
using namespace std;

int N, M;
long long l, r;

long long solve(int n, int m, int k) {
	if (k >= 18) return 0;
	if (n > N and m > M) return 0;

	long long ans = 0;
	if (n == N or m == M) ans = 1;

	return ans + 8*solve(n, m, k+1) + solve(n+1, m, k+1) + solve(n, m+1, k+1);
}

int main() {
	cin >> N >> M >> l >> r;
	cout << r - l + 1 - solve(0, 0, 0) - 1 << endl;
}