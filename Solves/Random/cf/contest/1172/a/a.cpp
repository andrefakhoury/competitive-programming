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

int sorted(vector<int> b) {
	int ipos = -1;
	for (int i = 0; i < (int) b.size(); i++) if (b[i] == 1) ipos = i;
	if (ipos == -1) return 0;
	for (int i = ipos + 1; i < (int) b.size(); i++) {
		if (b[i-1] + 1 != b[i]) return 0;
	}

	return (int) b.size() - ipos;
}

int solve(vector<int> a, vector<int> b, int n) {
	int last = sorted(b);
	reverse(b.begin(), b.end());

	bitset<MAXN> vis;
	for (int i = 0; i < n; i++) vis[a[i]] = 1;

	int ret = 0;
	for (int i = last + 1; i <= n; i++) {
		if (!vis[i]) return INF;
		vis[b.back()] = 1;
		b.pop_back();
		ret++;
	}

	return ret;
}

int main() {
	int n; rd(n);
	vector<int> a(n);
	vector<int> b(n);
	for (int& i : a) rd(i);
	for (int& i : b) rd(i);

	vector<int> pos(n + 1);
	for (int i = 0; i < n; i++)
		pos[b[i]] = i + 1;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, pos[i] - i + 1 + n);
	}

	ans = min(ans, solve(a, b, n));
	printf("%d\n", ans);
}