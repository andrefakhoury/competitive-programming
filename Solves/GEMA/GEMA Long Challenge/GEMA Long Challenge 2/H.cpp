#include <bits/stdc++.h>
using namespace std;

const int MAXN = 302;

char gr[MAXN][MAXN];
int n, m, k;

struct point {
	int x, y;
	point() {}
	point(int a, int b) { x = a, y = b; }
};

struct constel {
	point center;
	int radius;

	constel() { }
	constel(point a, int x) {
		center = a;
		radius = x;
	}
};

bool cmp(constel a, constel b) {
	if (a.radius != b.radius) return a.radius < b.radius;
	if (a.center.x != b.center.x) return a.center.x < b.center.x;
	return a.center.y < b.center.y;
}

bool can(int i, int j, int r) {
	if (i+r > n || i-r < 1 || j+r > m || j-r < 1) return false;

	return gr[i][j+r] == '*' and gr[i][j-r] == '*' and
		   gr[i+r][j] == '*' and gr[i-r][j] == '*';
}

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf(" %c", &gr[i][j]);

	vector<constel> vec;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (gr[i][j] == '*') {
				for (int r = 1; r <= 300; r++) {
					if (can(i, j, r)) {
						vec.emplace_back(point(i, j), r);
					}
				}
			}
	}

	sort(vec.begin(), vec.end(), cmp);
	if (vec.size() < k) return !printf("-1\n");

	point cent = vec[k-1].center;
	int r = vec[k-1].radius;

	printf("%d %d\n", cent.x, cent.y);
	printf("%d %d\n", cent.x - r, cent.y);
	printf("%d %d\n", cent.x + r, cent.y);
	printf("%d %d\n", cent.x, cent.y - r);
	printf("%d %d\n", cent.x, cent.y + r);

	return 0;
}