#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifndef __linux
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

inline void _solve_(int __ntest__) {
	int n; cin >> n;
	string a, b; cin >> a >> b;

	vector<int> ans;

	deque<char> dq;
	for (int i = 0; i < n; i++) dq.push_back(a[i]);

	int qtt = 0;
	for (int i = n-1; i >= 0; i--) {
		// cout << "[" << i << ", " << qtt << "] ";
		// for (char j : dq) cout << j << " ";
		// cout << endl;

		if (qtt%2 == 0) { // back
			if (dq.back() == b[i]) {
				dq.pop_back();
				continue;
			}

			if (dq.back() != dq.front()) {
				ans.pb(1);
			}

			qtt++;
			ans.pb(i+1);
			dq.pop_front();
		} else { // front
			if (dq.front() == ((b[i]-'0')^1)+'0') {
				dq.pop_front();
				continue;
			}

			if (dq.back() != dq.front()) {
				ans.pb(1);
			}

			qtt++;
			ans.push_back(dq.size());
			dq.pop_back();
		}
	}

	cout << ans.size() << " ";
	for (int i : ans) {
		cout << i << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	// int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}