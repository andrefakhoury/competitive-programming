#include <bits/stdc++.h>
using namespace std;

float go(char c, char l){
    if((c == 'd' or c == 'f') and (l == 'd' or l == 'f')) return 0.4;
    if((c == 'j' or c == 'k') and (l == 'j' or l == 'k')) return 0.4;
    return 0.2;
}

int main() {
    int t;  cin >> t;
    while(t--){
        double ans = 0;
        int n;  cin >> n;
        map<string, double> m;
        while(n--){
            string st;
            cin >> st;
            if(m[st]==0.0){
                double worth = 0.2;
                for(int i = 1; i < st.size(); i++){
                    worth += go(st[i], st[i-1]);
                }
                m[st] = worth;
                ans+= worth;
            } else {
                ans+=m[st]/2.0;
            }
        }
        cout << ans*10 << endl;
    }
    return 0;
}