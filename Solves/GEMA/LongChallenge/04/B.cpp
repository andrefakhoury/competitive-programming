#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN], neg[MAXN], pos[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	ifstream in;
	in.open("input.txt", ios::in);

	ofstream out;
	out.open("output.txt", ios::out);

	int n; in >> n;

	int zr = 0;
	for (int i = 1; i <= n; i++) {
		in >> a[i];
		neg[i] = neg[i-1] + (a[i] < 0);
		pos[i] = pos[i-1] + (a[i] > 0);
		zr += a[i] == 0;
	}
 	
 	int ans = INT_MAX;
	for (int i = 1; i < n; i++) {
		int cur = pos[i] + neg[n] - neg[i];
		ans = min(ans, cur);
	}

	out << ans + zr << endl;
	return 0;
}