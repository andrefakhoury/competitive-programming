#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main () {
	int n; scanf("%d", &n);
	vector<pii> ev(n);

	set<int> numbers;
	for (int i = 0; i < n; i++) {
		int l, r; scanf("%d%d", &l, &r);
		numbers.insert(l);
		numbers.insert(r);
		ev[i] = {l, r};
	}

	map<int, int> mp;

	int cnt = 1;
	for (int i : numbers) mp[i] = cnt++;

	for (int i = 0; i < n; i++) {
		ev[i].first = mp[ev[i].first];
		ev[i].second = mp[ev[i].second];
	}

	sort(ev.begin(), ev.end());

	int ans = 0, maximo = -1;
	for (int t = 1, i = 0; t <= cnt; t++) {
		int curMax = -1;
		
		while (i < n && ev[i].first == t) {
			if (ev[i].second < maximo) ans++;
			curMax = max(curMax, ev[i].second);
			i++;
		}

		maximo = max(maximo, curMax);
	}

	printf("%d\n", ans);
}