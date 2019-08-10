#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	priority_queue<pii> pq;
	for (int i = 0; i < n; i++) {
		pq.push(mp(a[i], i));
	}

	int i, j; i = j = pq.top().second;
	pq.pop();

	while(pq.size()) {
		int u = pq.top().second; pq.pop();

		if (abs(i - u) != 1 && abs(j - u) != 1) {
			cout << "NO" << endl;
			return 0;
		} else {
			i = min(i, u);
			j = max(j, u);
		}
	}

	cout << "YES\n";
	return 0;
}