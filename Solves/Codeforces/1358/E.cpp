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

const int MAXN = 5e5 + 5, INF = 0x3f3f3f3f;

int a[MAXN];
ll sum[MAXN];

int main() {
	int n; rd(n);
	for (int i = 1; i <= (n + 1) / 2; i++) rd(a[i]);
	int x; rd(x);
	for (int i = (n + 1) / 2 + 1; i <= n; i++) a[i] = x;

	for (int i = 1; i <= n; i++)
		sum[i] = sum[i-1] + a[i];

	vector<int> pos;
	for (int i = 1; i <= n; i++) pos.eb(i);
	shuffle(pos.begin(), pos.end(), rng);

	vector<int> I;
	for (int i = 1; i <= n; i++) I.eb(i);
	shuffle(I.begin(), I.end(), rng);

	auto ck = clock();
	for (int at = 0; at < (int) pos.size() && (double(clock() - ck) / CLOCKS_PER_SEC <= 1.85); at++) {
		int k = pos[at];

		bool ok = true;
		for (int i : I)
			if (i <= n - k + 1 && sum[i+k-1] - sum[i-1] <= 0) {
				ok = false;
				break;
			}

		if (ok) {
			printf("%d\n", k);
			return 0;
		}
	}

	printf("-1\n");
}