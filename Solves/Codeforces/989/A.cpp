#include <bits/stdc++.h>

using namespace std;

int main() {
	string s;
	cin >> s;
	if (s.find("ABC") != string::npos || 
			s.find("ACB") != string::npos || 
			s.find("BAC") != string::npos || 
			s.find("BCA") != string::npos || 
			s.find("CAB") != string::npos || 
			s.find("CBA") != string::npos)
		printf("Yes\n");
	else printf("No\n");
	return 0;
	
}
