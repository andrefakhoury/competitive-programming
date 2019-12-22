#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int debug =  true;
int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	int caso = 0;
	while(t--)
	{
		caso++;
		cout << "Case #" << caso << ": ";
		int n,m;
		cin >> n >> m;
		string ori,crip,str;	
		cin >> ori;
		cin >> crip;
		cin >> str;	
		int posi = (int)ori[0] - (int)crip[0]; 
		if(posi < 0)
			posi+=26;
		if(false)
			cout << posi << endl;
		string resp;
		for(int i=0;i<str.size();i++)
		{
			int at = (int)str[i] + posi;
			if(char(at) > 'Z')
				at-=26;
			cout << (char)at;
		}
		cout << endl;
	}

	return 0;
}