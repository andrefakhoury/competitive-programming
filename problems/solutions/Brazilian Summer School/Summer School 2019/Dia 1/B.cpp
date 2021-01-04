#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 100005;

int n;
set<int> point;

int main() {
	scanf("%d", &n);

	int sum = 0;
	point.insert(0);

	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		sum += x;
		point.insert(sum);
	}


	int ans = 0;
	for(set<int>::iterator it = point.begin(); it != point.end(); it++) {
		if(point.find((*it + sum/2) % sum) != point.end()) {
			ans++;
			point.erase(it);
			point.erase((*it + sum/2) % sum);
		}
	}

	printf("%c\n", ans >= 2 and sum%2 == 0 ? 'Y' : 'N');
	return 0;
}