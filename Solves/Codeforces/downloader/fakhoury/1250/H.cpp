#include <bits/stdc++.h>
using namespace std;
 #define INF 0x3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
 typedef pair<int, int> pii;
typedef long long ll;
 const int MAX = 10 + 5;
int c[MAX];
int main() 
{
 ios::sync_with_stdio(false); cin.tie(NULL);
 int t;
 cin >> t;
 while(t--)
 {
  int menor = 1;
  for(int i=0;i<10;i++)
  {
   cin >> c[i];
   if(i!=0 and c[i] < c[menor])
    menor = i;
  }
  if(c[menor] == 0)
   cout << menor << endl;
  else if(c[0] < c[menor])
  {
   cout << 1;
   for(int i=0;i<c[0]+1;i++)
    cout << 0;
   cout << endl;
  }
  else
  {
   for(int i=0;i<c[menor]+1;i++)
   {
    cout << menor; 
   }
   cout << endl;
  }
  }
 return 0;
}