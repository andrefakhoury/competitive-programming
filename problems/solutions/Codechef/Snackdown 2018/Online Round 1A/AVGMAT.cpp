#include <bits/stdc++.h>
using namespace std;

//x = (a, b)
//y = (c, d)

//|a-c| + |b-d|

#define eb emplace_back
const int MAXN = 305;

int mat[MAXN][MAXN];

struct point {
	int x, y;

	point() {}
	point(int a, int b) {
		x = a;
		y = b;
	}
};

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		unordered_map<int, int> dist;
		vector<point> houses;

		int n, m; scanf("%d%d ", &n, &m);
		char c;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				scanf("%c ", &c);
				mat[i][j] = c-'0';
				if (mat[i][j]) {
					houses.eb(point(i, j));
				}
			}

		for (int i = 0; i < houses.size(); i++) {
			for (int j = i+1; j < houses.size(); j++) {
				int x = abs(houses[i].x - houses[j].x) + abs(houses[i].y - houses[j].y);
				dist[x]++;
			}
		}

		for (int i = 1; i <= m+n-2; i++)
			printf("%d ", dist[i]);
		printf("\n");

	}

	return 0;
}