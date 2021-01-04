#include <bits/stdc++.h>

#define ff first
#define ss second

#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define clr(x, c) memset((x), (c), sizeof((x)))

using namespace std;

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl 


using ll = long long;
using ii = pair<int, int>;

int const inf = 0x3f3f3f3f;
ll const linf = 0x3f3f3f3f3f3f3f3f;

int const mod = 1e9 + 7;

seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(
    	chrono::high_resolution_clock::now().
    	time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) random_device{}(),
    (uint64_t) 17
};

mt19937 rd{seq};

int const maxn = 1010101;

double e[maxn], acc[maxn];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++) {

        int gap = b-a+1;
        if (a == 0) gap--;

        int l = i-b, r = min(i-a, i-1);

        if (r < 0) {
            e[i] = 1;
        }
        else {
            double s = 0;
            if (l <= 0) {
                s += -l +1;
                l = 1;
            }
            s += acc[r] - acc[l-1] + (r-l+1);

            if (a == 0) s++;
            e[i] = s / gap;
        }
        
        acc[i] = e[i] + acc[i-1];
    }

    cout << setprecision(5) << fixed << e[n] << '\n';
}
