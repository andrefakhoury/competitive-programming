#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	//ios::sync_with_stdio(false); cin.tie(NULL);
	int t; scanf("%d", &t);
	int l, r;
	while(t--) {
		scanf("%d%d", &l, &r);

		for (int k = 2; k <= r; k++) {
			if (l*k <= r) {
				printf("%d %d\n", l, l*k);
				break;
			}
		}
	}

	return 0;
}