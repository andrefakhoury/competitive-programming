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

	vector<int> a;
	vector<int> b;

	for (int i = 0; i < n; i++) {
		int x; rd(x);
		if (x) a.pb(x);
	}
	for (int i = 0; i < n; i++) {
		int x; rd(x);
		if (x) b.pb(x);
	}

	for (int i = 0; i < n-1; i++) a.pb(a[i]);

	bool ans = false;
	for (int i = 0; i < n-1; i++) {
		bool ok = true;
		for (int j = 0; ok && j < n-1; j++) {
			if (a[i+j] != b[j]) ok = false;
		}
		ans |= ok;
	}

	if (ans) puts("YES");
	else puts("NO");
}