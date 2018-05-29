#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back

#define inf 0x3f3f3f3f
#define MAXN 1000000000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n;
int fat = 1;
vector<string> pal;
map<string, int> rep;

long double fatorial(int n) {
	long double fat = 1;
	for (int i = 2; i <= n; i++) {
		fat *= i;
	}
	return fat;
}


int main () {
    ios::sync_with_stdio(false);

    string s;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
		cin >> s;
		pal.pb(s);
		rep[s]++;
	}
	
	sort( pal.begin(), pal.end() );
	pal.erase( unique( pal.begin(), pal.end() ), pal.end() );
	
	long double den = 1;
	for (int i = 0; i < (int)pal.size(); i++) {
		int qt = rep[pal[i]];
		den *= fatorial(qt);
	}
	
	long double ans = fatorial(n) / den;
	
	cout << fixed << setprecision(0) << (long long int)ans << endl;
	

    return 0;
}