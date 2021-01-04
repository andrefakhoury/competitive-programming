#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define se second
#define fi first

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e6 + 5;

bool isComp[MAXN];
vector<int> primes;

void sieve() {
    for (int i = 2; i < MAXN; i++) {
        if (isComp[i]) continue;
        primes.pb(i);
        for (int j = 2 * i; j < MAXN; j += i) isComp[j] = true;
    }
}

int count(int x) {

    int ans = 0;

    while (x >= 4) {
    
        for (int p : primes) {
            int q = x - p;
            if (!isComp[q]) {
                ans++;
                x = q - p;
                break;
            }
        }

    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    sieve();

    int x; cin >> x;
    cout << count(x) << endl;
    
    return 0;
}