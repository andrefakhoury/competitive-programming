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

inline void run_test(int test_number) {
	string s; cin >> s;
	vector<int> a(500);
	for (char i = '1'; i <= '9'; i++) rd(a[i]);

	int n = s.size();
	string ans;

	int j = 0;
	for (int i = 0; i < n; i++) {
		for (char d = '9'; d >= '1'; d--) {
			bool can = true;

			int l = j;
			while(l < n && s[l] != d) l++;
			if (l == n) continue;

			// deleto todos de [j, l]

			vector<int> nx_a = a;
			for (int k = j; k < l; k++) {
				nx_a[s[k]]--;
				can &= nx_a[s[k]] >= 0;
			}
			int cnt_eq = 0;
			for (int k = l + 1; k < n; k++) {
				if (s[k] == d) cnt_eq++;
			}

			can &= nx_a[d] <= cnt_eq;

			if (can) {
				ans += d;
				j = l + 1;
				a = nx_a;
				break;
			}
		}
	}
	print(ans);

}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}