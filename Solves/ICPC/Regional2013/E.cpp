#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG false
#define ll long long
typedef pair<int, int> pii;
 
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    int n, t; cin >> n >> t;
 
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = 1; i <= t; i++) {
        int x; cin >> x;
        st.erase(x);
    }
 
    if (st.size()) {
        for (int i : st) cout << i << ' ';
        cout << endl;
    } else cout << '*' << endl;
    
    return 0;
}