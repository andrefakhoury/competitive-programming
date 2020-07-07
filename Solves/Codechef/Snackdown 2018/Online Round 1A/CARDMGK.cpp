#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int t;  cin >> t;
    while(t--){
        int ans = 1;
        int n;  cin >> n;
        vector<int> inp(n);
        vector<int> aux;
        for(int i = 0; i< n; i++){
            cin >> inp[i];
        }
        aux = inp;
        sort(aux.begin(), aux.end());
        if(aux == inp){
            cout << "YES" << endl;
            continue;
        }
        int i = 0;
        for(i = 0; i < n-1; i++){
            if(inp[i] <= inp[i+1]) continue;
            else break;
        }
        for(int j = i+1; j < inp.size() - 1; j++){
            if(inp[j] <= inp[j+1]) continue;
            else ans = 0;
        }
        if(ans and inp[0] >= inp[n-1]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}