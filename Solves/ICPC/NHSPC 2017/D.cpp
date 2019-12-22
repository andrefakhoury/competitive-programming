#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        memset(a, 0, sizeof a);

        int n; cin >> n;
        long long sum = 0;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            
            sum ^= a[i];
        }

        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += (sum ^ a[i]) < a[i];
        }

        cout << "Case " << cs << ": " << ans << '\n';
    }
}