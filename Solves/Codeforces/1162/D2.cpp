#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 5;

struct HASH{
  size_t operator()(const pair<int,int>&x)const{
    return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
  }
};

pair<int, int> edge[MAXN];
unordered_set<pii, HASH> st;

void impossible() {
	cout << "No\n";
	exit(0);
}

void possible() {
	cout << "Yes\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, m; cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		u--, v--;

		edge[i] = {min(u, v), max(u, v)};
		st.insert(edge[i]);
	}

	for (int k = 1; k < n; k++) {
		if (n%k) continue;

		bool flag = true;
		for (int i = 1; i <= m; i++) {
			int u = edge[i].first, v = edge[i].second;
			if (!st.count({(u+k)%n, (v+k)%n}) && !st.count({(v+k)%n, (u+k)%n})) {
				flag = false;
				break;
			}
		}

		if (flag) possible();
	}

	impossible();
}