#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, n; cin >> s >> n;
    vector<pair<int, int> > vec;
    
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }
    
    sort(vec.begin(), vec.end());
    
    for (int i = 0; i < vec.size(); i++) {
        if (s <= vec[i].first) {
            cout << "NO\n";
            return 0;
        }
        s += vec[i].second;
    }
    
    cout << "YES\n";
    
    return 0;
    
}