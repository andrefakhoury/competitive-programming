#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 200010;

int a[MAXN];

int main() {
	int n; scanf("%d", &n);
	int maxi = -1;
	int mini = MAXN;
	multiset<int> s;

	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
		s.insert(a[i]);
	}

	int ans = MAXN;
	for (int i = 1; i <= n; i++) {
		auto it = s.find(a[i]);
		s.erase(it);

		int cur = (*s.rbegin()) - (*s.begin());

		ans = min(ans, cur);

		s.insert(a[i]);
	}

	printf("%d\n", ans);



}