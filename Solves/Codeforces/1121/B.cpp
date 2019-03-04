#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1005;

int n, a[MAXN];
bool has[200005];

int qtt(int x) {
	int used = 0;
	for (int i = 1; i <= n; i++) {
		if (x - a[i] < 0) continue;
		used += has[x - a[i]];
	}

	return used/2;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	for (int i = 1; i <= n; i++) has[a[i]] = true;

	int ans = 0;
	for (int i = 0; i <= 200000; i++) ans = max(ans, qtt(i));

	printf("%d\n", ans);
}