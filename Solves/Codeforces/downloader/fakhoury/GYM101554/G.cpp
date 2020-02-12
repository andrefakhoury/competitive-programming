#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
     int k; cin >> k;
     string ini, fim; cin >> ini >> fim;
     while(k--) {
        for (char& c : ini) {
            c = c == '0' ? '1': '0';
        }
    }
     if (ini == fim) cout << "Deletion succeeded" << endl;
    else cout << "Deletion failed" << endl;
     return 0; 
}