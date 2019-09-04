#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e6 + 5;

ll fastExp(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

template<typename T>
struct Pair {
	T fi, se;

	Pair() {}
	Pair(T a, T b) {
		fi = a;
		se = b;
	}

	Pair operator*(ll p) const {
		return Pair(fi * p, se * p);
	}

	Pair operator+(ll p) const {
		return Pair(fi + p, se + p);
	}

	Pair operator-(ll p) const {
		return Pair(fi - p, se - p);
	}

	Pair operator-(Pair p) const {
		return Pair(fi - p.fi, se - p.se);
	}

	Pair operator*(Pair p) const {
		return Pair(fi * p.fi, se * p.se);
	}

	Pair operator+(Pair p) const {
		return Pair(fi + p.fi, se + p.se);
	}

	Pair operator%(Pair p) const {
		return Pair(fi % p.fi, se % p.se);
	}

	bool operator<(const Pair& p) const {
		return fi == p.fi ? se < p.se : fi < p.fi;
	}

	bool operator==(const Pair p) const {
		return fi == p.fi && se == p.se;
	}

	T& operator[](size_t i) {
		return i == 0 ? fi : se;
	}

	Pair inv(const Pair m) const {
		return Pair(fastExp(fi, m.fi - 2, m.fi), fastExp(se, m.se - 2, m.se));
	}
};

ostream& operator<<(std::ostream& os, const Pair<ll>& obj) { return os << obj.fi << " " << obj.se; }
ostream& operator<<(std::ostream& os, const Pair<int>& obj) { return os << obj.fi << " " << obj.se; }

const Pair<ll> m(1e9+7, 1e9+9);
const Pair<ll> p(31, 37);
const Pair<ll> PINV = p.inv(m);
Pair<ll> curPow[MAXN];

map<string, int> getId;
Pair<ll> Hash[3][MAXN];
map<string, Pair<ll>> memoHash;
ll dis[256];

Pair<ll> getHash(string& s) {
	if (memoHash.count(s)) return memoHash[s];

	Pair<ll> hash(0, 0);
	for (int i = 0; i < (int)s.size(); i++)
		hash = (hash + curPow[i] * dis[s[i]]) % m;

	return memoHash[s] = hash;
}

string solve(string& a, string& b) {
	Pair<ll> hashA = getHash(a);
	
	int n = min(a.size(), b.size());
	for (int i = 0; i + n < (int) a.size(); i++) {
		hashA = ((hashA - dis[a[i]]) % m + m) % m;
		hashA = (hashA * PINV) % m;
	}

	int ans = 0, id = getId[b];
	for (int i = a.size() - n, j = n-1; i < (int) a.size(); i++, j--) {
		if (hashA == Hash[id][j]) {
			ans = j + 1;
			break;
		}

		hashA = ((hashA - dis[a[i]]) % m + m) % m;
		hashA = (hashA * PINV) % m;
	}

	return a + ((ans >= (int)b.size()) ? string("") : b.substr(ans, b.size()));
}

int solve(string& a, string& b, string& c) {
	string g = solve(a, b);
	string f = solve(g, c);

	return f.size();
}

int main () {
	curPow[0] = Pair<ll>(1, 1);
	for (int i = 1; i < MAXN; i++) curPow[i] = (curPow[i-1] * p) % m;
	for (char c = 'a'; c <= 'z'; c++) dis[c] = c - 'a' + 1;

	ios::sync_with_stdio(false); cin.tie(NULL);

	string a, b, c;
	while(cin >> a >> b >> c) {
		int ans = INT_MAX;

		getId[a] = 0;
		getId[b] = 1;
		getId[c] = 2;

		Hash[0][0] = (curPow[0] * ll(a[0] - 'a' + 1)) % m;
		for (int j = 1; j < (int)a.size(); j++)
			Hash[0][j] = (Hash[0][j - 1] + (curPow[j] * ll(a[j] - 'a' + 1)) % m) % m;

		Hash[1][0] = (curPow[0] * ll(b[0] - 'a' + 1)) % m;
		for (int j = 1; j < (int)b.size(); j++)
			Hash[1][j] = (Hash[1][j - 1] + (curPow[j] * ll(b[j] - 'a' + 1)) % m) % m;

		Hash[2][0] = (curPow[0] * ll(c[0] - 'a' + 1)) % m;
		for (int j = 1; j < (int)c.size(); j++)
			Hash[2][j] = (Hash[2][j - 1] + (curPow[j] * ll(c[j] - 'a' + 1)) % m) % m;

		ans = min(ans, solve(a, b, c));
		ans = min(ans, solve(a, c, b));
		ans = min(ans, solve(b, a, c));
		ans = min(ans, solve(b, c, a));
		ans = min(ans, solve(c, a, b));
		ans = min(ans, solve(c, b, a));

		cout << ans << '\n';

		for (int i = 0; i < max({a.size(), b.size(), c.size()}); i++)
			Hash[0][i] = Hash[1][i] = Hash[2][i] = {0, 0};
	}

	return 0;
}