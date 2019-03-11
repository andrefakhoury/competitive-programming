// https://open.kattis.com/problems/thief

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef pair<int, int> pii;

const int MAXN = 1e6 + 5;
const int MAXK = 1e5 + 5;

int val[MAXK];

int main() {
	int n, k; scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		val[x] = max(val[x], y);
	}

	sort(a.begin(), a.end());


}