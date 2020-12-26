#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 5001;

ll sum[MAXN];

bool check(int num) {
	char s[10]; sprintf(s, "%d", num);
	int len = strlen(s);
	sort(s, s + len);
	for (int i = 1; i < len; i++) {
		if (s[i] == s[i-1]) return false;
	}
	return true;
}

void pre() {
	for (int i = 1; i < MAXN; i++) {
		sum[i] = sum[i-1] + check(i);
	}
}

int main() {
	pre();

	int n, m;
	while(~scanf("%d %d", &n, &m)) {
		printf("%lld\n", sum[m] - sum[n-1]);
	}

}