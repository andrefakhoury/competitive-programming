#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 700;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline ll lcm(ll a, ll b) {
	return a * (b / __gcd(a, b));
}

inline ll gcd(ll a, ll b) {
	return __gcd(a, b);
}

ll mat[MAXN][MAXN];
ll aux[MAXN][MAXN];

bool isPrime(ll n) {
	for (ll i = 2; i * i <= n; i++) if (n%i == 0) return false;
	return true;
}

int main() {
	vector<int> primes;
	for (int i = 2; primes.size() < 1e4; i++) {
		if (isPrime(i))
			primes.pb(i);
	}

	int r, c; scanf("%d%d", &r, &c);

	bool inverte = false;
	if (r > c) {
		inverte = true;
		swap(r, c);
	}

	if (r == 1 && c == 1) return !printf("0\n");

	if (r == 1) {
		for (int i = 1; i <= c; i++)
			mat[1][i] = i+1;
	} else {
		for (int i = 1; i <= c; i++)
			mat[1][i] = i+1;

		for (int i = 2; i <= r; i++) {
			mat[i][0] = c+i;
			for (int j = 1; j <= c; j++)
				mat[i][j] = lcm(mat[1][j], mat[i][0]);
		}
	}

	if (inverte) {
		for (int i = 1; i <= c; i++) {
			for (int j = 1; j <= r; j++) {
				printf("%lld ", mat[j][i]);
				aux[i][j] = mat[j][i];
			}
			printf("\n");
		}
		swap(r, c);
	} else {
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				printf("%lld ", mat[i][j]);
				aux[i][j] = mat[i][j];
			}
			printf("\n");
		}
	}

	set<int> fn;
	for (int i = 1; i <= r; i++) {
		ll g = 0;
		for (int j = 1; j <= c; j++) {
			g = __gcd(g, aux[i][j]);
		}
		fn.emplace(g);
	}
	for (int i = 1; i <= c; i++) {
		ll g = 0;
		for (int j = 1; j <= r; j++) {
			g = __gcd(g, aux[j][i]);
		}
		fn.emplace(g);
	}
	assert((int)fn.size() == r+c);
	// printf("%ld vs %lld\n", fn.size(), r+c);
	// for (int x : fn) printf("%d ", x);
	// printf("\n");

	return 0;
}