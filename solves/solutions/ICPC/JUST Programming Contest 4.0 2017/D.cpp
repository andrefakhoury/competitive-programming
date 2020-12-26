#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mk make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

vector<int> sum[26];
int n, q;

int get(int i, int c) {
    if (i < 0) return 0;
    return i/n * sum[c][n-1] + sum[c][i%n];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

    int T; cin >> T;
    while(T--) {
        cin >> n >> q;
        string s; cin >> s;

        for (int i = 0; i < 26; i++) sum[i].resize(n);

        for (int i = 0; i < n; i++) {
            for (int c = 0; c < 26; c++) {
                if (i == 0) sum[c][i] = (s[i] - 'a') == c;
                else sum[c][i] = sum[c][i-1] + ((s[i] - 'a') == c);
            }
        }

        while(q--) {
            int l, r; cin >> l >> r;
            char c; cin >> c;

            l--, r--;
            int ans = get(r, c-'a') - get(l-1, c-'a');
            cout << ans << '\n';
        }

        
    }

    

	return 0;
}