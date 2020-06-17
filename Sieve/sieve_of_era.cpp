#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

const int N = 1e6 + 7;
vi primes;
vvi pfs(N);// pfs[i] contains all pfs of i
bool composite[N];// {0} initially all prime

// O(N loglogN)
void sieve() {
	for (int i = 2; i <= (N); i++) {
		// till N or sqrt(N) doesnt matter. Almost same complexity of O(NloglogN)
		if (composite[i]) continue;
		primes.push_back(i);// prime
		pfs[i].push_back(i);
		for (int j = 2 * i; j <= N; j += i) {
			composite[j] = 1;// multiple of prime
			pfs[j].push_back(i);
		}
	}
}

int main() {
	sieve();
	for (int i = 1; i <= 10; i++) {
		cout << i << " ";
		for (auto x : pfs[i])
			cout << x << ",";
		cout << endl;
	}
	return 0;
}
