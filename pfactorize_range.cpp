const int N = 1e2 + 7;
bool composite[N];
int LargestPrime[N];// {0} initially all prime and stores the largest prime factor of indexed number
vector<pair<int, int>> pf[N + 5];// stores pfactorization 

void sieve() {
	for (int i = 2; i <= (N); i++) {
		if (composite[i]) continue;
		LargestPrime[i] = i;
		for (int j = i * i; j <= N; j += i) {
			LargestPrime[j] = i;
			composite[j] = 1;
		}
	}
}

void pfactorize() {
	for (int i = 2; i <= N; i++) {
		int x = i;// pfactorize i
		map<int, int> mp;
		while (x != 1) {
			mp[LargestPrime[x]]++;
			x /= LargestPrime[x];
		}
		for (auto v : mp) {
			pf[i].push_back(v);// prime, exponent
		}
	}
}

void solve() {
	sieve();
	pfactorize();
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;

	solve();


	return 0;
}
