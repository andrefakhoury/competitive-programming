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

const int MAXN = 2e5 + 5, LOG = 21;

int _log[MAXN], freq[MAXN];

int tb[MAXN][LOG];
inline int getmax(int i, int j) {
    return freq[i] == freq[j] ? (i < j ? i : j) : freq[i] > freq[j] ? i : j;
}

inline void build(int n) {
    for (int i = 0; i < n; i++) tb[i][0] = i;
    for (int j = 1; j < LOG; j++) {
        for (int i = 0; i < n; i++) {
            tb[i][j] = getmax(tb[i][j-1], tb[min(i + (1 << (j-1)), n-1)][j-1]);
        }
    }
}

inline int query(int l, int r) {
    if (l > r) swap(l, r);

    int lg = _log[r-l+1];
    return getmax(tb[l][lg], tb[r - (1 << lg) + 1][lg]);
}    

inline int get(string& s) {
    int n = s.size(), i, l, r;

    int ans = 0;
    for (i = 0; i < n; i++) {
        for(l = i, r = i; l >= 0 and r < n; l--, r++) {
            if(s[l] != s[r]) break;
            ans++;
        }
    }
    for (i = 0; i < n; i++) {
        for(l = i, r = i+1; l >= 0 and r < n; l--, r++) {
            if(s[l] != s[r]) break;
            ans++;
        }
    }
    return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

    _log[1] = 0;
    for (int i = 2; i < MAXN; i++)
        _log[i] = _log[i/2] + 1;

    int T; cin >> T;
    while(T--) {
        int n, q; cin >> n >> q;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            mp[s] = i;
            freq[i] = get(s);
        }

        build(n);

        while(q--) {
            string a, b; cin >> a >> b;
            cout << query(mp[a], mp[b]) + 1 << '\n';
        }
    }

	return 0;
}