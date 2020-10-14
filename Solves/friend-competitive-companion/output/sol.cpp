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

void imp() {
	cout << -1 << "\n";
	exit(0);
}

inline int check(vector<int> const& v, string const& s) {
	int n = s.size();

	int sl = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') sl++;
		else if (s[i] == ')') sl--;
		else sl -= v[i];

		if (sl < 0) imp();
	}

	return sl;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s; cin >> s;
	int n = s.size();
	vector<int> v(n, 1);
	int x = check(v, s);
	for (int i = n-1; i >= 0; i--) {
		if (s[i] == '#') {
			v[i] += x;
			break;
		}
	}

	if (check(v, s)) imp();
	for (int i = 0; i < n; i++) if (s[i] == '#') {
		cout << v[i] << "\n";
	}
}