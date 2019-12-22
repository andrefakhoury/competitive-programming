#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 200;

bool memo[200];
bool vis[15][900][15];

void pre() {
	int h = 0, m = 0;
	// memo[0] = true;

	for (int i = 1; i <= 720; i++) {
		m %= 60;
		h %= 60;

		int ang = 6 * min(60 - abs(h - m), abs(h - m));
		memo[ang] = true;

		if (i%12 == 0) h++;
		m++;

		m %= 60;
		h %= 60;

		ang = 6 * min(60 - abs(h - m), abs(h - m));
		memo[ang] = true;
	}
}


int main() {
	pre();
	int a;
	while(~scanf("%d", &a)) {
		printf("%c\n", memo[a] ? 'Y' : 'N');
	}
}