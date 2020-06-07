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
inline void _solve_(int __ntest__) {
	int n; rd(n);
	map<int, int> f[2];

	vector<int> a(n);
	for (int& i : a) rd(i);
	vector<int> b(n);
	for (int& i : b) rd(i);

	for (int i : a) f[0][i]++;
	for (int i : b) f[1][i]++;

	if (f[0] != f[1] or (n%2 && a[n/2] != b[n/2])) {
		puts("No");
		return;
	}

	map<int, multiset<int>> who;
	for (int i = 0; i < n; i++) {
		who[a[i]].emplace(a[n-i-1]);
	}

	for (int i = 0; i < n/2; i++) {
		if (who[b[i]].count(b[n-i-1])) {
			who[b[i]].erase(who[b[i]].find(b[n-i-1]));
			who[b[n-i-1]].erase(who[b[n-i-1]].find(b[i]));
		} else {
			puts("No");
			return;
		}
	}
	puts("Yes");
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}

// sempre que tem um cara, tem o reverso dele
// caras do meio sao sempre duplinhas I, N-i
// o cara do comeco sempre vai vir junto do N-i