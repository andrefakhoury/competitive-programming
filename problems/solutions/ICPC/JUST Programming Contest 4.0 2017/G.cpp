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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;
        vector<int> vec;
        for(int i = 0; i < n; ++i) {
            int x; cin >> x;
            vec.pb(x);
        }

        vector<int> pre(n, 0), suf(n, 0x3f3f3f3f);

        pre[0] = vec[0];
        for(int i = 1; i < n; ++i) {
            pre[i] = max(vec[i], pre[i-1]);
        }

        suf[n-1] = vec[n-1];

        for(int i = n-2; i >= 0; --i) {
            suf[i] = min(suf[i+1], vec[i]);
        }

        int ans = 0;
        for(int i = 1; i + 1 < n; ++i) {
            int flag = 1;
            if(i) {
                flag = flag and pre[i-1] <= vec[i];
            }

            if(i + 1 < n) {
                flag = flag and suf[i+1] >= vec[i];
            }
            ans += flag;
        }

        cout << ans << '\n';
    }
    

	return 0;
}