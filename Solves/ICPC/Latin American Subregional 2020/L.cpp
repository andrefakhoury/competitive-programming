#include <bits/stdc++.h>

#define ff first
#define ss second

#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define clr(x, c) memset((x), (c), sizeof((x)))

using namespace std;

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl 


using ll = long long;
using ii = pair<int, int>;

int const inf = 0x3f3f3f3f;
ll const linf = 0x3f3f3f3f3f3f3f3f;

int const mod = 1e9 + 7;

seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(
    	chrono::high_resolution_clock::now().
    	time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) random_device{}(),
    (uint64_t) 17
};

mt19937 rd{seq};

int const maxl = 44;

string s[maxl];
bitset<maxl> b[maxl][maxl];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int l, c;
    cin >> l >> c;

    for (int i = 0; i < l; i++) cin >> s[i];

    int n;
    cin >> n;

    for (int at = 0; at< n; at++) {
        string x;
        cin >> x;
        sort(all(x));
        int t = size(x);

        for (int i = 0; i <= l-t; i++) {
            for (int j = 0; j <= c-t; j++) {
                string y;
                for (int k = 0; k < t; k++) {
                    y.pb(s[i+k][j+k]);
                }

                sort(all(y));

                if (y == x) {
                    for (int k = 0; k < t; k++) {
                        b[i+k][j+k][at] = true;
                    }
                }
            }
        }

        for (int i = 0; i < l; i++) {
            for (int j = 0; j <= c-t; j++) {
                string y;
                for (int k = 0; k < t; k++) {
                    y.pb(s[i][j+k]);
                }

                sort(all(y));

                if (y == x) {
                    for (int k = 0; k < t; k++) {
                        b[i][j+k][at] = true;
                    }
                }
            }
        }

        for (int i = 0; i <= l-t; i++) {
            for (int j = 0; j < c; j++) {
                string y;
                for (int k = 0; k < t; k++) {
                    y.pb(s[i+k][j]);
                }

                sort(all(y));

                if (y == x) {
                    for (int k = 0; k < t; k++) {
                        b[i+k][j][at] = true;
                    }
                }
            }
        }

        for (int i = 0; i <= l-t; i++) {
            for (int j = 0; j <= c-t; j++) {
                string y;
                for (int k = 0; k < t; k++) {
                    y.pb(s[i+t-k-1][j+k]);
                }

                sort(all(y));

                if (y == x) {
                    for (int k = 0; k < t; k++) {
                        b[i+t-k-1][j+k][at] = true;
                    }
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (b[i][j].count() > 1) ans++;
        }
    }

    cout << ans << '\n';
}
