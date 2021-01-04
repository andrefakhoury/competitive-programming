#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fastcin ios::sync_with_stdio(false); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int main(){
    fastcin;    
    int n;  cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        if(x == i+1) s.insert(x);
    }
    int ans = (s.size()&1 ? s.size()/2 + 1 : s.size()/2);
    
    cout << ans << endl;
    while(s.size() > 1){
        cout << *s.begin() << " ";
        s.erase(s.begin());
        cout << *s.begin() << endl;
        s.erase(s.begin());
    }
    if(s.size() == 1) cout << *s.begin() << " " << (*s.begin() != 1 ? 1 : 2);
    return 0;
}