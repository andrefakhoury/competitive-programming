#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a/gcd(a, b)*b;
}

struct Fraq {
    ll p, q;

    Fraq& normalize() {
        ll g = gcd(abs(p), abs(q));
        p /= g, q /= g;
        return *this;
    }

    Fraq(string const& s) {
        p = 1, q = 1;
        if (s[0] == '-') p *= -1;

        int i;
        ll x = 0;
        for (i = 1; i < (int)s.size() and s[i] != '/'; i++) x = x*10 + s[i] - '0';
        p *= x;

        if (i == (int)s.size()) return;

        x = 0;
        for (i++; i < (int)s.size() and s[i] <= '9' and s[i] >= '0'; i++) x = x*10 + s[i] - '0';
        q *= x;

        normalize();
    }

    Fraq(ll a, ll b) : p(a), q(b) {};

    Fraq& operator+=(Fraq const& rhs) {
        ll g = gcd(q, rhs.q);
        p = rhs.q/g*p + q/g*rhs.p;
        q = q/g*rhs.q;
        
        normalize();

        return *this;
    }
};

vector<Fraq> eval(string const& s) {
    vector<Fraq> ans;

    for (int i = 0; i < (int)s.size(); i++) {
        string x;
        x.push_back(s[i]);

        i++;
        while (i < (int)s.size() and s[i] != '-' and s[i] != '+') {
            x.push_back(s[i]);
            i++;
        }
        i--;

        ans.emplace_back(x);
    }

    return ans;
}

void run(string const& ts) {
    string s;
    stack<int> st;
    int sig1 = 1, sig2 = 1;

    for (int i = 0; i < (int)ts.size(); i++) {
        char c = ts[i];

        if (c == ')') {
            sig1 = st.top();
            st.pop();
            sig2 = 1;
        }
        else if (c == '(') {
            st.push(sig1);
            sig1 *= sig2;
            sig2 = 1;
        }
        else if (c == '-') {
            sig2 = -1;
        }
        else if (c == '+') {
            sig2 = 1;
        }
        else {
            if (sig1*sig2 == 1) s.push_back('+');
            else s.push_back('-');
            
            while (i < (int)ts.size() and (ts[i] == '/' or isdigit(ts[i]))) {
                s.push_back(ts[i]);
                i++;
            }

            i--;
        }
    }
    
    auto v = eval(s);

    vector<ll> fq(21);

    for (auto x : v) {
        fq[x.q] += x.p;
        // cout << x.p << "/" << x.q << "\n";
    }

    Fraq ans(0, 1);
    for (int i = 1; i <= 20; i++)
        ans += Fraq(fq[i], i);

    cout << ans.p << "/" << ans.q << "\n";
} 

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    string s;

    while (cin >> s) run(s);
    
    return 0;
}