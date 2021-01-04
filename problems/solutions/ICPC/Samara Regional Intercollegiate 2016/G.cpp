#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fastcin ios::sync_with_stdio(false); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

bool s2(int a, int b, int a2, int b2) {
    return (a >= a2 && b >= b2) ||
            (a >= b2 && b >= a2);
}

bool solve(int a, int b, int a1, int b1, int a2, int b2) {
    
    bool ret = false;

    if (a >= a1 && b >= b1) {
        ret |= s2(a - a1, b, a2, b2);
        ret |= s2(a, b - b1, a2, b2);
    }

    if (a >= b1 && b >= a1) {
        ret |= s2(a - b1, b, a2, b2);
        ret |= s2(a, b - a1, a2, b2);
    }

    return ret;
}

int main(){
    fastcin;

    int a, b; cin >> a >> b;

    int a1, b1; cin >> a1 >> b1;
    int a2, b2; cin >> a2 >> b2;

    bool ans = solve(a, b, a1, b1, a2, b2);

    cout << (ans ? "YES" : "NO") << endl;

    return 0;
}