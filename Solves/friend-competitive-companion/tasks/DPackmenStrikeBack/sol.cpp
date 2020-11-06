#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define deb(x) (cerr << #x << ": " << x << '\n')

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e6 + 7;

char v[N];
int nxt[N];
bool ok[N];
vector<int> food, pack;
vector<ii> vec;
int acc[N], prox[N];
int n;

bool check(int d) {

	for(int i = 0; i < n; ++i) {
		ok[i] = false;
	}

	int ahead = n;
	ok[n] = true;
	prox[n] = n;

	queue<int> q;
	for(int i = n-1; i >= 0; --i) {
		while(q.size() and q.front() > i + d) q.pop();
		nxt[i] = min(n, i + d + 1);

		if(q.size()) nxt[i] = max(nxt[i], nxt[q.front()]);

		if(v[i] == 'P') {
			q.push(i);

		} else if(v[i] == '*') {

			int aux = acc[min(i + d, n-1)] - acc[i];
			if(aux == 0) {
				ok[i] = false;
			} else if(aux == 1) {
				ok[i] = ok[ahead];
			} else {
				ok[i] = ok[prox[nxt[i]]];
			}

			ahead = i;
		} else {

		}
		prox[i] = ahead;
	}

	int blz;
	int j = 0;
	while(v[j]== '.') j++;
	if(v[j] == 'P') {
		blz = ok[prox[nxt[j]]];
	} else {
		blz = ok[j];
	}
	return blz;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n;

	int acc_aux = 0;
	for(int i = 0; i < n; ++i) {
		cin >> v[i];

		if(v[i] == '*') {
			food.pb(i);
		} if(v[i] == 'P') {
			pack.pb(i);
			acc_aux ++;
		}

		acc[i] = acc_aux;

		if(v[i] != '.') vec.eb(v[i] == 'P', i);
	}

	if(food.size() == 0) {
		cout << 0 << " " << 0 << '\n';
		return 0;
	}
	if(pack.size() == 1) {
		int men = 0, mai = 0;
		for(int x : food) {
			if(x < pack[0]) men++;
			else mai++;
		}
		if(!men) cout << mai << " " << food.back() - pack[0] << '\n';
		else if(!mai) cout << men << " " << pack[0] - food[0] << '\n';
		else {
			int best_men = pack[0] - food[0];
			int best_mai = food.back() - pack[0];
			if(mai == men) cout << mai << " " << min(best_men, best_mai) << '\n';
			else if(men < mai) cout << men << " " << best_men << '\n';
			else cout << mai << " " << best_mai << '\n';
		}
		return 0;
	}

	// a partir daqui da pra pegar todos

	int ans = n;
	int l = 1, r = n;

	// food.pb(n);
	while(l <= r) {
		int mid = l + (r - l)/2;
		if(check(mid)) {
			ans = mid;
			r = mid-1;
		} else {
			l = mid+1;
		}
	}
	cout << food.size() << " " << ans << '\n';
}