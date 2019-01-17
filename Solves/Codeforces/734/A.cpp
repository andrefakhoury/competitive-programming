#include <bits/stdc++.h>
using namespace std;

#define DEBGG(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(false);
#define vszz(v) ((int)v.size())
#define xx first
#define yy second

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
#define MAXN 10000

typedef long long ll;
typedef pair<int, int> pii;

int main () {
	char v[100005]; int n; scanf("%d", &n);
	scanf(" %s", v+1);
	int a = 0, d = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] == "A") a++;
		if (v[i] == "D") d++;
	}

	if (a > d) printf("Anton\n");
	else if (d > a) printf("Danik\n");
	else printf("Friendship\n");
	return 0;
}