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

Pair<ll> getHash(string const& s) {
	const Pair<ll> m(1e9+7, 1e9+9);
	const Pair<ll> p(31, 37);
	Pair<ll> hash(0, 0);
	Pair<ll> curPow(1, 1);

	for (char c : s) {
		hash = (hash + p * ll(c - 'a' + 1)) % m;
		curPow = (curPow * p) % m;
	}

	return hash;
}

int main() {
	string s = "abacaba";
	cout << getHash(s) << endl;

	return 0;
}