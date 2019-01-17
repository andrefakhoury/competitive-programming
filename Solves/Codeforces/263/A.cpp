// Example program
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x=0, y=0;
    int n, ans=0;
  
  for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
          cin >> n;
          if (n==1) {
            x = i; y = j;   
          }
      }
  }
  
  if (x > 2) ans+= x-2;
  else if (x < 2) ans+= 2-x;
  
  if (y > 2) ans+= y-2;
  else if (y < 2) ans+= 2-y;
  
  cout << ans << endl;
}
