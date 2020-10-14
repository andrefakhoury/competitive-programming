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
#ifdef _WIN32
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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	ll num = 0;
	ll den = 1ll * n;
	ll sum = 0;
	ll rsum = accumulate(a.begin(), a.end(), 0ll);

	for (int i = 0; i < n; i++) {
		rsum -= a[i];

		ll qtt = i + 1;
		ll rqtt = n - i - 1;

		num += 1ll * qtt * a[i];
		num -= sum;
		num += rsum;
		num -= 1ll * rqtt * a[i];

		sum += a[i];
	}
	cerr << num << " " << den << "\n";

	ll g = __gcd(num, den);
	cout << num / g << " " << den / g << "\n";
}



/**

    [2, 3, 5]: |2 – 0| + |3 – 2| + |5 – 3| = 5;
    [2, 5, 3]: |2 – 0| + |5 – 2| + |3 – 5| = 7;
    [3, 2, 5]: |3 – 0| + |2 – 3| + |5 – 2| = 7;
    [3, 5, 2]: |3 – 0| + |5 – 3| + |2 – 5| = 8;
    [5, 2, 3]: |5 – 0| + |2 – 5| + |3 – 2| = 9;
    [5, 3, 2]: |5 – 0| + |3 – 5| + |2 – 3| = 8.

*/