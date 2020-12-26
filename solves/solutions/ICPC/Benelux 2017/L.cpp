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

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	map<string, long double> mx;
	mx["pink"] = 0;

	while(n--) {
		string s, t;
		cin >> s >> t;
		long double x;
		cin >> x;

		if (!mx.count(t)) continue;

		if (!mx.count(s) or mx[s] < mx[t] + log(x)) {
			mx[s] = mx[t] + log(x);
		}

		if (mx.count("blue") && mx["blue"] >= log(10))
			mx["blue"] = log(10);
	}

	long double ans = 0;
	if (mx.count("blue")) ans = exp(mx["blue"]);
	cout << fixed << setprecision(12) << ans << '\n';


}