#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 100000
#define MAXM 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> seq;
int pot[MAXN];

int main () {
	int n, x; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		seq.pb(x);
	}

	if (n == 0) return !printf("0\n");
	if (n == 1) return !printf("1\n");
}