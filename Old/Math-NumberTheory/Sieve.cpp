//Built by Sabuj Jana(greenindia) from Jadavpur University,Kolkata,India
// God is Great

#include <bits/stdc++.h>
using namespace std;


void Era() {
	int limit = 1000007;
	bool sieve[limit + 1];
	memset(sieve, true, sizeof(sieve));

	sieve[0] = false;
	sieve[1] = false;

	for (int i = 2; i * i <= limit ; ++i)
	{
		/* code */
		if (sieve[i] == true) {

			for (int j = i * i; j <= limit; j += i) {
				sieve[j] = false;
			}
		}
	}
}
