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
const int MAXN = 2e5 + 5;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int n, a[MAXN];

bool check(int x) {
    if (x <= 0) return false;
    if (a[0] + a[1] <= x) return false;
    if (a[n-1] + a[n-2] <= x) return false;
    if (a[0] + x <= a[n-1]) return false;

    return true;
}

void print(int x) {
    cout << "YES\n" << x << endl;
    exit(0);
}

int main(){
    fastcin;    

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    int x = 1;
    
    x = a[0] + a[1] - 1;
    if (check(x)) print(x);
    
    x = a[n-1] - a[0] - 1;
    if (check(x)) print(x);

    x = a[n-1] - a[0] + 1;
    if (check(x)) print(x);

    x = rng() % a[n-1] + 1;
    if (check(x)) print(x);
    
    cout << "NO\n";
    return 0;
}