#include "bits/stdc++.h"
using namespace std;
#define MAXN   100001

int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 
vector<int> getFactorization(int x)
{
    vector<int> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}
 
int main(int argc, char const *argv[])
{
    sieve();
    int x;
    cin >> x;
    
    int sizeColors = 0;
    vector<pair<int, int> > diff;
    
    for (int i = 2; i <= x+1; i++) {
    	vector <int> p = getFactorization(i);
    	
    	cout << "\n\n-- " << i << "--\n";
    	for (int kk = 0; kk < p.size(); kk++) {
    		cout << p[kk] << " ";
		}
    	cout << "\n----\n\n";
    	
    	for (int j=0; j<p.size(); j++)
    		if (p[j] <= x && p[j] > 1 && p[j] != diff[sizeColors-1].second) {
    			sizeColors++;
    			diff.push_back({i, p[j]});
			}
	}
	
	for (int i = 0; i < diff.size(); i++) {
		cout << diff[i].first << " : " << diff[i].second << endl;
	}
    return 0;
}
