/*
	Problem: Nice subsets from Codechef (INSQ15_C)

	Print the number of subsets of size at most K whose
	Niceness value is in the range [A, B].
*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;


void solve(int i, int n, int cur_qtt, int cur_val, int max_qtt, int max_val, vector<int>& nice, map<int, int>& freq) {
	if (cur_qtt > max_qtt || cur_val > max_val) return;
	if (i == n) {
		freq[cur_val]++;
		return;
	}

	solve(i+1, n, cur_qtt, cur_val, max_qtt, max_val, nice, freq);
	solve(i+1, n, cur_qtt + 1, cur_val + nice[i], max_qtt, max_val, nice, freq);
}

int main() {
	int n, k, a, b; scanf("%d%d%d%d", &n, &k, &a, &b);
	vector<int> p(n), nice(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);

		nice[i] = 1;
		for (int j = 2; j <= p[i]; j++) {
			if (p[i]%j == 0) nice[i] *= j;
			while(p[i]%j == 0) p[i] /= j;
		}
	}

	map<int, int> freq;
	vector<pii> X, Y_lower, Y_upper;

	solve(0, n/2, 0, 0, k, b, nice, freq);
	for (auto x : freq)
		X.push_back(make_pair(x.first, x.second));

	freq.clear();
	solve(n/2, n, 0, 0, k, b, nice, freq);
	for (auto y : freq)
		Y_upper.push_back(make_pair(y.first, y.second));
	
	sort(Y_upper.begin(), Y_upper.end());
	
	Y_lower = Y_upper;
	reverse(Y_lower.begin(), Y_lower.end());

	vector<int> maximum_upper(Y_upper.size());
	vector<int> maximum_lower(Y_lower.size());

	maximum_upper[0] = Y_upper[0].second;
	for (int i = 1; i < (int)Y_upper.size(); i++)
		maximum_upper[i] += Y_upper[i].second; //max(maximum_upper[i-1], Y_upper[i].second);

	maximum_lower[0] = Y_lower[0].second;
	for (int i = 1; i < (int)Y_lower.size(); i++)
		maximum_lower[i] += Y_lower[i].second; //max(maximum_lower[i-1], Y_lower[i].second);

	int ans = 0;
	for (auto x : X) {
		int ind_upper = lower_bound(Y_upper.begin(), Y_upper.end(), make_pair(b - x.first + 1, 0)) - Y_upper.begin() - 1;
		int ind_lower = lower_bound(Y_lower.begin(), Y_lower.end(), make_pair(x.first - a + 1, 0)) - Y_lower.begin() - 1;

		int op_upper = 0, op_lower = 0;

		if (ind_upper > -1) op_upper = maximum_upper[ind_upper];
		if (ind_lower > -1) op_lower = maximum_lower[ind_lower];
		ans += x.second + x.second * max(op_upper, op_lower);
	}

	printf("%d\n", max(ans - 1, 0));
	return 0;
}