#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair

typedef pair<int, int> pii;
typedef long long ll;

int const inf = 0x3f3f3f3f;

[[ gnu::target("abm,bmi") ]]
int popcount(int x) {
	return __builtin_popcount(x);
}

struct State {
	string s;
	int cnt;

	bool operator<(State const& rhs) const {
		return s < rhs.s;
	}

	bool operator==(State const& rhs) const {
		return s == rhs.s;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);	
	
	int n;
	cin >> n;

	vector<string> s(n);
	vector<vector<State>> v(n);

	for (auto& x : s) cin >> x;	

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < (1<<s[i].size()); j++) {
			string ans;
			for (int k = 0; k < (int)s[i].size(); k++) {
				if (j&(1<<k)) ans.push_back(s[i][k]);
			}
			// cout << i << " " << ans << " " << ans.size() << "\n";
			v[i].push_back(State{ans, (int)ans.size()});
		}
	}

	for (auto& x : v) {
		sort(x.begin(), x.end());
		x.erase(unique(x.begin(), x.end()), x.end());
	}

	for (int j = (int)v[n-1].size() - 2; j >= 0; j--) {
		v[n-1][j].cnt = max(v[n-1][j].cnt, v[n-1][j+1].cnt);
	}

	for (int i = n-2; i >= 0; i--) {
		for (State& st : v[i]) {
			int best = -inf;
			auto it = upper_bound(v[i+1].begin(), v[i+1].end(), st);

			if (it != v[i+1].end()) {
				if (it->cnt != -inf) { 
					best = st.cnt + it->cnt;
				}
			}

			st.cnt = best;
		}

		for (int j = (int)v[i].size() - 2; j >= 0; j--) {
			v[i][j].cnt = max(v[i][j].cnt, v[i][j+1].cnt);
		}
	}

	int ans = v[0][0].cnt;

	ans = max(ans, -1);
	cout << ans << "\n";

	return 0;
}