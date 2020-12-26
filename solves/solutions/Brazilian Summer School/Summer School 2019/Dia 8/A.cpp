#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

struct STT {
	int l, r, k, id;

	STT() {}
	STT(int a, int b, int c, int d) : l(a), r(b), k(c), id(d) {}

	bool operator<(STT const& rhs) const {
		return r == rhs.r ? id < rhs.id : r < rhs.r;
	}
};

void no() {
	printf("NO\n");
	exit(0);
}

bool cmp(STT const& lhs, STT const& rhs) {
	return lhs.l == rhs.l ? lhs.k > rhs.k : lhs.l < rhs.l;
}

int main() {
	vector<STT> a;

	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		STT ac; scanf("%d%d", &ac.l, &ac.r);
		ac.k = -1;
		ac.id = i;
		a.push_back(ac);
	}

	int m; scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		STT ac; scanf("%d%d%d", &ac.l, &ac.r, &ac.k);
		ac.id = i;
		a.push_back(ac);
	}

	sort(a.begin(), a.end(), cmp);
	vector<int> ans(n);

	set<STT> actors;
	for (STT x : a) {
		if (x.k > 0) actors.emplace(x);
		else {
			auto it = actors.lower_bound(STT(-1, x.r, -1, -1));
			if (it == actors.end()) no();

			STT ac = *it;
			actors.erase(it);

			ans[x.id] = ac.id;	
			ac.k--;
			if (ac.k >= 1) actors.emplace(ac);
		}
	}

	printf("YES\n");
	for (int i : ans) printf("%d ", i+1);
	printf("\n");

	return 0;
}