#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 200010
#define MAXM 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int m;
vector<int> v;

int solve(int l, int r) {
	vector<int> aux;
	for (int i = l; i <= r; i++)
		aux.pb(v[i]);
	sort(aux.begin(), aux.end());

	if (aux[(aux.size()-1)/2] == m) return 1;
	return 0;
}

int main () {
	int n, x; scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		v.pb(x);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (j+1 < n && (j-i)%2 == 1) {
				ans += solve(i, j)*2; j++;
			}
			else ans += solve(i, j);
		}
	}
	printf("%d\n", ans);
}