const int lim = 1e6;
const int p = 1e9 + 7;
int fac[lim];

void preprocess() {
	fac[0] = 1;

	for (int i = 1; i <= lim; ++i) {
		fac[i] = (fac[i - 1] * i) % p;
	}
}

int power(int a, int b, int m) {
	a = a % m;
	int ans = 1;
	while (b) {
		if (b & 1)
			ans = (ans * a) % m;
		a = (a * a) % m;
		b /= 2;
	}

	return ans;
}

int inverse(int a, int p) {
	return power(a, p - 2, p);
}

int ncrmodp(int n, int r, int p) {
	// n!
	//-------- mod p
	//r!(n-r)!

	return (fac[n] * inverse(fac[r], p) * inverse(fac[n - r], p)) % p;
}

void solve() {
	preprocess();

	int n = 10, r = 2;
	cout << ncrmodp(n, r, p) << endl;
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
