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

int pi[MAXN];
string p, t;

void pre () {
	p += '#';

	pi[0] = pi[1] = 0;
	for (int i = 2; i <= (int)p.size(); i++) {
		pi[i] = pi[i-1];

		while (pi[i] > 0 and p[pi[i]] != p[i-1])
			pi[i] = pi[pi[i]];

		if (p[pi[i]] == p[i-1])
			pi[i]++;
	}
}

int KMP () {
	int k = 0;
	int m = p.size() - 1;
	int ret = 0;

	for (int i = 0; i < (int)t.size(); i++) {
		while (k > 0 and p[k] != t[i])
			k = pi[k];
		
		if (p[k] == t[i])
			k++;
		if (k == m)
			ret++;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int cs; cin >> cs;
	while(cs--) {
		cin >> p;
		pre();

		ll ans = 0;
		for (int i = 1; i <= 100; i++) {
			string cc = bitset<64>(i).to_string();

			string ss;
			for (int j = 0, ok = 0; j < cc.size(); j++) {
				if (cc[j] != '0') {
					ok = 1;
					ss += cc[j];
				} else if (ok) ss += cc[j];
			}

			if (ss.size() == i) {
				t = ss;
				ans += KMP();

				cout << i << ": " << KMP() << endl;
			} else if (ss.size() < i) {
				t.clear();
				t = string(i - ss.size(), '0');
				t += ss;
				// cout << t << endl;

				ans += KMP();
			}
		}

		cout << ans << '\n';
	}
	

	return 0;
}

