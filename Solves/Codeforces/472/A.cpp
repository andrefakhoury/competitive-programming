#include <bits/stdc++.h>
using namespace std;

void initi(int n, vector<int>& not_prime) {
	for (long long i = 2; i < n; i++) {
		if (!not_prime[i]) {
			for (long long j = i*i; j < n; j += i) 
				not_prime[j] = true;
		}
	}
}

pair<int, int> solve(int n, vector<int>& not_prime) {
	for (long long i = 2; i < n; i++) {
		if (!not_prime[i]) {
			for (long long j = i*i; j < n; j += i)
				if (not_prime[j] && not_prime[n-j-1])
					return make_pair(j, n-j-1);
		}
	}
}

int main() {
	int n; cin >> n;
	vector<int> not_prime(n+1, 0);
	initi(n+1, not_prime);

	pair<int, int> ans = solve(n+1, not_prime);
	cout << ans.first << " " << ans.second << endl;

	return 0;
}