#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
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

inline void _solve_(int testCase) {
	cout << "Case #" << testCase << ": ";

	string s; cin >> s;
	int n = s.size();

	string ans;
	set<int> cur;
	int last = 0;
	for (int i = 0; i <= n; i++) {
		if (i == n || s[i] == '0') {
			if (cur.empty()) {
				if (i != n)
					ans += '0';
				last = i + 1;
				continue;
			}

			int qtt = *cur.begin();
			ans += string(qtt, '(');

			for (int j = last; j < i; j++) {
				int c = s[j] - '0';
				if (c <= qtt) {
					// fecho qtt - c
					for (int x = 0; x < qtt-c; x++)
						ans += ')';
					qtt = c;
				} else {
					// abrir c - qtt
					for (int x = 0; x < c - qtt; x++)
						ans += '(';
					qtt = c;
				}

				ans += s[j];
			}
			while(qtt--) ans += ')';

			cur.clear();
			if (i != n) ans += '0';
			last = i + 1;
		} else cur.emplace(s[i]-'0');
	}
		
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int __T__; cin >> __T__;
	for (int tt = 1; tt <= __T__; tt++) _solve_(tt);
	return 0;
}