#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define MAX 1003
typedef long long ll;
typedef pair<int, int> pii;

// const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    long double v[MAX],f[MAX],c[MAX];
    while(t--)
    {
        int n,resp=0;
        long double d;
        
        cin >> n >> d;
        
        for(int i=0;i<n;i++)
        {
            cin >> v[i] >> f[i] >> c[i];
        }
        for(int i=0;i<n;i++)
        {
            long double tempo = f[i]/c[i];
            if(tempo * v[i] >= d)
                resp++;
        }
        cout << resp << "\n";
    }
    

    return 0;
}