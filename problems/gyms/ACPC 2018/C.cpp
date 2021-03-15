#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) { cout.flush(); fflush(stdout); fprintf(stderr, args); }
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
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
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	freopen("coffee.in", "r", stdin);
	
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;
		map<string, int> sm, md, lr;

		int sum = 100 / m;

		while(n--) {
			string s; cin >> s;
			int a, b, c; cin >> a >> b >> c;
			sm[s] = a, md[s] = b, lr[s] = c;
		}

		auto get_val = [](int x) {
			if ((x-1)%5 == 0) return x-1;
			if ((x+1)%5 == 0) return x+1;
			return x;
		};

		while(m--) {
			string s; cin >> s;
			string sz; cin >> sz;
			string sb; cin >> sb;

			int cur = 0;
			if (sz[0] == 's') cur = sm[sb];
			if (sz[0] == 'm') cur = md[sb];
			if (sz[0] == 'l') cur = lr[sb];
			cout << s << " " << get_val(cur + sum) << '\n';
		}
	}




}