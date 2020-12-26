#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    cin >> s;

    ll cnt = 0;
    for (int i = (int)s.size()-1; i >= 0; i--) {
        if (s[i] == '.') cnt = (int)s.size()-1-i;
    }

    ll d = 1;
    while (cnt--) d *= 10ll;

    ll n = 0;
    for (char a : s) if (a != '.') n = n*10ll + (a-'0');

    bool ok = false;
    ll k = 1, cor = 1;
    for (ll i = 1; i < 100'000'000; i++) {
        if (i >= k*10ll) k *= 10, cor = 1;
        else if (i >= k*(cor+1)) cor++;

        if (i*n == d*((i-k*cor)*10ll + cor)) {
            ok = true;
            cout << i << "\n";
        }
    }

    if (!ok) cout << "No solution\n";
}