#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 1000007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;

	ll x = 0, x2 = 0;
	const ll M = (1ll << 32), M2 = (1ll << 32) + 1;
	ll cur = 1, cur2 = 1;
	stack<ll> st, st2;
	st.push(1ll), st2.push(1ll);
	while(t--) {
		string s; cin >> s;

		if(s == "add") {
			x = (x + cur)%M;
			x2 = (x2 + cur2)%M2;
		} else if(s == "end") {
			st.pop();
			cur = st.top();
			st2.pop();
			cur2 = st2.top();
		} else {
			ll n; cin >> n;
			cur = (st.top() * n)%M;
			st.push(cur);
			cur2 = (st2.top() * n)%M2;
			st2.push(cur2);
		}
	}

	if(x != x2) cout << "OVERFLOW!!!" << endl;
	else cout << x << endl;
}