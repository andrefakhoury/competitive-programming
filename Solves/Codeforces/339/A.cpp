#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    string a; cin >> a;
    vector<char> n;
    
    for (int i = 0; i < (int)a.size(); i+=2) n.push_back(a[i]);
    sort(n.begin(), n.end());
    
    for (int i = 0; i < (int)n.size()-1; i++) cout << n[i] << "+";
    cout << n.back() << endl;
    return 0;
}