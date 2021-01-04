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

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);
	int n; rd(n);
	vector<ll> a(n);
	for (ll& i : a) rd(i);
	// sort(a.begin(), a.end());
	ll ans = a[n-1] * a[n-2] * a[n-3];
	ans = max(ans, a[0] * a[1] * a[n-1]);

	vector<ll> b;
	vector<int> used(n);
	for (int i = 0; i < min(n, 100); i++) {
		b.emplace_back(a[i]);
		used[i] = true;
	}

	for (int j = n-1; j >= max(0, n - 100); j--) {
		if (!used[j]) b.emplace_back(a[j]);
	}

	sort(b.begin(), b.end());
	for (int i = 0; i < (int) b.size(); i++) {
		for (int j = i + 1; j < (int) b.size(); j++) {
			for (int k = j + 1; k < (int) b.size(); k++) {
				ans = max(ans, a[i] * a[j] * a[k]);
			}
		}
	}

	cout << ans << "\n";
}