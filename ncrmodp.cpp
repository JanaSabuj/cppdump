const int maxn = 2e6 + 5;
const int mod = 1e9 + 7;
int fac[maxn], invfac[maxn];

int add(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}
int mul(int a, int b) {
	a *= b;
	if (a >= mod)
		a %= mod;
	return a;
}
int powmod(int x, int p)
{
	int sum = 1;
	for (; p; x = mul(x, x), p >>= 1)
		if (p & 1)
			sum = mul(sum, x);
	return sum;
}
int ncr(int n, int r)
{
	if (r < 0)
		return 0;
	if (r > n)
		return 0;
	return mul(mul(fac[n], invfac[n - r]), invfac[r]);
}
void preprocess() {
	fac[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		fac[i] = mul(fac[i - 1], i);
	}
	invfac[maxn - 1] = powmod(fac[maxn - 1], mod - 2);
	for (int i = maxn - 2; i >= 0; i--)
		invfac[i] = mul(invfac[i + 1], i + 1);
}
-----------------------------------------------------------
	const int N = 1e5 + 7;
const int mod = 1e9 + 7;
int fac[N];

void prefac() {
	fac[0] = 1;
	for (int i = 1; i < N; ++i) {
		fac[i] = (fac[i - 1] * i) % mod;
	}
}

int power(int a, int b, int p) {
	int res = 1;
	a %= p;
	while (b) {
		if (b & 1)
			res = res * a % p;
		a = a * a % p;
		b /= 2;
	}

	return res;
}

int invmodp(int a, int p) {
	return power(a, p - 2, p);
}

int ncrmodp(int n, int r, int p) {
	if (n < r)
		return 0;
	if (r == 0)
		return 1;
	return ((fac[n] * invmodp(fac[r], p)) % p * invmodp(fac[n - r], p)) % p;
}
