#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
vector<int> primes;
bool composite[N];// {0} initially all prime

// O(N loglogN)
void sieve() {
	for (int i = 2; i <= (N); i++) {
		// till N or sqrt(N) doesnt matter. Almost same complexity of O(NloglogN)
		if (composite[i]) continue;
		primes.push_back(i);// prime
		for (int j = 2 * i; j <= N; j += i)
			composite[j] = 1;// multiple of prime
	}
}

int main() {
	sieve();
	for (auto x : primes)
		cout << x << " ";
	return 0;
}
