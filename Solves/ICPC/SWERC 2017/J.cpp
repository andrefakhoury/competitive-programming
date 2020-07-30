#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __linux
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	int n; rd(n);
	vector<ll> a(n);
	vector<ll> b(n);
	for (ll& i : a) rd(i);
	for (ll& i : b) rd(i);

	ll ans[3] = {};
	ll cb[3] = {};

	for (int j = 0; j < 3; j++) {
		for (int i = j; i < n; i += 3)
			cb[j] += b[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			ans[(i+j+2)%3] += a[i] * cb[j];
		}
	}

	for (int i = 0; i < 3; i++)
		printf("%lld ", ans[i]);
	printf("\n");
}