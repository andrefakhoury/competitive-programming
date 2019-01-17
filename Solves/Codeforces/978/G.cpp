#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int MAXN = 105;

struct exam {
	int s, d, c, i;
	exam();
	exam(int x, int y, int z, int w) {
		s = x, d = y, c = z, i = w;
	}

    bool operator < (const exam& a) const {
        return a.d > d;
    }
};

int ans[MAXN];
vector<exam> cal;

void impossible() {
	exit(!printf("-1\n"));
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	
	for (int i = 1; i <= m; i++) {
		int s, d, c; scanf("%d%d%d", &s, &d, &c);
		cal.push_back(exam(s, d, c, i));

		ans[d] = m + 1;
	}

	sort(cal.begin(), cal.end());

	for (auto ev : cal) {
		for (int i = ev.s; ev.c && i <= ev.d; i++) {
			if (i == ev.d || i < ev.s) impossible();
			if (ans[i]) continue;

			ans[i] = ev.i;
			ev.c--;
		}
	}

	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	return !printf("\n");
}