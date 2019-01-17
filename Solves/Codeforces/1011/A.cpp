#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(0); cin.tie(NULL);
#define PI acos(-1.0)
#define inf 0x3f3f3f3f3f

#define MAXN 100000
#define MAXM 100000

typedef long long ll;
typedef pair<int, int> pii;

int n, k; 
string s;

ll solve(int atual, int anterior, int soma, int qt) {
	if (qt == k) return soma;
	if (atual >= n) return inf;

	if (s[atual] > s[anterior]+1)
		return min(solve(atual+1, anterior, soma, qt), solve(atual+1, atual, soma+s[atual]-"a"+1, qt+1));

	return solve(atual+1, anterior, soma, qt);
}

int main () {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> k;
	cin >> s;
	sort(s.begin(), s.end());

	ll ans = inf;
	for (int i = 0; i < n; i++) {
		ans = min(ans, solve(i+1, i, s[i]-"a"+1, 1));
	}
	if (ans == inf) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}