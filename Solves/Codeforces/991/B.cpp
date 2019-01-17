#include <bits/stdc++.h>
using namespace std;
#define pb push_back

vector<int> g;

int avg(){
    float r = 0;
    for(auto i : g) r+=i;
    r/=g.size();
    if(r-floor(r)<0.5) return (int)floor(r);
    else return (int)floor(r+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ans = 0;

    int n;
    cin >> n;
    while(n--){
        int x;
        cin >> x;
        g.pb(x);
    }

    while(avg()<5){
        sort(g.begin(), g.end());
        g[0] = 5;
        ans++;
    }
    cout << ans;
    return 0;
}