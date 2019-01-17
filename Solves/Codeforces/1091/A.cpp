#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;

int main() {
	//ios::sync_with_stdio(false);
	int y, b, r; scanf("%d%d%d", &y, &b, &r);

	int sum = 0;
	for (int i = 1; i <= y; i++) {
		if (i+1 <= b && i+2 <= r) {
			sum = i + i + 1 + i + 2;
		}
	}

	printf("%d\n", sum);
	return 0;
}