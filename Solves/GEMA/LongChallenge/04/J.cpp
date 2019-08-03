#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		int n; scanf("%d", &n);
		vector<int> a(n);
		for (int& i : a) scanf("%d", &i);

		vector<pair<int, int> > ind(n);
		for (int i = 0; i < n; i++) {
			ind[i].first = a[i];
			ind[i].second = i;
		}

		sort(ind.rbegin(), ind.rend());

		int ans = ind[0].first + ind[1].first;

		int qtt = 0, tot = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				qtt += a[i] + a[j] == ans;
				tot++;
			}
		}

		printf("%.7lf\n", qtt/(double)tot);
	}
}