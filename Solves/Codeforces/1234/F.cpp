#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;
const int N = 21;

inline bool find(int mask, int i) {
	return mask & (1 << i);
}

inline int insert(int mask, int i) {
	return mask | (1 << i);
}

bool all[1 << N];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string s; cin >> s;
	int n = s.size();

	vector<int> vec;
	for (int i = 0; i < n; i++) {
		int curMask = 0;
		for (int j = 0; i + j < n && j < 20; j++) {
			if (find(curMask, s[i+j]-'a')) break;
			curMask = insert(curMask, s[i+j]-'a');
			all[curMask] = true;
			vec.pb(curMask);
		}
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	int ans = 1;
	for (int s1 : vec) {
		int s2 = s1 ^ ((1 << N) - 1);

		for (int i = s2; i > 0; i = (i - 1) & s2)
			ans = max(ans, all[i] * __builtin_popcount(s1^i));
	}

	printf("%d\n", ans);
	return 0;
}