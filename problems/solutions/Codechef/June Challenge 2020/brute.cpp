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

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct A {
	int x, y, z;

	inline void read() {
		rd(x, y, z);
	}

	bool operator<(A const& b) const {
		return tie(x, y, z) < tie(b.x, b.y, b.z);
	}

	bool operator==(A const& b) const {
		return tie(x, y, z) == tie(b.x, b.y, b.z);
	}
};

inline A sum(A u, int k, vector<int>&& pos) {
	for (int i : pos) {
		if (i == 0) u.x += k;
		if (i == 1) u.y += k;
		if (i == 2) u.z += k;
	}
	return u;
}

inline A mul(A u, int k, vector<int>&& pos) {
	for (int i : pos) {
		if (i == 0) u.x *= k;
		if (i == 1) u.y *= k;
		if (i == 2) u.z *= k;
	}
	return u;
}

inline void _solve_(int __ntest__) {
	A a, b;
	a.read();
	b.read();

	map<A, int> vis;
	vis[a] = 0;
	queue<A> q;
	q.emplace(a);

	while(q.size()) {
		A u = q.front();
		q.pop();

		if (u == b) {
			printf("%d\n", vis[u]);
			return;
		}

		auto tenta = [&](A v) {
			if (!vis.count(v)) {
				q.emplace(v);
				vis[v] = vis[u] + 1;
			}
		};

		for (int i = -100; i <= 100; i++) {
			tenta(sum(u, i, {0}));
			tenta(sum(u, i, {1}));
			tenta(sum(u, i, {2}));
			tenta(sum(u, i, {0, 1}));
			tenta(sum(u, i, {0, 2}));
			tenta(sum(u, i, {1, 2}));
			tenta(sum(u, i, {0, 1, 2}));

			tenta(mul(u, i, {0}));
			tenta(mul(u, i, {1}));
			tenta(mul(u, i, {2}));
			tenta(mul(u, i, {0, 1}));
			tenta(mul(u, i, {0, 2}));
			tenta(mul(u, i, {1, 2}));
			tenta(mul(u, i, {0, 1, 2}));
		}
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}