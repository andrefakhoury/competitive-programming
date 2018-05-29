#include <bits/stdc++.h>

using namespace std;

struct coords{
	long long int x, y;
};

int main(void) {
	int R, N;
	double dist, maxDist;
	cin >> R >> N;
	maxDist = R;
	
	coords cord[N+4];
	
	for (int i = 0; i < N; i++) {
		cin >> cord[i].x >> cord[i].y;
		
		dist = R - (sqrt(cord[i].x*cord[i].x + cord[i].y*cord[i].y));
		if (dist < maxDist) {
			maxDist = dist;
		}
	}
	
	printf("%.9lf\n", maxDist);
	
	return 0;
	
}