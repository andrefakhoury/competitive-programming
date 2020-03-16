#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct waveletTree {
	int lo, hi;
	waveletTree *L, *R;
	vector<int> mapLeft, mapRight;
	vector<int> profit;

	/** Builds the wavelet tree, with elements on range [lo..hi] */
	waveletTree(pii *beg, pii *end) { // O(nlogA). obs: the input array is 0 based
		L = R = NULL;
		lo = min_element(beg, end)->fi;
		hi = max_element(beg, end)->fi;

		if (lo == hi) { // leaf node
			mapLeft.reserve(end - beg + 1);
			mapLeft.push_back(0);
			profit.reserve(end - beg + 1);
			profit.push_back(0);

			for (auto it = beg; it != end; it++) {
				profit.push_back(profit.back() + it->se);
				mapLeft.push_back(mapLeft.back() + 1);
			}
		} else {
			int mi = (lo + hi) / 2;
			auto f = [mi](pii const& x) { // lambda function to help index
				return x.fi <= mi;
			};

			mapLeft.reserve(end - beg + 1);
			mapRight.reserve(end - beg + 1);
			profit.reserve(end - beg + 1);

			mapLeft.push_back(0);
			mapRight.push_back(0);
			profit.push_back(0);

			for (auto it = beg; it != end; it++) {
				mapLeft.push_back(mapLeft.back() + f(*it));
				mapRight.push_back(mapRight.back() + !f(*it));
				profit.push_back(profit.back() + it->se);
			}

			auto pivot = stable_partition(beg, end, f); // split the vector
			if (pivot > beg) L = new waveletTree(beg, pivot);
			if (end > pivot) R = new waveletTree(pivot, end);
		}
	}

	/** Qtt of elements smaller than x in array[l..r] */
	int rangeCount(int x, int l, int r) {
		if (hi <= x) return profit[r] - profit[l-1];

		int mi = (lo + hi) / 2;
		int ret = 0;
		if (L && mapLeft[r] >= mapLeft[l-1]+1 && lo <= x) ret += L->rangeCount(x, mapLeft[l-1]+1, mapLeft[r]);
		if (R && mapRight[r] >= mapRight[l-1]+1 && mi+1 <= x) ret += R->rangeCount(x, mapRight[l-1]+1, mapRight[r]);
		return ret;
	}

	~waveletTree() {
		if (L) delete L;
		if (R) delete R;
	}
};

pii weapon[MAXN];
pii armor[MAXN];

struct Monster {
	int def, att, prof;

	inline bool operator<(Monster const& rhs) const {
		return tie(def, att, prof) < tie(rhs.def, rhs.att, rhs.prof);
	}
} monster[MAXN];

int n, m, p;
pii indexMonsters[MAXN];
pii compressedMonsters[MAXN];
int melhor_armor[MAXN], maxii;

inline bool find_index(int x, int& l, int& r) {
	l = 1;
	auto it = lower_bound(indexMonsters+1, indexMonsters+p+1, make_pair(x, -1)) - 1;
	r = it->se;
	return l <= r;
}

inline int next(int last, int j, int lo, int hi, waveletTree& T) {
	int lf = j+1, rt = maxii, mi;
	while(lf < rt) {
		mi = (lf + rt) / 2;
		int at = T.rangeCount(mi-1, lo, hi) - melhor_armor[mi];
		if (at == last) lf = mi + 1;
		else rt = mi-1;
	}
	return lf;
}

int main() {
	scanf("%d%d%d", &n, &m, &p);

	for (int i = 1; i <= n; i++) scanf("%d%d", &weapon[i].fi, &weapon[i].se);
	for (int i = 1; i <= m; i++) scanf("%d%d", &armor[i].fi, &armor[i].se);
	for (int i = 1; i <= p; i++) scanf("%d%d%d", &monster[i].def, &monster[i].att, &monster[i].prof);

	sort(weapon+1, weapon+n+1);
	sort(armor+1, armor+m+1);
	sort(monster+1, monster+p+1);

	memset(melhor_armor, -1, sizeof melhor_armor);

	melhor_armor[MAXN-1] = INF;
	for (int i = MAXN-2, j = m; i >= 1; i--) {
		if (melhor_armor[i] == -1) melhor_armor[i] = melhor_armor[i+1];
		if (j >= 1 && i == armor[j].fi) {
			melhor_armor[i] = min(melhor_armor[i], armor[j].se);
			i++, j--;
			continue;
		}
	}

	for (int i = 1; i <= p; i++) {
		indexMonsters[i] = mk(monster[i].def, i);
		compressedMonsters[i] = {monster[i].att, monster[i].prof};
	}

	maxii = armor[m].fi + 1;
	waveletTree T(compressedMonsters+1, compressedMonsters+p+1);

	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		int cur = -1e8;
		int lo, hi;

		if (find_index(weapon[i].fi, lo, hi)) {
			for (int j = 1, at; j <= maxii; j = next(at, j, lo, hi, T)) {
				at = T.rangeCount(j-1, lo, hi) - melhor_armor[j];
				cur = max(cur, at);
			}
		}

		ans = max(ans, cur - weapon[i].se);
	}

	printf("%d\n", ans);
	return 0;
}