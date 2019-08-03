    #include <bits/stdc++.h>
    #define int long long
    #define For(i,a,b) for (int i = a; i <= (b); i++)
    #define For2(i,a,b) for (int i = a; i >= (b); i--)
    #define Test(x) cout << #x << ": " << x << endl;
    using namespace std;
    vector<int> a;
    signed main() {
        int t,n;
        cin >> t;
        while (t--) {
            cin >> n;
            a.resize(n);
            For(i,0,n - 1) cin >> a[i];
            sort(a.begin(),a.end());
            int maxf = 0;
            int cnt = 0;
            For(i,0,n - 1) {
                if (a[i] >= 2) cnt++;
            }
            if (cnt < 2) cout << 0 << endl;
            else cout << min(n - 2,min(a[n - 1],a[n - 2]) - 1) << endl;
        }
    }