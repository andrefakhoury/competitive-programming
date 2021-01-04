#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	int n, m, p;
	while(~scanf("%d%d%d", &n, &m, &p)) {
		vector<pii> points(p);
		for (auto& x : points) scanf("%d%d", &x.fi, &x.se);

		bool flag = true;
		for (int i = 0; flag && i < p; i++) {
			for (int j = i+1; flag && j < p; j++) {
				pii a = points[i], b = points[j];
				bool ok = false;

				ok |= a.fi == b.fi;
				ok |= a.se == b.se;
				for (int k = 0; !ok && k < p; k++) {
					if (k == i || k == j) continue;

					pii c = points[k];
					int X1 = max(a.fi, b.fi), X2 = min(a.fi, b.fi);
					int Y1 = max(a.se, b.se), Y2 = min(a.se, b.se);
					ok |= c.fi >= X2 && c.fi <= X1 && c.se >= Y2 && c.se <= Y1;
				}

				flag &= ok;
			}

		}

		printf("%c\n", flag ? 'Y' : 'N');
	}

	return 0;
}