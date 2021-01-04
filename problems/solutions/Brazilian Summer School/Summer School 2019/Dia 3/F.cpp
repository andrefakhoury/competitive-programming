#include <bits/stdc++.h>
using namespace std;

struct team {
	int k, da, db, id;

	bool operator<(team t) const{
		return this->id < t.id;
	}
};

struct balloon {
	int a, b;
};

void tira(int& k, int& ori, int& d, long long& ans) {
	int qtt = min(k, ori);
	k -= qtt;
	ori -= qtt;

	ans += qtt * d;
}

int main() {
	int n, a, b;
	while (scanf("%d%d%d", &n, &a, &b), n and a and b) {
		vector<team> vec(n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d%d", &vec[i].k, &vec[i].da, &vec[i].db);
			vec[i].id = vec[i].k * (vec[i].da - vec[i].db);
		}

		sort(vec.begin(), vec.end());
		long long ans = 0;

		int i = 0;
		while (vec[i].id <= 0) {
			tira(vec[i].k, a, vec[i].da, ans);
			i++;
		}

		i = n-1;
		while (vec[i].id > 0) {
			tira(vec[i].k, b, vec[i].db, ans);
			i--;
		}

		for (i = 0; i < n; i++) {
			if (vec[i].k == 0) continue;

			if (a > 0) tira(vec[i].k, a, vec[i].da, ans);
			if (b > 0) tira(vec[i].k, b, vec[i].db, ans);
		}

		printf("%lld\n", ans);
		vec.clear();
	}

	return 0;
}