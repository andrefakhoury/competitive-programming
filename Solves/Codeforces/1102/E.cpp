#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005, INF = 0x3f3f3f3f, MOD = 998244353;
typedef long long ll;

struct SegT {
	vector<int> seg;
	int n;

	SegT () {}
	SegT (int n) {
		this->n = n;
		seg.resize(4*n + 1);
	}

	void point_update(int pos, int value, int n) {
		pos += n;
		seg[pos] = value;

		while (pos > 1) {
			pos >>= 1;

			seg[pos] = min(seg[2 * pos],
			seg[2 * pos + 1]);
		}
	} 

	int range_query(int left, int right, int n) {
		left += n;
		right += n;

		int mi = INF;

		while (left < right) {
			if (left & 1) { 
				mi = min(mi, seg[left]);
				left++; 
			}

			if (right & 1) {
				right--;

				mi = min(mi, seg[right]);
			}
			left /= 2;
			right /= 2;
		}
		return mi;
	}

	void update(int i, int val) {
		return point_update(i, val, n);
	}

	int query(int l, int r) {
		return range_query(l, r, n);
	}

};

int main() {
	int n; scanf("%d", &n);
	SegT seg(n);
	vector<int> a(n);

	map<int, set<int> > mp;
	map<int, bool> used;

	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) mp[a[i]].insert(i);

	for (int i = 0; i < n; i++) seg.update(i, INF);

	int pot = -1;
	for (int i = 0; i < n; i++) {
		if (seg.query(i, n) != 0) pot++;
		
		if (used[a[i]]) continue;
		for (int k : mp[a[i]]) seg.update(k, 0);
		used[a[i]] = true;
	}

	int ans = 1;
	for (int i = 0; i < pot; i++) ans = (ans * 2)%MOD;
	printf("%d\n", ans);
}