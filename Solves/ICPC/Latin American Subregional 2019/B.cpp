#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;;
	cin >> n;
	vector<pair<int,int > > v;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		v.pb(make_pair(a,-i));
	}
	sort(v.rbegin(),v.rend());
	if(v[0].se == 0)
		cout << "S" << endl;
	else
		cout << "N" << endl;
	return 0;
}
