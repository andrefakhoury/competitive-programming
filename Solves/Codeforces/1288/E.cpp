#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 3e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[MAXN];
int p[MAXN]; // p[i] = where is i
int r[MAXN]; // r[i] = who's at i

pii ans[MAXN];

struct wvt {
	int lo, hi;
	wvt *L, *R;
	vector<int> ml, mr;

	wvt(int* from, int* to, int lo, int hi) {
		int mi = (lo + hi) / 2;
		ml.reserve(to-from+1);
		mr.reserve(ro-from+1);

		if (lo == hi) {
			
		}

		for (int i = 0; i < )
	}


};

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) scanf("%d", a+i);

	int l = 1;
	for (int i = 1; i <= m; i++) {
		if (a[i] == a[i-1]) continue;
		else a[l++] = a[i];
	}
	m = l - 1;

	for (int i = 1; i <= m; i++) {

	}

	for (int i = 1; i <= m; i++) printf("%d ", a[i]);
	printf("\n");

	for (int i = 1; i <= n; i++) printf("%d %d\n", ans[i].fi, ans[i].se);
	return 0;
}