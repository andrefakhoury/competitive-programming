#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define DEBUG 1

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 5e5 + 5, INF = 0x3f3f3f3f;

map<int, int> mp;
multiset<ll> st;
map<int, int> freq;
int n;

int query(int id) {
    // cout << "Yo quiero lo " << id << " que vale " << mp[id] << endl;
    // for (int x : st) cout << x << ' '; cout << endl;

    int cur = mp[id];
    map<int, int> fin;

    ll sum = 0;
    int ans = 0;

    while (true) {
        auto it = st.lower_bound(sum);
        if (it == st.end()) break;

        if (fin[*it] >= freq[*it]) {
            // cout << *it << ": " << fin[*it] << " vs " << freq[*it] << endl;
            it = st.lower_bound((*it) + 1);
            if (it == st.end()) break;
        }

        if (fin[cur] >= 1 || (sum + (*it) <= cur)) {
            sum += (*it);
            // cout << " +a " << (*it) << endl;
            fin[*it]++;
        } else  {
            sum += cur;
            // cout << " +b " << cur << endl;
            fin[cur]++;
        }

        ans++;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        mp[i] = x;
        st.insert(x);
        freq[x]++;
    }

    while(q--) {
        char op; cin >> op;
        if (op == '?') {
            int x; cin >> x;
            cout << query(x) << '\n';
        } else if (op == '-') {
            int x; cin >> x;
            auto it = st.find(mp[x]);
            freq[mp[x]]--;
            st.erase(it);
        } else if (op == '+') {
            int x, id; cin >> x >> id;
            mp[id] = x;
            freq[x]++;
            st.insert(x);
        }
    }

    

    return 0;
}