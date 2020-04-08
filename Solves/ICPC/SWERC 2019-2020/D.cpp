#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

const int MAXN = 1e6 + 5, INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

struct Amn {
	int val;
	bool comp;
	int sz;

	bool operator==(Amn const& rhs) const {
		return tie(val, comp, sz) == tie(rhs.val, rhs.comp, rhs.sz);
	}

	bool operator<(Amn const& rhs) const {
		return tie(val, sz, comp) < tie(rhs.val, rhs.sz, rhs.comp);
	}
};

inline int add(int x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	return x;
}

inline int sub(int x, int y) {
	x -= y;
	if (x < 0) x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return ll(x) * y % MOD;
}

inline int fastpow(int x, int y) {
	int ret = 1;
	while(y) {
		if (y&1) ret = mul(ret, x);
		x = mul(x, x);
		y /= 2;
	}
	return ret;
}

inline int inv(int x) {
	return fastpow(x, MOD-2);
}

inline int divi(int x, int y) {
	return mul(x, inv(y));
}

map<Amn, pair<Amn, Amn>> mp;

inline Amn merge(Amn x, Amn y) {
	Amn res;
	res.sz = x.sz + y.sz;
	res.comp = true;
	res.val = add(x.val, mul(y.val, x.sz + 1));
	mp[res] = {x, y};
	return res;
}

inline pair<Amn, Amn> split(Amn x) {
	assert(mp.count(x));
	return mp[x];
}

pair<bool, vector<Amn>> get(string const& s) {
	vector<Amn> v(MAXN);

	for (int i = 0; i < MAXN; i++) {
		v[i] = {i+1, false, 1};
	}

	reverse(v.begin(), v.end());

	bool broken = false;
	for (char const& c : s) {
		if (c == 'C') { // duplica
			v.push_back(v.back());
		} else if (c == 'D') {
			v.pop_back();
		} else if (c == 'L') {
			if (v.back().comp) {
				Amn xx = v.back(); v.pop_back();
				v.push_back(split(xx).fi);
			} else broken = true;
		} else if (c == 'P') {
			Amn xx = v.back(); v.pop_back();
			Amn yy = v.back(); v.pop_back();
			v.push_back(merge(xx, yy));
		} else if (c == 'R') {
			if (v.back().comp) {
				Amn xx = v.back(); v.pop_back();
				v.push_back(split(xx).se);
			} else broken = true;
		} else if (c == 'S') {
			Amn xx = v.back(); v.pop_back();
			Amn yy = v.back(); v.pop_back();
			v.push_back(xx);
			v.push_back(yy);
		} else if (c == 'U') {
			if (v.back().comp) {
				Amn xx = v.back(); v.pop_back();
				pair<Amn, Amn> pp = split(xx);
				v.push_back(pp.se);
				v.push_back(pp.fi);
			} else broken = true;
		}

		if (broken) break;
	}

	return mk(broken, v);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string s; cin >> s;
	string t; cin >> t;

	pair<bool, vector<Amn>> a, b;
	a = get(s);
	b = get(t);

	bool ok = a.fi == b.fi;
	if (ok && a.fi) {
		cout << "True\n";
	} else if (ok) {
		if (a.se.size() == b.se.size()) {
			for (int i = 0; ok && i < (int)a.se.size(); i++)
				ok &= a.se[i] == b.se[i];
		} else ok = false;
		if (ok) cout << "True\n";
		else cout << "False\n";
	} else {
		cout << "False\n";
	}
}