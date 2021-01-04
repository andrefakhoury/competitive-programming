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
	int n; rd(n);
	vector<int> a(n);
	for (auto& i : a) rd(i);

	int ans = n;

	{
		int cur = 0;
		int x[2] = {1, -1};
		for (int i = 0; i < n; i++) {
			cur += a[i] != x[i%2];
		}
		ans = min(ans, cur);
	}

	{
		int cur = 0;
		int x[2] = {-1, 1};
		for (int i = 0; i < n; i++) {
			cur += a[i] != x[i%2];
		}
		ans = min(ans, cur);
	}

	printf("%d\n", ans);
}