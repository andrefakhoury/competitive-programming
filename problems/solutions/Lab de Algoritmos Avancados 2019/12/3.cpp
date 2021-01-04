#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
	int x, cs = 0;
	vector<int> vec;

	SCAN:
	while(scanf("%d", &x), x != -1) {
		if (x == -1) break;

		vec.push_back(x);
	}

	if (vec.size() == 0) return 0;

	vector<int> memo(32768, 0);

	for (int v : vec) {
		for (int k = v; k < (int)memo.size(); k++)
			memo[v] = max(memo[v], memo[k] + 1);
	}

	if (cs) printf("\n");
	printf("Test #%d:\n  maximum possible interceptions: %d\n", ++cs, *max_element(memo.begin(), memo.end()));

	vec.clear();
	goto SCAN;
}