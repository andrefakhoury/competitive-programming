#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
    #define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
#else
    #define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class num> inline void rd(num &x) {
    char c; while(isspace(c = getchar()));
    bool neg = false;
    if(!isdigit(c)) neg = (c == '-'), x = 0;
    else x = c - '0';
    while(isdigit(c = getchar()))
    x = (x << 3) + (x << 1) + c - '0';
    if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

inline ll read() {
    ll x, y;
    scanf("%lld.%lld", &x, &y);
    return x * 100 + y;
}

inline __int128 f(__int128 x, __int128 T) {
    return (x * (10000 + T) + 5000) / 10000;
}

inline __int128 get_left(ll T, ll a, bool lft) {
    __int128 lo = 0, hi = LLONG_MAX, mi;
    hi *= 100000;

    while(lo < hi) {
        mi = (lo + hi + 1) / 2;
        if (f(mi, T) <= a) lo = mi;
        else hi = mi-1;
    }

    __int128 val = f(lo, T);
    if (val != a) {
        if (lft) {
            if (val < a) lo++;
        } else if (val > a) lo--;
    }

    return lo;
}

inline void print(__int128 x) {
    string s="";
    if (x == 0) s = "0";
    while(x > 0) {
        s += x%10 + '0';
        x /= 10;
    }
    reverse(s.begin(), s.end());
    printf("%s\n", s.c_str());
}

inline void _solve_() {
    ll a, b, T;
    a = read();
    b = read();
    T = read();

    __int128 L = get_left(T, a, true);
    __int128 R = get_left(T, b, false);

    __int128 dif = 0;
    if (L > R) {
        dif += f(L, T) - a;
        dif += b - f(R, T);
    } else {
        dif += (b - a + 1) - (R - L + 1);   
    }

    if (dif < 0) dif = 0;
    if (dif > b - a + 1) dif = b - a + 1;
    print(dif);
}

int main() {
    int __T__; rd(__T__);
    while(__T__--) _solve_();
    return 0;
}