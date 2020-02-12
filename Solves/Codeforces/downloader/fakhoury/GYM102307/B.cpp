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
string s;
string add;
bool ispalin()
{
 for(int i=0;i<s.size()/2;i++)
 {
  if(s[i]!=s[s.size()-i-1])
  {
   return false;
  }
 }
 return true;
}
 int main() 
{
 ios::sync_with_stdio(false); cin.tie(NULL);
 int p=0;
 string ini;
 cin >> s;
 ini = s;
 while(!ispalin())
 {
  add.pb(s[p]);
  string inv = add;
  reverse(inv.begin(),inv.end());
  s= ini+inv;
  p++; 
 }
 cout << s << endl;
 return 0;
}