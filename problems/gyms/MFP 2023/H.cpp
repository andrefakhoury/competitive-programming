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

template<class T> void DBG(T&& x) { cerr << x << ' '; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; rd(n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) rd(a[i]);

	vector<int> s(n-1);
	for (int i = 0; i < n-1; i++) rd(s[i]);

	map<int, int> f;
	for (int i: a) f[i]++;

	set<int> checked;
	auto check = [&](int a1) {
		if (checked.count(a1)) return;
		checked.insert(a1);

		vector<int> ans;
		ans.pb(a1);
		for (int i = 0; i < n-1; i++) {
			int cur = s[i] - ans.back();
			if (f[cur] == 0) {
				while(i > 0) f[ans[i--]]++;
				return;
			}
			f[cur]--;
			ans.pb(cur);
		}

		for (int i = 0; i < n; i++)
			cout << ans[i] << " ";
		cout << "\n";

		exit(0);
	};

	if (n <= 4) for (int i: a) check(i);

	ll tot_sum_a2 = 0;
	for (int i: a) tot_sum_a2 += i * 2;

	ll tot_sum_s = 0;
	for (int i: s) tot_sum_s += i;

	ll sum_a1_an = 0;
	for (int i = 0; i < n-1; i++) {
		if (i % 2 == 0) sum_a1_an += s[i];
		else sum_a1_an -= s[i];
	}

	for (int i: a) {
		f[i]--;

		ll an = tot_sum_a2 - i - tot_sum_s;
		ll cur_sum = n % 2 == 0 ? i + an : i - an;

		if (f[an] && sum_a1_an == cur_sum) check(i);

		f[i]++;
	}

	assert(false);
}
