#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl 
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
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	int a1, a2; rd(a1, a2);
	int k1, k2; rd(k1, k2);
	int n; rd(n);

	if (k1 > k2) {
		swap(k1, k2);
		swap(a1, a2);
	}

	// k1 <= k2;
	auto go1 = [](int a1, int a2, int k1, int k2, int n) {
		multiset<int> b1;
		for (int i = 0; i < a1; i++) b1.insert(k1);
		for (int i = 0; i < a2; i++) b1.insert(k2);

		int ans = 0;
		while(n--) {
			int l = *b1.rbegin();
			b1.erase(b1.find(l));
			l--;
			if (l == 0) {
				ans++;
			} else b1.insert(l);
		}

		return ans;
	};

	auto go2 = [](int a1, int a2, int k1, int k2, int n) {
		int q1 = min(k1 * a1, n);
		int ans = q1 / k1;
		n -= q1;
		int q2 = min(k2 * a2, n);
		ans += q2 / k2;
		return ans;
	};

	printf("%d %d\n", go1(a1, a2, k1, k2, n), go2(a1, a2, k1, k2, n));


	
}
