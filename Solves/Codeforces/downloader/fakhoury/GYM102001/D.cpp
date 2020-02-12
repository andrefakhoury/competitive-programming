#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair
 typedef pair<int, int> pii;
typedef long long ll;
 const int MAX = 5e2 + 5;
const int INF = 0x3f3f3f3f;
 int main() 
{
 ios::sync_with_stdio(false); cin.tie(NULL); 
 int n,m;  
 int resp =0;
 cin >> n >> m;
 string linhas[MAX];
 for(int i=0;i<n;i++)
 {
  cin >> linhas[i]; 
 }
 if(n == 2 or m == 2)
 {
  // kkk fodeu 
  if(n == 2)
  {
   for(int j =1 ;j<(m-1);j++)
   {
    if(linhas[0][j] == '#' or linhas[1][j] == '#')
     continue;
    else
     resp++;
   }
  }
  else
  {
   for(int i =1;i<(n-1);i++)
   {
    if(linhas[i][0] == '#' or linhas[i][1] == '#')
     continue;
    else
     resp++;
   }
  }
  cout << resp << endl;
  return 0;
 }
 if(n == 1 or m ==1 )
 {
  if(n == 1)
  {
   for(int j=1;j<(m-1);j++)
   {
    if(linhas[0][j] == '.')
     resp++;
   }
  }
  else
  {
    for(int i=1;i<(n-1);i++)
    if(linhas[i][0] == '.')
     resp++;
  }
  cout << resp << endl;
   return 0;
 }
 for(int i=1;i<(n-1);i++)
 {
  for(int j=1;j<(m-1);j++)
  {
   if(linhas[i][j] == '.')
    resp++;
  }
 }
 bool safe = false;
 for(int i=1;i<(n-1);i++)
 {
  if(linhas[i][0] == '#' or linhas[i][m-1] == '#') 
   safe = true;
 }
 for(int j =1 ;j<(m-1);j++)
 {
  if(linhas[0][j] == '#' or linhas[n-1][j] == '#')
   safe = true;
 }
 if(not safe)
  resp++;
 cout << resp << endl;
 return 0;
}