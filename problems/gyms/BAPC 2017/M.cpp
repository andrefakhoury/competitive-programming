#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define y1 jfkdlsjfdkl

const int N = 100007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int seg[N + N];

int query(int l, int r) {
	int ans = -1;
	for(l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if(l&1) ans = max(ans, seg[l++]);
		if(r&1) ans = max(ans, seg[--r]);
	}
	return ans;
}

void update(int p, int val) {
	p += N;
	for(seg[p] = max(seg[p], val); p > 1; p >>= 1) {
		seg[p >> 1] = max(seg[p], seg[p^1]);
	}
}

int main() {
	memset(seg, -1, sizeof seg);
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    int x0, y0, x1, y1;

    vector<int> Y;
    cin >> x0 >> y0 >> x1 >> y1;

    vector<ii> vec;

    int flagx = 0, flagy = 0;
    x1 -= x0;
    y1 -= y0;

    if(flagx) x1 = -x1;
    if(flagy) y1 = -y1;
    

    if(x1 < 0) flagx = 1, x1 = -x1;
    if(y1 < 0) flagy = 1, y1 = -y1;

    vec.eb(x1, y1);
    Y.pb(y1);

	for(int i = 1; i <= n; i++) {
    	int x, y; cin >> x >> y;
    	x -= x0;
    	y -= y0;
    	if(flagx) x = -x;
    	if(flagy) y = -y;

    	if(x <= x1 and y <= y1 and x >= 0 and y >= 0) {
    		vec.eb(x, y);
	    	Y.pb(y);
    	}
    }

    Y.pb(0);
    sort(vec.begin(), vec.end());
    sort(Y.begin(), Y.end());
    Y.erase(unique(Y.begin(), Y.end()), Y.end());

    update(0, 0);
    for(int i = 0; i < vec.size(); i++) {
    	int x, y;
    	tie(x, y) = vec[i];

    	int p = lower_bound(Y.begin(), Y.end(), y) - Y.begin();

    	int res = query(0, p + 1);
    	if(res != -1) update(p, res + 1);
    	if(i + 1 == vec.size()) {
    		cout << res << '\n';
    	}
    }
}