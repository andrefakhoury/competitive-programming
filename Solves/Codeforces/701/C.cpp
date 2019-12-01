#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

char s[MAXN];

vector<int> all[256];

int main() {
	int n; scanf("%d", &n);
	scanf(" %s", s + 1);

	vector<int> td;
	for (int i = 1; i <= n; i++) {
		all[s[i]].eb(i);
		td.eb(s[i]);
	}

	sort(td.begin(), td.end());
	td.erase(unique(td.begin(), td.end()), td.end());

	int ans = n;
	for (int i = 1; i <= n; i++) {
		int j = 0, ok = 1;
		for (int& x : td) {
			auto it = lower_bound(all[x].begin(), all[x].end(), i);
			if (it == all[x].end()) {
				ok = 0;
				break;
			} else {
				j = max(j, *it);
			}
		}
		
		if (ok) ans = min(ans, j - i + 1);
	}

	printf("%d\n", ans);


	return 0;	
}
