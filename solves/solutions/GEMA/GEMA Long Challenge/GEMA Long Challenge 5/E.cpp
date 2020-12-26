#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

bool is[MAXN];
int a[MAXN], memo[MAXN];
int acc[MAXN], maxi[MAXN];

struct ST {
	vector<int> seg;

	ST() {
		seg.resize(4 * MAXN);
		fill(seg.begin(), seg.end(), 0);
	}
 
	void update(int pos, int val){
		for(; pos < MAXN; pos += (-pos) & pos) {
			seg[pos] = max(seg[pos],val);
		}
	}

	int query(int pos){
		int ans = 0;
		
		for(; pos; pos -= (-pos) & pos){
			ans = max(ans,seg[pos]);
		}

		return ans;
	}
};

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	
	ST seg;
	int lis = 0;
	for (int i = 1; i <= n; i++) {
		memo[i] = seg.query(a[i] - 1) + 1;
		seg.update(a[i], memo[i]);
		lis = max(lis, memo[i]);
	}

	for (int i = n; i >= 1; i--) {
		if (memo[i] == lis) {
			maxi[memo[i]] = max(maxi[memo[i]], a[i]);
			acc[memo[i]]++;
			is[i] = true;
		} else if (maxi[memo[i] + 1] > a[i]) {
			maxi[memo[i]] = max(maxi[memo[i]], a[i]);
			acc[memo[i]]++;
			is[i] = true;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (is[i] && acc[memo[i]] == 1) printf("3");
		else if (is[i]) printf("2");
		else printf("1");
	}

	printf("\n");
}