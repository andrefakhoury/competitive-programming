#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
map<string,ll>tipo;
int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		tipo.clear();
		for(int i=0;i<n;i++)
		{
			string nom,q;
			cin >> nom >> q;
			tipo[q]++;
		}
		ll  resp =1LL;
		for(auto it : tipo)
		{
			pair<string,ll> at = it;
			at.se++;
			if(false)
				cout << " Q " << at.fi << " " << at.se << endl;
			resp*=at.se;
		}
		resp--;
		cout << resp << endl;
	}
	return 0;
}