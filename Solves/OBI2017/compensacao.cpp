#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000
#define MAXM 1000000
#define pb push_back

typedef pair<int, int> pii;

int deb[MAXN+1];

int main() {
	ios::sync_with_stdio(false);
	int M, N, x, v, y;
	long long int soma1 = 0, soma2 = 0;
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		cin >> x >> v >> y;
		soma1 += v;
		deb[x] -= v;
		deb[y] += v;
	}

	for (int i = 1; i <= N; i++) {
		if (deb[i] >= 0) soma2 += deb[i];
	}

	if (soma1 <= soma2) {
		cout << "N\n" << soma1 << endl;
	} else if (soma2 < soma1) {
		cout << "S\n" << soma2 << endl;
	}
	return 0;
}