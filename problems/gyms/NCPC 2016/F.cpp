#include <bits/stdc++.h>

#define ff first
#define ss second

#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define clr(x, c) memset((x), (c), sizeof((x)))

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int const inf = 0x3f3f3f3f;
ll const linf = 0x3f3f3f3f3f3f3f3f;

int const mod = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    double n, p;
    cin >> n >> p;


    double c = p / (n+1);
    double ans = c;

    for (double x = 2; x <= 3e6; x++) {
        c *= x;
        c /= x-1;

        c *= n-p+x;
        c /= n+x;

        ans = max(ans, c);
    }

    cout << setprecision(9) << ans << '\n';
}
