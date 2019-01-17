#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define pb push_back


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int x = 0;
    int y = 0;
    if(n==1){
        cout << -1;
        return 0;
    }
    int p[n];
    for(int i = 0; i<n; i++) cin >> p[i];

    if(n==2 and p[0]==p[1]){
        cout << -1;
        return 0;
    }

    for ( int i = 0; i < n; ++i ) {
        x+=p[i];
        for ( int j = i+1; j < n; ++j ) {
            y+=p[j];
        }
        if(x!=y){
            cout << i+1 << endl;
            for ( int w = 1; w <= i + 1; ++w ) {
                cout << w << " ";
            }
            return 0;
        }
        y = 0;
    }
    return 0;
}