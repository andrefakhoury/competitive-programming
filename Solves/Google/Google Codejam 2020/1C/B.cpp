#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) { cout.flush(); fflush(stdout); fprintf(stderr, args); }
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
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
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 1e4, INF = 0x3f3f3f3f;
inline void _solve_(int __ntest__) {
	auto ck = clock();

	cout << "Case #" << __ntest__ << ": ";

	int u; cin >> u;

	set<char> all;

	vector<pair<int, string>> a;
	for (int i = 0; i < MAXN; i++) {
		int m; cin >> m;
		string q; cin >> q;

		if (q == "-1") {

		} else {
			for (char c : q) all.emplace(c);
			a.eb(m, q);
		}
	}

	sort(a.begin(), a.end());

	vector<char> pos[10];
	for (int i = 0; i < 10; i++) {
		for (char c : all) pos[i].eb(c);
	}

	bitset<256> used;
	auto get = [&]() {
		string s;
		used = 0;
		for (int i = 0; i < 10; i++) {
			char curr = pos[i][rng()%pos[i].size()];
			if (used[curr]) {
				i--;
				continue;
			}
			used[curr] = 1;
			s += curr;
		}
		return s;
	};

	vector<int> idx(256);
	int cnt = 0;
	for (char x : all) idx[x] = cnt++;

	auto can = [&](string const& d, string const& r, int maxi, string const& val) {

		long long cur = 0;
		for (int i = val.size()-1; i >= 0; i--) {
			cur *= 10;
			cur += r[idx[val[i]]];
		}

		cout << cur << " vs " << maxi << endl;

		return cur <= maxi;
	};

	while(double(clock() - ck) / CLOCKS_PER_SEC <= 1.8) {
		string d = get();
		string r(10, 0);

		for (int i = 0; i < 10; i++)
			r[idx[d[i]]] = i;

		bool ok = true;
		for (auto p : a) {
			cout << p.fi << " " << p.se << endl;
			if (!can(d, r, p.fi, p.se)) {
				ok = false;
				break;
			}
		}

		if (ok) {
			cout << d << "\n";
			return;
		}
	}

	cout << get() << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int __T__; cin >> __T__;
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}