#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
};

ostream& operator<<(std::ostream& os, const Pair<ll>& obj) { return os << obj.fi << " " << obj.se; }
ostream& operator<<(std::ostream& os, const Pair<int>& obj) { return os << obj.fi << " " << obj.se; }

int solve(string const& s, int n, int k) {
	const Pair<ll> m(1e9+7, 1e9+9);
	const Pair<ll> p(31, 37);
	Pair<ll> hash(0, 0);
	Pair<ll> curPow(1, 1);

	set<Pair<ll> > all;
	for (int i = k-1; i >= 0; i--) {
		hash = (hash + (curPow * ll(s[i] - 'a' + 1)) % m) % m;
		if (i) curPow = (curPow * p) % m;
	}

	all.insert(hash);

	for (int i = k; i < n; i++) {
		hash = (hash - (curPow * ll(s[i-k] - 'a' + 1)) + m) % m;
		hash = (((hash + m) % m + m) % m + m) % m;
		hash = (hash * p) % m;
		hash = (hash + ll(s[i] - 'a' + 1)) % m;
		all.insert(hash);
	}

	return all.size();
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
		string s; cin >> s;
		cout << solve(s, n, k) << '\n';
	}

	return 0;
}