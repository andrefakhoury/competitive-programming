#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 6;

typedef long long ll;

struct ST {
	vector<ll> seg, lazy;
 
	ST() {
		seg = vector<ll>(4 * MAXN);
		lazy = vector<ll>(4 * MAXN);
 
		fill(seg.begin(), seg.end(), 0ll);
		fill(lazy.begin(), lazy.end(), 0ll);
	}
 
	ll merge(ll i, ll j) {
		return max(i, j);
	}
 
	void prop(int p, int i, int j) {
		if (!lazy[p]) return;
 
		seg[p] = merge(seg[p], lazy[p]);
 
		if (i != j) {
			lazy[2 * p] = lazy[p];
			lazy[2 * p + 1] = lazy[p];
		}
 
		lazy[p] = 0;
	}

	void build(int p, int i, int j, vector<int>& v) {
		if (i == j) {
			seg[p] = v[i];
		} else {
			int m = (i + j) / 2;
			build(2*p, i, m, v);
			build(2*p+1, m+1, j, v);
			seg[p] = merge(seg[2*p], seg[2*p+1]);
		}
	}

	int find(int p, int i, int j, int l, int r, ll x) {
		if (i > j || j < l || i > r) return MAXN;
		prop(p, i, j);
		if (seg[p] < x) return MAXN;

		if (i == j) {
			if (seg[p] >= x) return i;
			return MAXN;
		}

		int m = (i + j) / 2;

		int t1 = find(2*p, i, m, l, r, x);
		if (t1 == MAXN) return find(2*p+1, m+1, j, l, r, x);
		return t1;
	}

	int find(int l, int r, ll x) {
		return find(1, 0, MAXN-1, l, r, x);
	}
};

vector<int> build_Z(string& s) {
	int n = s.size();
	vector<int> z(n, 0);

	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);

		while(i + z[i] < n && s[z[i]+i] == s[z[i]])
			z[i]++;

		if (z[i] + i - 1 > r)
			l = i, r = i + z[i] - 1;
	}

	return z;
}

void dbg(string s, vector<int> v) {
	cout << s << endl;
	for (int i : v) cout << i << " ";
	cout << endl;
}

void print(int i = -1, int j = -1) {
	cout << i << " " << j << "\n";
	exit(0);
}

string a, b;
vector<int> z, z2, z3, tos;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string a, b;
	getline(cin, a);
	getline(cin, b);

	string b2 = b;
	reverse(b2.begin(), b2.end());

	string a2 = a;
	reverse(a2.begin(), a2.end());

	int n = a.size(), m = b.size();

	// cout << "N: ";
	// cout << n << endl;

	if (n != m) print();

	string s  = b  + char(2) + a;
	string s2 = b2 + char(2) + a;
	string s3 = a2 + char(2) + b;

	z  = build_Z(s);
	z2 = build_Z(s2);
	z3 = build_Z(s3);

	// dbg("z", z);
	// dbg("z2", z2);
	// dbg("z3", z3);


	tos.resize(MAXN + 5);
	for (int j = 0, i = m + 1; i < n + m - 1; i++, j++)
		tos[j] = z3[i];

	int ans1 = -1, ans2 = -1;

	ST seg;
	seg.build(1, 0, MAXN - 1, tos);

	for (int i = m + 2; i < n + m + 1; i++) {
		if (z[i] && z2[m + 1] >= i - m - 1) {
			int q1 = z[i];
			int q2 = min(z2[m+1], i - m - 1);

			// cout << i - m - 2 << ":" << endl;
			// cout << "q1: " << z[i] << endl;
			// cout << "q2: " << q2 << endl;
			// cout << "toFind: " << n - q1 - q2 << endl;

			int ss = seg.find(1, z[i], n - q1 - q2);
			if (ss != MAXN) {
				ans1 = i - m - 2;
				if (q1 + q2 > n - 1) ans2 = min(n-1, i - m - 1 + ss);
				else ans2 = q1 + q2;
			}
		}
	}

	print(ans1, ans2);
}



/**

a a a a a a a b c d b a a a a a a b
a a a b c d b a a a b a a a a a a a



0 1 2 3 4 5 6 7 8 9
a b c d e f g h i j

2 5
d e j i h g f c b a


d e j i h g f c b a # a b c d e f g h i j
0 0 0 0 0 0 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0

a b c f g h i j e d # a b c d e f g h i j
0 0 0 0 0 0 0 0 0 0 0 3 0 0 0 0 0 0 0 0 0

j i h g f e d c b a # d e j i h g f c b a
0 0 0 0 0 0 0 0 0 0 0 0 0 5 0 0 0 0 0 0 0

*/