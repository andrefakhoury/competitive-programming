#include <bits/stdc++.h>
 #define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define mk make_pair
 using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 int main() {
    ios::sync_with_stdio(0); cin.tie(0);
     int n; cin >> n;
     stack<int> st;
    for (int i = 1; i <= 2*n; i++) {
        string x; cin >> x;
        int u; cin >> u;
         if (st.size() && x == "in") {
            printf("%d %d\n", st.top(), u);
            st.push(u);
        } else if (x == "in") {
            st.push(u);
        } else {
            st.pop();
        }
    }
}