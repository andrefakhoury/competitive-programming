#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5 + 5;

int tin[MAXN], tout[MAXN];
int times[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	priority_queue<int> pq;

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int x, y; cin >> x >> y;

		tin[x]++;
		pq.push(-(y - 1));
	}

	int ans = -1, cur = -1, qtt = 0;
	for (int i = 0; i < MAXN; i++) {
		if (pq.empty()) break;

		if (cur != -1) cur++;
		if (tin[i]) {
			cur = 1;
			qtt += tin[i];
		}

		while (pq.size() && -pq.top() == i) {
			ans = max(ans, cur);
			pq.pop();
			qtt--;
		}
		
		if (qtt) ans = max(ans, cur);
	}

	cout << ans << endl;
}