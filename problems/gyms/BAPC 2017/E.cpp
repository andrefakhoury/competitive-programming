#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 257, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

vector<int> e[N];

int vis[N], match[N], umatch[N];

int x[2][N], y[2][N];

double dist(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int dfs(int u) {
	if(vis[u]) return 0;
	vis[u] = 1;
	for(int v : e[u]) {
		if(match[v] == -1 or dfs(match[v])) {
			match[v] = u;
			umatch[u] = v;
			return 1;
		}
	}
	return 0;
}

int mis(int n, int m) {
	memset(match, -1, sizeof match);
	memset(umatch, -1, sizeof umatch);
	memset(vis, 0, sizeof vis);

	int f = 0;
	int ok = 1;
	while(ok) {
		ok = 0;
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < n; i++) {
			if(umatch[i] == -1 and dfs(i)) {
				f++;
				ok = 1;
			}
		}
	}

	return m + n - f;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, b, r; cin >> n >> b >> r;

    for(int i = 0; i < b; i++) {
    	cin >> x[0][i] >> y[0][i];
    }

    for(int i = 0; i < r; i++) {
    	cin >> x[1][i] >> y[1][i];
    }

    double lo = 0, hi = 100000;
    int cnt = 60;
    double ans;
    while(cnt--) {
    	double mid = lo + (hi - lo)/2;
    	for(int i = 0; i < b; i++) {
    		e[i].clear();
    		for(int j = 0; j < r; j++) {
    			if(dist(x[0][i], y[0][i], x[1][j], y[1][j]) <= mid) {
    				e[i].pb(j);
    			}
    		}
    	}

    	if(mis(b, r) >= n) {
    		ans = mid;
    		lo = mid;
    	} else {
    		hi = mid;
    	}
    }

    cout << fixed << setprecision(10) << ans << endl;
}