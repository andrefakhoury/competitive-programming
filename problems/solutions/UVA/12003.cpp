#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 3e5 + 5, BKSZ = 516;

vector<ll> cnt[MAXN];
ll a[MAXN];
int n;

inline int get(int i) {
	return (i-1)/BKSZ;
}

inline void update(int b) {
	cnt[b].clear();

	cnt[b].eb(0);

	for (int i = b*BKSZ+1; i <= n && get(i) == b; i++) cnt[b].eb(a[i]);
	sort(cnt[b].begin(), cnt[b].end());
}

inline int count(int b, ll v) {
	auto it = lower_bound(cnt[b].begin(), cnt[b].end(), v) - 1;
	return it - cnt[b].begin();
}

inline int count(int l, int r, ll v) {
	int bl = get(l), br = get(r), ans = 0;
	for (int i = bl+1; i < br; i++) ans += count(i, v);
	for (int i = l; i <= r && get(i) == bl; i++) ans += a[i] < v;
	if (bl != br) for (int i = br*BKSZ+1; i <= r; i++) ans += a[i] < v;
	return ans;
}

int main() {
	int  m; scanf("%d%d", &n, &m);
	ll u; scanf("%lld", &u);

	for (int i = 1; i <= n; i++) scanf("%lld", a+i);
	for (int b = 0; b <= get(n); b++) update(b);

	for (int q = 1; q <= m; q++) {
		int l, r, p; scanf("%d%d", &l, &r);
		ll v; scanf("%lld%d", &v, &p);
		
		a[p] = u * count(l, r, v) / (r - l + 1);
		update(get(p));
	}

	for (int i = 1; i <= n; i++) printf("%lld\n", a[i]);
	return 0;
}