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

char aux[MAXN];

int main() {
	int n; rd(n);

	set<string> st;
	for (int i = 1; i <= n; i++) {
		scanf(" %[^\n\r]", aux);

		int len = strlen(aux);
		string s;
		for (int k = 0; k < len; k++) {
			if (aux[k] == '-') s += ' ';
			else s += tolower(aux[k]);
		}
		st.emplace(s);
	}

	printf("%ld\n", st.size());
}