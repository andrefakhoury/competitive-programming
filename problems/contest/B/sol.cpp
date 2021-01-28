#include <bits/stdc++.h>

#define deb(x) (cout << #x << ": " << x << endl)
#define pb push_back
#define fi first
#define se second
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 7;

struct Bit {
	int n;
	vector<ll> bt;

	void init(int n) {
		this->n = n;
		bt.assign(n + 10, 0);
	}

	void update(int i, int v) {
		for (i++; i > 0; i -= i&-i) bt[i] += v;
	}
	ll query(int i) {
		ll r = 0;
		for (i++; i < n + 5; i += i&-i) r += bt[i];
		return r;
	}
};

// Retorna um vetor com os indices de inicio de prefixo.
vector<int> build_suffix_array(string & s) {
	int n = s.size();
	vector<int> head(n), a(n), a1(n), c(n), c1(n);

	for(int i = 0; i < n; ++i) a[i] = i;
	sort(a.begin(), a.end(), [&](int i, int j) {
		return s[i] < s[j];
	});
	int cc = 0;
	for(int i = 0; i < n; ++i) {
		if(i == 0 or s[a[i]] != s[a[i-1]]) {
			c[a[i]] = cc;
			head[cc++] = i;
		} else c[a[i]] = c[a[i-1]];
	}

	int l = 1, i, j;
	while(l < n) {
		for(i = 0; i < n; ++i) {
			j = (a[i] - l + n)%n;
			a1[head[c[j]]++] = j;
		}
		cc = 0;

		head.assign(head.size(), 0);
		for(i = 0; i < n; ++i) {
			if(i == 0 or c[a1[i]] != c[a1[i-1]] or c[(a1[i] + l)%n] != c[(a1[i-1] + l)%n]) {
				head[cc] = i;
				c1[a1[i]] = cc++;
			} else c1[a1[i]] = c1[a1[i-1]];
		}

		a.assign(a1.begin(), a1.end());
		c.assign(c1.begin(), c1.end());
		l <<= 1;
	}

	return a;
}


// returns lcp array, with size a.size()-1, in which lcp[i] represents
// the longest common prefix between suffix in position i and the one in i+1
vector<int> build_lcp(vector<int> & a, string & s) {
	int n = a.size();
	vector<int> pos(n), lcp(n-1);
	for(int i = 0; i < n; ++i) {
		pos[a[i]] = i;
	}

	int sz = 0;
	for(int i = 0; i < n; ++i) {
		if(pos[i] == n-1) continue;
		int j = a[pos[i] + 1];
		while(i + sz < n and j + sz < n and s[i + sz] == s[j + sz]) sz++;
		lcp[pos[i]] = sz;
		if(sz) sz--;
	}
	return lcp;
}

struct segtree {
	vector<int> seg;
	int n;
	segtree(int n) {
		seg.assign(n + n, 0x3f3f3f3f);
		this->n = n;
	}

	void update(int p, int val) {
		for(p += n, seg[p] = val; p > 0; p >>= 1) {
			seg[p >> 1] = min(seg[p], seg[p^1]);
		}
	}

	int query(int l, int r) {
		int ans = 0x3f3f3f3f;
		for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if(l&1) ans = min(ans, seg[l++]);
			if(r&1) ans = min(ans, seg[--r]);
		}
		return ans;
	}
};

int f[N]; // f[i] calcula maior substring comum comecando em i de s1

void _solve() {
	string s, t;
	cin >> s >> t;

	for (int i = 0; i < (int) s.size(); ++i) f[i] = 0;

	string S = s + '$' + t + '#';
	int fim = (s + '$').size();

	vector<int> a = build_suffix_array(S);
	vector<int> lcp = build_lcp(a, S);

	segtree seg(lcp.size());
	for (int i = 0; i < (int) lcp.size(); ++i) seg.update(i, lcp[i]);

	int last = 0;
	for (int i = 2; i < (int) a.size(); ++i) {
		if (a[i] < (int) s.size() and last) {
			f[a[i]] = seg.query(last, i);
		}
		if (a[i] >= fim) last = i;
	}

	last = 0;
	for (int i = a.size() - 1; i > 1; --i) {
		if (a[i] < (int) s.size() and last) {
			f[a[i]] = max(f[a[i]], seg.query(i, last));
		}
		if (a[i] >= fim) last = i;
	}

	int q;
	cin >> q;

	int n = s.size();

	vector<vector<ii>> qry(n + 1);
	vector<vector<int>> rem(n + 5);

	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		qry[r].emplace_back(i, l);
	}

	vector <ll> ans(q);

	Bit btn[2], btf;
	btn[0].init(n);
	btn[1].init(n);
	btf.init(n);

	for (int i = l; i <= r; i++)
		ans += min(f[i], r - i + 1);

	for (int i = 0; i < n; i++) {
		btn[0].update(i, 1);
		btn[1].update(i, i);
		rem[i + f[i]].pb(i);
		for (int j : rem[i]) {
			btn[0].update(j, -1);
			btn[1].update(j, -j);
			btf.update(j, f[j]);
		}

		for (auto [id, l] : qry[i]) {
			ans[id] = btf.query(l) + 1ll * btn[0].query(l) * (i + 1) - btn[1].query(l);
		}
	}

	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	freopen("curse.in", "r", stdin);

	int T; cin >> T;
	for (int cs = 1; cs <= T; cs++) {
		cout << "Case " << cs << ":\n";
		_solve();
	}
}