#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mk make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

int t, n;
string s;
long long int freq[28];

long long int f[21];

long long int fat(long long int x){
    if(f[x] != 0) return f[x];

    if(x == 0) return f[x] = 1;

    return f[x] = x * fat(x-1);
}

int main() {
	//ios::sync_with_stdio(false); cin.tie(NULL);

    cin  >> t;

    for(int i=0; i<t; i++){
        memset(freq, 0, sizeof(freq));
        cin >> n;
        cin >> s;

        for(int j=0; j<n; j++){
            freq[s[j]-'a']++;
        }

        int par = 0, imp = 0;
        int k = -1;

        for(int j=0; j<27; j++){
            if(freq[j]%2 == 0) par++;
            if(freq[j]%2 == 1){
                imp++;
                k = j;
            }
        }

        if((n%2 == 1 && imp != 1) || imp > 1){
            cout << "0\n";
        }else if(n%2 == 0 && imp == 0){
            long long int resp = fat(n/2);
            for(int j=0; j<27; j++){
                resp = resp/fat((freq[j])/2LL);
            }
    
            cout << resp << "\n";
        }else if(n%2 == 1 && imp == 1){
            freq[k]--;
            long long int resp = fat(n/2);
            for(int j=0; j<27; j++){
                resp = resp/fat((freq[j])/2LL);
            }
            cout << resp << "\n";
        }else{
            cout << "0\n";
        }
    }

	return 0;
}