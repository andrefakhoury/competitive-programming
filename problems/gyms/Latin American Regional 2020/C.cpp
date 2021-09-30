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

ll solve(int n, vector<ll> a) {
	stack<int> st;

	ll ans = 0;
	for (int i = n + n + n - 1; i >= 0; i--) {
		if (a[i % n] == 0) continue;
		if (a[i % n] < 0) st.emplace(i);
		else {
			while(st.size() && a[i % n] > 0) {
				auto j = st.top();
				st.pop();
				if (a[j % n] == 0) continue;

				ll qtt = min(a[i % n], - a[j % n]);

				a[i % n] -= qtt;
				a[j % n] += qtt;

				ans += (j - i) * qtt;
				if (a[j % n] < 0) st.emplace(j);
			}
		}

	}

	return ans;
	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n; rd(n);
	vector<ll> a(n);
	for (int i = 0; i < n; i++) rd(a[i]);

	ll sum = accumulate(a.begin(), a.end(), 0ll);
	ll each = sum / n;

	for (ll& i : a) i -= each;

	ll ans = LLONG_MAX;
	ans = min(ans, solve(n, a));
	reverse(a.begin(), a.end());
	ans = min(ans, solve(n, a));
	print(ans);	
}
