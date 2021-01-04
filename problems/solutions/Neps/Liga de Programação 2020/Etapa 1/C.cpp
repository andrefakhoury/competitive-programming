#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) {cout.flush(); fflush(stdout); fprintf(stderr, args);}
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

inline long double area(vector<ll>& a) {
	if (a[0] == -1) return 0;
	long double p = (a[0] + a[1] + a[2]) / 2.0;
	return sqrt(p * (p - a[0]) * (p - a[1]) * (p - a[2]));
}

inline bool can(ll a, ll b, ll c) {
	return a + b > c && a + c > b && b + c > a;
}

int main() {
	int n; rd(n);
	vector<ll> a(n);
	for (ll& i : a) rd(i);
	sort(a.begin(), a.end());
	
	vector<ll> ans = {-1, -1, -1};
	for (int i = 0; i + 3 < n; i++) {
		if (can(a[i], a[i+1], a[i+2])) {
			vector<ll> cur = {a[i], a[i+1], a[i+2]};
			if (area(ans) < area(cur)) ans = cur;			
		}
	}

	for (ll i : ans) cout << i << " ";
	cout << endl;
}