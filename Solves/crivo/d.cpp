#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define pb push_back

long long int fac[N];
bool prime[N] = {false};

int sieveOfAtkin(int limit)
{
	prime[1] = true;
	prime[2] = true;
	prime[3] = true;
    for (int x = 1; x * x < limit; x++) {
        for (int y = 1; y * y < limit; y++) {
             
            // Main part of prime of Atkin
            int n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                prime[n] ^= true;
 
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                prime[n] ^= true;
 
            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11)
                prime[n] ^= true;
        }
    }
 
    for (int r = 5; r * r < limit; r++) {
        if (prime[r]) {
            for (int i = r * r; i < limit; i += r * r)
                prime[i] = false;
        }
    }
 
    for (int a = 5; a < limit; a++)
        if (prime[a])
            cout << a << " ";
}

void fact() {	
	fac[0] = 1;
	fac[1] = 1;
	fac[2] = 2;
	for (long long int i = 3; i < N; i++) {
		fac[i] = i * fac[i-1];
	}
}

int main() {
	sieveOfAtkin(N);
	
	for (int i = 0; i < N; i++) {
		cout << prime[i] << " ";
	}
	
	fact();
	int x, y;
	while(scanf("%d %d", &x, &y) != EOF) {
		if (fac[y]%x == 0)
			printf("%d divides %d!\n", y, x);
		else
			printf("%d does not divide %d!\n", y, x);
	}
	
    
}
