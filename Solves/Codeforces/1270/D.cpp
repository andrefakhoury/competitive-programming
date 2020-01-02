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
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, k;
pii ask(vector<int> xx) {
	cout << "?";
	for (int x : xx) cout << ' ' << x;
	cout << endl; cout.flush();
	
	int a1; cin >> a1;
	if (a1 == -1) exit(0);

	int a2; cin >> a2;
	return {a1, a2};
}

pii ask(int i, int j) {
	i = (i-1)%n + 1;
	j = (j-1)%n + 1;

	vector<int> xx;
	while(i != j) {
		xx.eb(i);
		i = i%n + 1;

		if (i == j) {
			xx.eb(i);
			i = i%n + 1;
			break;
		}
	}

	return ask(xx);
}

pii ask(set<int> st) {
	vector<int> xx;

	int cnt = 0;
	for (int x : st) {
		if (cnt == k) break;

		xx.eb(x);
		cnt++;
	}

	return ask(xx);
}

void answer(int m) {
	cout << "! " << m << endl;
	exit(0);
}

int getAns(set<int> got, vector<int> a) {
	pii x = ask(got);
	sort(a.begin(), a.end());
	return lower_bound(a.begin(), a.end(), x.se) - a.begin() + 1;
}

int main() {
	cin >> n >> k;

	int m = 0;
	if (n >= 2*k) {
		set<int> st;

		set<int> got;
		vector<int> a;

		for (int i = 1; i <= n; i++) st.emplace(i);
		for (int i = 1; i <= k; i++) {
			pii cur = ask(st);
			got.emplace(cur.fi);
			a.eb(cur.se);
			st.erase(cur.fi);
		}

		m = getAns(got, a);
	} else {
		vector<int> a;
		set<int> st, foi;
		int ff = 1;

		vector<int> val(n+1);
		vector<int> cnt(n+1);

		for (int i = 1; i <= n; i++) st.emplace(i);

		for (int i = 1; i <= n && (int)foi.size() < k; i++) {
			pii cur = ask(i, i+k-1);
			val[cur.fi] = cur.se;

			if (foi.count(cur.fi)) cnt[cur.fi]++;
			else {
				st.erase(cur.fi);
				foi.emplace(cur.fi);
				cnt[cur.fi]++;
				a.eb(cur.se);
			}

			if (cnt[cur.fi] > cnt[ff]) ff = cur.fi;
		}

		if ((int)foi.size() == k) m = getAns(foi, a);
		else {
			sort(a.begin(), a.end());
			m = lower_bound(a.begin(), a.end(), val[ff]) - a.begin() + 1;
			if (m > k/2) m = min(k, m+1);
			else m = max(1, m-1);
		}
	}

	answer(m);


	return 0;
}