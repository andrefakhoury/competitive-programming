#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mk make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;
const int M = 1000000007;

int v[MAXN];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;

    while(t--) {
        int n; cin >> n;

        multiset<int> st;
        for(int i = 0; i < n; ++i) {
            cin >> v[i];
            st.insert(v[i]);
        }

        for(int i = 0; i < n; ++i) {
            int x = v[i];
            int y = M - v[i];
            st.erase(st.find(v[i]));
            int a = *st.rbegin();
            int b = a;
            auto it = st.lower_bound(y);
            if(it != st.begin()) {
                it--;
                b = *it;
            }
            cout << max((a + x)%M, (b + x)%M) << ' ';
            st.insert(v[i]);
        }
        cout << '\n';
    }
    

	return 0;
}