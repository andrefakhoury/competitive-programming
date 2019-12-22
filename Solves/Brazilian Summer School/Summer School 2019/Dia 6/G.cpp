#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int lcm(int a, int b) {
	return a / __gcd(a, b) * b;
}

int main() {
	int n, k; scanf("%d%d", &n, &k);

	int l = 1;
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		int g = __gcd(x, k);
		l = lcm(l, g);
	}

	printf("%s\n", l == k ? "Yes" : "No");
}