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
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

const int MAXN = 2e5 + 1;

using bts = bitset<2 * MAXN + 2>;

inline void run_test(int test_number) {
	int n, m; rd(n, m);
	string s; rd(s);
	n++;
	s = "X" + s;

	const int BKSZ = sqrt(n + 10) + 1;
	const int BKQT = (n + BKSZ) / BKSZ;

	vector<bts> freq(BKQT);
	vector<int> sum(BKQT * BKSZ);
	for (int i = 0; i < n; i++) {
		if (i > 0) sum[i] = sum[i-1];
		sum[i] += (s[i] == '+') - (s[i] == '-');
		freq[i / BKSZ][sum[i] + MAXN] = 1;
	}

	auto get_prefix = [&](int l) {
		int B = l / BKSZ;
		bts ans;
		for (int i = 0; i < B; i++) ans |= freq[i];
		for (int i = B * BKSZ; i <= l; i++) ans[sum[i] + MAXN] = 1;
		return ans;
	};

	auto get_suf = [&](int r) {
		int B = r / BKSZ;
		bts ans;
		for (int i = BKQT - 1; i > B; i--) ans |= freq[i];
		for (int i = min(n - 1, (B + 1) * BKSZ - 1); i >= r; i--) ans[sum[i] + MAXN] = 1;
		return ans;
	};

	for (int i = 0; i < m; i++) {
		int l, r; rd(l, r);
		int acc = sum[r] - sum[l-1];
		bts ans = get_prefix(l - 1);
		if (acc > 0) ans |= get_suf(r + 1) >> acc;
		else ans |= get_suf(r + 1) << (-acc);
		print(ans.count());
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	rd(n_tests);
	for (int i = 1; i <= n_tests; i++) run_test(i);
}