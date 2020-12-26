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

const int MAXN = 3e5 + 5, INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s; cin >> s;
	int n = s.size();

	string a = s.substr(0, n/2);
	string b = s.substr(n/2);

	auto rotate = [](string& s) {
		int num = 0;
		for (char c : s) num += c - 'A';
		for (char& c : s) {
			c = ((c - 'A') + num) % 26 + 'A';
		}
	};

	rotate(a);
	rotate(b);

	for (int i = 0; i < n/2; i++) {
		a[i] = (a[i] - 'A' + b[i] - 'A') % 26 + 'A';
	}

	cout << a << endl;
}