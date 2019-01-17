#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;

struct point {
	double x, y;
};

point disks[MAXN];
int main() {
	int n, r; scanf("%d%d", &n, &r);

	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		disks[i].x = (double)x;
	}

	disks[1].y = (double)r;

	for (int i = 2; i <= n; i++) {
		double pos = (double)r;
		for (int j = 1; j < i; j++) {
			if (abs(disks[i].x - disks[j].x) <= 2*r) {
				double newpos = disks[j].y + sqrt(4*r*r - (disks[i].x-disks[j].x)*(disks[i].x-disks[j].x));
				// printf("%d e %d [(%lf, %lf) e (%lf,?)]: %lf\n", i, j, disks[j].x, disks[j].y, disks[i].x, newpos);
				pos = max(pos, newpos);
			}
		}
		disks[i].y = pos;
	}




	for (int i = 1; i <= n; i++) printf("%.9lf ", disks[i].y);
	return !printf("\n");
}