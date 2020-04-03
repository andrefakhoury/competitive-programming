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

char aux[300];
int main() {
	string oth = "AEIOUY";
	string vog = oth;
	for (char& c : oth) c = (c - 'A' - 1 + 26) % 26 + 'A';

	scanf(" %s", aux);

	int n = strlen(aux);

	vog += oth;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (char c : vog) {
			if (aux[i] == c) {
				printf("%c\n", aux[i]);
			}
		}
	}
	printf("%d\n", sum);
}