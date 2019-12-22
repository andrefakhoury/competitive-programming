#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define ll long long 
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;		
	vector<long long > v;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		v.pb(a);
	}
	sort(v.rbegin(),v.rend());
	long long  longe = 0;
	for(int i=0;i<n;i++)
	{
		int at =i+1;
		longe = max(longe,at + v[i] +1 );
	}
	cout << longe << endl;
	return 0;
}