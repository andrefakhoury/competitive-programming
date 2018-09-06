#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(0); cin.tie(NULL);
#define PI acos(-1.0)
#define inf 0x3f3f3f3f3f
#define infl (1LL << 48)

#define MAXN 500

typedef long long ll;
typedef pair<int, int> pii;

int fw[MAXN][MAXN];

void init(int n) {
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				fw[i][j] = min(fw[i][j], fw[i][k]+fw[k][j]);
}

int main () {
	ios::sync_with_stdio(0); cin.tie(NULL);
	int n, m, k; cin >> n >> m >> k;	




	return 0;
}