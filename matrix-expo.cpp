int addx(int a, int b) {
	a += b;
	if (a >= mod) a -= mod;
	return a;
}
int mulx(int a, int b) {
	a *= b;
	if (a >= mod)
		a %= mod;
	return a;
}


vvi mul(vvi& a, vvi& b) {
	// a = n * k, b = k * m
	int n = a.size();
	int m = b[0].size();
	int kk = a[0].size();

	vvi prod(n, vi(m, 0));;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < kk; k++)
				prod[i][j] = addx(prod[i][j],  mulx(a[i][k],  b[k][j]));
		}
	}

	return prod;
}

vvi matrix_expo(vvi& a, int x) {
	int n = a.size();
	int m = a[0].size();
	vvi res(n, vi(m, 0));
	for (int i = 0; i < m; ++i) {
		res[i][i] = 1;
	}
	// vvi res = {{1, 0}, {0 , 1}};// I2
	while (x > 0) {
		if (x & 1)
			res = mul(res, a);
		a = mul(a, a);
		x /= 2;
	}

	return res;
}


void solve() {
	// An = A * P
	int n;
	cin >> n;
	vvi A = {{1, 1}, {1, 0}};
	vi P = {0, 1};


	if (n < 2)
		cout << P[n] << endl;
	else {

		vvi t = matrix_expo(A, n - 1);
		int ans = 0;
		int cols = A[0].size();

		for (int i = 0; i < cols; i++) {
			ans = addx(ans , mulx(t[0][i] , P[2 - i - 1]));
		}
		cout << ans << endl;
	}
}
