#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define PI acos(-1.0)
#define INF 0x3f3f3f3f
#define fastcin ios::sync_with_stdio(false);
#define endl "\n"

#define MAXN 1000000000000000000

typedef long long ll;
typedef pair<int, int> pii;

map<ll, int> likes;
set<ll> hates;

int main () {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	ll t, s, qtl = 0; ll xx, ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> t >> s;
		if (t == 1) { //likes
			while(s--) { cin >> xx;
				likes[xx]++;
			} qtl++;
		} else { //hates
			while(s--) { cin >> xx;
				likes[xx] = -n;
				hates.insert(xx);
			}
		}
	}

	for (map<ll, int>::iterator it = likes.begin(); it != likes.end(); it++)
		if (it->second == qtl) ans++;

	if (!qtl) cout << MAXN-(int)hates.size() << endl;
	else cout << ans << endl;

	return 0;
}