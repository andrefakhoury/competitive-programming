#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int a[MAXN], n, freq[MAXN];
vector<pair<int, int> > p;
multiset<char> side[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
		freq[a[i]]++;
	}

	for (int i = 1; i <= 100; i++) {
		if (freq[i] == 0) continue;
		p.push_back(make_pair(freq[i], i));
	}

	sort(p.begin(), p.end());

	int A = 0, B = 0;
	for (int i = 0; i < p.size(); i++) {
		if (p[i].first == 1) {
			if (A <= B) {
				side[p[i].second].insert('A');
				A++;
			}
			else {
				side[p[i].second].insert('B');
				B++;
			}
		} else if (p[i].first == 2) {
			side[p[i].second].insert('A');
			side[p[i].second].insert('B');
			A++; B++;
		} else {
			bool ch_a = false;
			if (A < B) {
				p[i].first--;
				side[p[i].second].insert('A');
				A++;
				ch_a = true;
			} else if (B < A) {
				p[i].first--;
				side[p[i].second].insert('B');
				B++;
			}

			while(p[i].first-- > 0) {
				if (ch_a)
					side[p[i].second].insert('B');				
				else
					side[p[i].second].insert('A');
			}
		}
	}

	if (A != B) return !printf("NO\n");
	else printf("YES\n");

	for (int i = 1; i <= n; i++) {
		printf("%c", *(side[a[i]].begin()));
		side[a[i]].erase(side[a[i]].begin());
	} printf("\n");
}