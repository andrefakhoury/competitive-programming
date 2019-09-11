/** Shoelace formula; get the area of a n-sided polygon */

const int MAXN = 100005;
double X[MAXN], Y[MAXN];

double polygonArea(int n) {
	double area = 0.0;
	
	int j = n-1;
	for (int i = 0; i < n; i++) {
		area += (X[j] + X[i]) * (Y[j] - Y[i]);
		j = i;
	}

	return abs(area/2.0);
}