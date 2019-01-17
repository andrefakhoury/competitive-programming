#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(0); cin.tie(NULL);
#define PI acos(-1.0)
#define INF 0x3f3f3f3f3f
#define INFL 100000000000000000000LL
#define endl "\n"

#define MAXN 200010
#define MAXM 100005

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	int n; scanf("%d", &n);
	int a = n%10;
	if (a < 5) return !printf("%d\n", n-a);
	else return !printf("%d\n", n+10-a);
}