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

template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	string tps; cin >> tps;

	vector<int> tipo(n);
	for (int i = 0; i < n; i++) {
		if (tps[i] == '<') tipo[i] = 1;
		else tipo[i] = 2;
	}

	vector<int> custo(n);
	for (int i = 0; i < n; i++) {
		cin >> custo[i];
	}

	int ans = 0;
	stack<pii> st;
	for (int i = 0; i < n; i++) {

		int sum = 0;
		while(st.size() && st.top().fi == 2) {
			sum += st.top().se;
			st.pop();
		}
		if (sum) st.emplace(2, sum);

		ans = max(ans, sum);

		if (tipo[i] == 1) st.emplace(1, custo[i]);
		else {
			int sum = 0;

			while(st.size() && st.top().fi == 2) {
				sum += st.top().se;
				st.pop();
			}

			ans = max(ans, sum);

			if (st.size()) {
				custo[i] += st.top().se;
				st.pop();
				st.emplace(2, sum + custo[i]);
			} else {
				st = {};
			}
		}

	}

	int sum = 0;
	while(st.size() && st.top().fi == 2) {
		sum += st.top().se;
		st.pop();
	}

	ans = max(ans, sum);

	cout << ans << "\n";
}