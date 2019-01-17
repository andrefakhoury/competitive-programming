#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100005, INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int w, h; cin >> w >> h;
	int u[2], d[2]; cin >> u[0] >> d[0];
	cin >> u[1] >> d[1];

	while(h) {
		w += h;

		if (h == d[0]) w = max(0, w - u[0]);
		if (h == d[1]) w = max(0, w - u[1]);

		h--;
	}

	cout << w << endl;
	return 0;
}