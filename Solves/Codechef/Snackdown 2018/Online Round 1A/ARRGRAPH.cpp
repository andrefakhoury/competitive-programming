#include <bits/stdc++.h>
using namespace std;

bool prime[51];
typedef pair<int, int> pii;
int gcd[51][51];

void crivo(){
    for (int p=2; p*p<=50; p++)
    {
        if (prime[p] == true)
        {
            for (int i=p*2; i<=50; i += p)
                prime[i] = false;
        }
    }
}

void preg(){
    for(int i = 2; i<=50; i++){
        for(int j = 2; j<=50; j++){
            gcd[i][j] = __gcd(i, j);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    memset(prime, true, sizeof(prime));
    crivo();
    preg();
    vector<int> s;
    for(int i = 2; i<=47; i++) if(prime[i]) s.push_back(i);
    int t;  cin >> t;
    while(t--) {
        bool flag = true;
        int n;
        cin >> n;
        vector<pii> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first;
            v[i].second = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (gcd[v[i].first][v[j].first] == 1) {
                    v[i].second++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (v[i].second == 0) flag = false;
        }
        if (flag or n == 1) {
            cout << 0 << endl;
            for (auto i : v)
                cout << i.first << " \n"[i == v[n - 1]];
        } else {
            vector<pii> aux = v;
            int k;
            for(k = 0; k < v.size(); k++){
                if(v[k].second == 0) break;
            }
            for(int p = 0; p < s.size(); p++){
                for(int i = 0; i < aux.size(); i++) aux[i].second = 0;
                bool flag = true;
                int temp = aux[k].first;
                aux[k].first = s[p];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (i == j) continue;
                        if (gcd[aux[i].first][aux[j].first] == 1) {
                            aux[i].second++;
                        }
                    }
                }
                for(auto i : aux) if(i.second == 0) flag = false;
                if(flag){
                    cout << "1" << endl;
                    for(auto i : aux) cout << i.first << " ";
                    cout << endl;
                    break;
                } else {
                    aux[k].first = temp;
                }
            }
        }
    }
    return 0;
}