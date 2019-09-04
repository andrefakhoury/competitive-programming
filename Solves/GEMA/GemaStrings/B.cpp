#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

map<pair<pair<ll, ll>, ll>, ll> mapInv;

ll fastExp(ll a, ll b, ll m) {
	if (mapInv.count(make_pair(make_pair(a, b), m))) return mapInv[make_pair(make_pair(a, b), m)];

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

const Pair<ll> m(1e9+7, 1e9+9);
const Pair<ll> p(131, 137);
Pair<ll> curPow(1, 1);

map<string, Pair<ll> > mapHash;
map<string, vector<Pair<ll>>> mapHashVec;

Pair<ll> getHash(string& s) {
	if (mapHash.count(s)) return mapHash[s];

	Pair<ll> hash(0, 0);
	curPow = Pair<ll>(1, 1);

	for (char c : s) {
		hash = (hash + curPow * ll(c)) % m;
		curPow = (curPow * p) % m;
	}

	curPow = curPow * curPow.inv(m);

	return hash;
}

vector<Pair<ll>> getVecHash(string& s) {
	if (mapHashVec.count(s)) return mapHashVec[s];

	Pair<ll> hash(0, 0);
	curPow = Pair<ll>(1, 1);

	vector<Pair<ll>> ret;
	for (char c : s) {
		hash = (hash + curPow * ll(c)) % m;
		curPow = (curPow * p) % m;
		ret.emplace_back(hash);
	}

	curPow = curPow * curPow.inv(m);

	return ret;
}

string solve(string& a, string& b) {
	int n;
	Pair<ll> hashA = getHash(a);
	vector<Pair<ll>> hashB = getVecHash(b);
	n = min(a.size(), b.size());

	for (int i = 0; i + n < (int) a.size(); i++) {
		hashA = ((hashA - ll(a[i])) % m + m) % m;
		hashA = (hashA * p.inv(m)) % m;
	}

	for (int i = a.size() - n; i < (int) a.size(); i++) {
		int tam = a.size() - i;

		if (hashA == hashB[tam-1]) return a + b.substr(tam, b.size());

		hashA = ((hashA - ll(a[i])) % m + m) % m;
		hashA = (hashA * p.inv(m)) % m;
	}

	return a + b;
}

int main () {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	string s; cin >> s;

	for (int i = 1; i < n; i++) {
		string t; cin >> t;
		s = solve(s, t);
	}

	cout << s << '\n';
	return 0;
}