#include <stdio.h>
#include <vector>
#include <string>
#include <set>
#include <iostream>
using namespace std;

const int MAXN = 20;
int a[MAXN], t, n, qtt;

vector<int> cur;

set<string> used;

void solve(int i, int curSum) {
	if (curSum == t) {
		string curAns;
		for (int k = 0; k < (int)cur.size(); k++) {
			curAns += to_string(cur[k]);
			if (k != (int)cur.size()-1) curAns += "+";
		}
		
		if (used.find(curAns) == used.end()) {
			cout << curAns << "\n";
			used.insert(curAns);
		}

		return;
	}

	if (i > n) return;

	cur.push_back(a[i]);
	solve(i+1, curSum + a[i]);
	cur.pop_back();

	solve(i+1, curSum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (cin >> t >> n, t && n) {
		for (int i = 1; i <= n; i++) cin >> a[i];
		cout << "Sums of " << t << ":\n";

		solve(1, 0);

		if (used.size() == 0) cout << "NONE\n";
		used.clear();
	}
}