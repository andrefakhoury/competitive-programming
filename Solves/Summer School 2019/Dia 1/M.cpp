#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 100005;

int n;
vector<int> cards;

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);
	scanf("%d", &n);
	cards.resize(n);

	for (int i = 0; i < n; i++) scanf("%d", &cards[i]);

	int ans = 1;
	for (int i = 0; i < n-1; i++) {
		if (cards[i] < cards[i+1]) ans++;
	}

	printf("%d\n", ans);
	return 0;
}