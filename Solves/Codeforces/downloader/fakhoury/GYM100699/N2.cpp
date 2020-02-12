#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef pair<int, int> pii;
typedef long long ll;
 const int MAXN = 1e5 + 5;
 int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
        int n; cin >> n;
     for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) cout << " ";
        cout << '/';
        for (int j = 0; j < 2 * i; j++) cout << " ";
        cout << "\\\n";
    }
     return 0;
}