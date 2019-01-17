#include <bits/stdc++.h>
using namespace std;

#define max(a, b) (a > b ? a : b)

int main() {
	int n, l, x; cin >> n >> l;
	vector<int> s;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		s.push_back(x);
	}

	sort(s.begin(), s.end());
	s.erase( unique( s.begin(), s.end() ), s.end() );

	double ans = s[0];
	for (int i = 1; i < s.size(); i++)
		ans = max(ans, (s[i] - s[i-1])/2.0);
	ans = max(ans, l - s.back());

	cout << fixed << setprecision(10) <<  ans << endl;

	return 0;
}