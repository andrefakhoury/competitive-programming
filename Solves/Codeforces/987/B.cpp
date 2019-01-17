#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define debugg(a) cout << ">>" << (#a) << " : " << (a) << endl;

using namespace std;

int gem[6];

int main() {
	double x, y;
	scanf("%lf %lf", &x, &y);
	char ans;
	if (y*log(x) > x*log(y)) ans = ">";
	else if (x*log(y) > y*log(x)) ans = "<";
	else ans = "=";

	printf("%c\n", ans);
	return 0;
}