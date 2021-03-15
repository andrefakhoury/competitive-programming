#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
const int N = 307, inf = 0x3f3f3f3f;

int cnt[N];
int need[N][N];

ii LOG[1000007];
int p, r, t; 

int tempneed[N][N];
int tempcnt[N];
int vis[N]; // vis[x] = 1 se x ja foi recovered
int tot[N];
int temptot[N];

int deadlock(int pos) {
	memcpy(tempcnt, cnt, sizeof cnt);
	memcpy(tempneed, need, sizeof need);
	memcpy(temptot, tot, sizeof tot);

	memset(vis, 0, sizeof vis);

	auto recover = [&](int x) {
		vis[x] = 1; // recovered
		for(int i = 1; i <= r; ++i) {
			// volta tudo 
			tempcnt[i] += need[x][i] - tempneed[x][i];
		}
	};

	for(int i = 1; i <= pos; ++i) {
		int x, y; tie(x, y) = LOG[i];

		tempneed[x][y]--;
		tempcnt[y]--;
		temptot[x]--;
		if(temptot[x] == 0) {
			recover(x);
		}
	}

	auto is_dead = [&](int x) {
		for(int i = 1; i <= r; ++i) {
			if(tempneed[x][i] > tempcnt[i]) return true;
		}
		return false;
	};
	auto find_not_dead = [&]() {
		for(int i = 1; i <= p; ++i) {
			if(vis[i]) continue;
			if(!is_dead(i)) return i;
		}
		return -1;
	};

	int x;
	while((x = find_not_dead()) != -1) {
		// recover the resources
		recover(x);
	}

	int good = 1;
	for(int i = 1; i <= p; ++i) {
		good = good and vis[i];
	}

	return !good;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> p >> r >> t;

	for(int i = 1; i <= r; ++i) {
		cin >> cnt[i];
	}

	for(int i = 1; i <= p; i++) {
		tot[i] = 0;
		for(int j = 1; j <= r; ++j) {
			cin >> need[i][j];
			tot[i] += need[i][j];
		}
	}

	for(int i = 1; i <= t; ++i) {
		cin >> LOG[i].fi >> LOG[i].se;
	}

	int l = 0, r = t;
	int ans = -1;

	while(l <= r) {
		int mid = (l + r)/2;

		if(deadlock(mid)) {
			ans = mid;
			r = mid-1;
		} else {
			l = mid+1;
		}
	}

	cout << ans << endl;
}