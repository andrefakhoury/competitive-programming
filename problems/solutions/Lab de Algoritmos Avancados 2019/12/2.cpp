#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
using namespace std;

typedef long long ll;
const int MAXN = 2e4 + 5;

struct State {
	int i, j;
	ll v;

	State() {}
	State(int a, int b, ll c) {
		i = a, j = b, v = c;
	}

	void clear(int n) {
		i = 1e8, j = n, v = 0;
	}

	bool operator>(State st) {
		int len1 = j - i + 1;
		int len2 = st.j - st.i + 1;

		if (len1 < 0) return false;
		if (len2 < 0) return true;

		if (v == st.v) {
			if (len1 == len2) {
				return i < st.i;
			}

			return len1 > len2;
		}

		return v > st.v;
	}

	bool has() {
		return j - i + 1 > 0;
	}
};

int main() {
	int t; scanf("%d", &t);
	for (int cs = 1; cs <= t; cs++) {
		int n; scanf("%d", &n);
		vector<int> a(n-1);
		for (int& i : a) scanf("%d", &i);

		State cur, ans;
		cur.clear(n); ans.clear(n);

		for (int k = 0; k < n-1; k++) {
			int v = a[k];

			if (cur.v + v >= 0) {
				cur.v += v;
				cur.i = min(cur.i, k + 1);

				if (cur > ans) {
					ans = cur;
					ans.j = k + 2;
				}
			} else {
				if (cur > ans) {
					ans = cur;
					ans.j = k + 1;
				}
				
				cur.clear(n);
			}
		}

		if (cur > ans) {
			ans = cur;
			ans.j = n;
		}

		if (ans.has()) {
			printf("The nicest part of route %d is between stops %d and %d\n", cs, ans.i, ans.j);
		} else {
			printf("Route %d has no nice parts\n", cs);
		}
	}
}
