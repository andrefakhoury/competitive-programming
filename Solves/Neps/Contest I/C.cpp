#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 1e3 + 5, INF = 0x3f3f3f3f;

int a[MAXN][MAXN];

int main() {
	int n; rd(n);

	for (int i = 1; i <= n/2; i++) {
		for (int j = 1; j <= n; j++) {
			a[i][j] = 0;
			if (i%2 == 1 && j >= i && j <= n-i+1) a[i][j] = 1;
			a[n-i+1][j] = a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j])
				a[j][i] = a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int sum = a[i-1][j] + a[i+1][j] + a[i][j-1] + a[i][j+1];
			if (sum != 2) return !printf("-1\n");
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}