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
 
int n, m;
vector<int> a, b;
 
set<vector<int> > st;
 
bool equal(vector<int> v1, vector<int> v2) {
    if (v1.size() != v2.size()) return false;
 
    for (int i = 0; i < (int)v1.size(); i++)
        if (v1[i] != v2[i]) return false;
 
    return true;
}
 
vector<int> rev(vector<int> v) {
 
    reverse(v.begin(), v.end());
    return v;
}
 
vector<int> dobra(vector<int> v, int i) {
    int l, r; l = i, r = i + 1;
    int nn = v.size();
 
    //cout << i << " - Era: ";
    //for (int j : v) cout << j << ' '; cout << endl;
 
    vector<int> aux;
    while (l >= 0 && r < nn) {
        aux.pb(v[l] + v[r]);
        l--, r++;
    }
 
    vector<int> ret;
 
    reverse(aux.begin(), aux.end());
 
    //cout << "Aux: ";
    //for (int bb : aux) cout << bb << ' '; cout << endl;
 
    if (l >= 0) {
        for (int j = 0; j <= l; j++) ret.push_back(v[j]);
        for (int j : aux) ret.pb(j);
    } else if (r < nn) {
        for (int j = nn-1; j >= r; j--) ret.push_back(v[j]);
        for (int j : aux) ret.pb(j);
    } else {
        ret = aux;
    }
 
    //cout << "Virou: ";
    //for (int j : ret) cout << j << ' '; cout << endl;
 
    return ret;
}
 
int cnt;
 
bool solve(vector<int> v, bool ok) {
    if (st.count(v)) return false;
    st.insert(v);
 
    //cnt++;
 
    //if (cnt == 15) exit(0);
 
    if (equal(v, b)) return true;
    if (v.size() < b.size()) return false;
 
    if (!ok && solve(rev(v), true)) return true;
    int nn = v.size();
 
    for (int i = 0; i < nn; i++) if (solve(dobra(v, i), false)) return true;
    return false;    
}
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    cin >> n; a.resize(n);
    for (int& i : a) cin >> i;
 
    cin >> m; b.resize(m);
    for (int& i : b) cin >> i;
 
    cout << (solve(a, false) ? 'S' : 'N') << endl;
 
 
   return 0;
}