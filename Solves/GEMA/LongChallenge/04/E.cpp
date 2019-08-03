#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int m, mLwr, mUpr;
bool fav[MAXN];

int best(vector<bool>& can, int zr) {
	int ret = 0;
	for (int i = 1; i <= m; i++) {
		if (can[i] == true && fav[i] && zr) {
			zr--;
			ret++;
		}
	}

	return ret;
}

int worst(vector<bool>& can, int zr) {
	int ini = zr, ret = 0;
	for (int i = 1; i <= m; i++) {
		if (can[i] == true && !fav[i] && zr) {
			zr--;
			ret++;
		}
	}

	return ini - ret;
}

struct Movie {
	int lwr, upr;
	vector<int> act;

	Movie() {
		lwr = upr = 0;

		scanf(" %*s");
		int k; scanf("%d", &k);
		act.resize(k);
		for (int& i : act) scanf("%d", &i);
		sort(act.begin(), act.end());

		vector<bool> can(m+1, true);

		int zr = 0;
		for (int ac : act) {
			if (ac == 0) zr++;
			else if (fav[ac]) lwr++, upr++;
			can[ac] = false;
		}

		upr += best(can, zr);
		lwr += worst(can, zr);

		mLwr = max(mLwr, lwr);
		mUpr = max(mUpr, upr);
	}
};

int main() {
	mLwr = mUpr = -1;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int k; scanf("%d%d", &m, &k);

	for (int i = 0; i < k; i++) {
		int x; scanf("%d", &x);
		fav[x] = true;
	}

	vector<Movie> movies;
	int n; scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		movies.push_back(Movie());
	}

	if (n == 1) return !printf("0\n");

	vector<int> ans(n);

	for (int i = 0; i < n; i++) {
		Movie m = movies[i];

		bool will = true;
		for (int j = 0; will && j < n; j++) {
			if (i == j) continue;
			if (movies[i].lwr < movies[j].upr) will = false;
		}

		if (will || m.lwr >= mUpr) ans[i] = 0;
		else if (m.upr >= mLwr) ans[i] = 2;
		else ans[i] = 1;
	}

	for (int i : ans) printf("%d\n", i);
	return 0;
}