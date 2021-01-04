#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s; cin >> s;

    bool ok = false;
    for (char c : s) {
        if (c >= '0' && c <= '9') cout << c;
        else break;

        ok = true;
    }

    if (!ok) cout << -1 << endl;
    else cout << endl;   
    

    return 0;
}