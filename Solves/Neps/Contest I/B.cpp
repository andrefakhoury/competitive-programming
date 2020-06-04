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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	set<int> all;
	for (ll i = 1, j = 1; i <= 1e13;) {
		all.emplace(i);
		all.emplace(j);
		ll x = i + j;
		i = j;
		j = x;
	}

	int n; rd(n);

	string ans(n, '9');
	for (int x : all) {
		if (x < n) continue;
		// da pra fazer x?

		string cur;
		bool flag = true;
		for (int i = 0, s = 0; i < n; i++) {
			bool ok = false;
			for (int d = 1; d <= 9; d++) {
				if (s + d + 9 * (n - i - 1) >= x) {
					cur += d + '0';
					s += d;
					ok = true;
					break;
				}
			}
			if (!ok) {
				flag = false;
				break;
			}
		}

		if (flag)
			ans = min(ans, cur);
	}

	printf("%s\n", ans.c_str());
}