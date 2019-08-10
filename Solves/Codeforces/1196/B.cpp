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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		int n, k; cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int qt = 0;
        ll cur = 0;
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            cur += a[i];

            if (cur%2) {
                cur = 0;
                qt++;
                pos.pb(i + 1);
            }
        }

        if (pos.size()) pos[pos.size() - 1] = n;

        if (qt != 0 && qt >= k && k%2 == qt%2) {
            cout << "YES\n";

            for (int i = qt - k; i < pos.size(); i++) {
                cout << pos[i] << ' ';
            } cout << "\n";            
        } else {
            cout << "NO\n";
        }
	}
	
	return 0;
}