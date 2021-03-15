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

int const mod = 360;


int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n1, n2;
    cin >> n1 >> n2;

    if ((mod + n1 - n2) % mod < (mod - n1 + n2) % mod){
        cout << -(mod + n1 - n2) % mod <<'\n';
    }
    else cout <<  (mod - n1 + n2) % mod << '\n';
}
