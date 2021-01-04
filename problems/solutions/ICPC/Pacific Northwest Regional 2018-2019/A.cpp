#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define se second
#define fi first

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int k;
    cin >> k;
    string eu,ele;
    cin >> eu >> ele;
    int certo =0;
    for(int i=0;i<eu.size();i++)
    {
        if(eu[i] == ele[i] and k>0)
        {
            certo++;
            k--;
        }
    }
    int dif = 0;
       
    for(int i=0;i<eu.size();i++)
    {    
        if(eu[i]!=ele[i] and k>0)
        {
            k--;
        }
        else if(eu[i] != ele[i])
            certo++;
    }           
    
    cout << certo << endl;

    /*
6
TTFTFFTFTF
TTTTFFTTTT

    */


    return 0;
}