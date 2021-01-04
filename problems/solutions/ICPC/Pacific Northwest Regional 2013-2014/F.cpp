#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int n;

    while(cin >> n, n != -1) {
        vector<int> div;

        ll sum = 0;
        for (int i = 1; i * i <= n; i++) {
            if (n%i == 0) {
                if (i < n) {
                    sum += i;
                    div.push_back(i);
                }

                if (i*i != n && n/i < n) {
                    sum += n/i;
                    div.push_back(n/i);
                }
            }
        }

        sort(div.begin(), div.end());

        if (sum == n) {
            cout << n << " = ";
            for (int i = 0; i < div.size(); i++) {
                cout << div[i] << " ";
                if (i != div.size() - 1) cout << "+ "; 
            }
            cout << "\n";
        } else {
            cout << n << " is NOT perfect.\n";
        }

    }

    

    return 0;
}