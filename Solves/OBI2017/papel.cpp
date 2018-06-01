#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005
#define pb push_back

vector<int> ret;
map<int, int> m;

int main() {
	int N, x;
	scanf("%d", &N);

	ret.pb(0);
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		if (x != ret.back()) ret.pb(x);
	}
	ret.pb(0);

	for (int i = 1; i < ret.size()-1; i++) {
		
	}

	int ans = 2;



	printf("%d\n", ans);
}