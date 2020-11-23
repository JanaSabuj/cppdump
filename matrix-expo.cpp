#include <bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long int
#define double long double
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
#define endl "\n"
void print1d(const vector<int>& vec) {for (auto val : vec) {cout << val << " ";} cout << endl;}
void print2d(const vector<vector<int>>& vec) {for (auto row : vec) {for (auto val : row) {cout << val << " ";} cout << endl;}}

vvi mul(vvi& a, vvi& b) {
	vvi prod = {{0, 0}, {0, 0}};
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++)
				prod[i][j] += (a[i][k] * b[k][j]);
		}
	}

	return prod;
}

vvi matrix_expo(vvi a, int n) {
	vvi res = {{1, 0}, {0 , 1}};// I2
	while (n > 0) {
		if (n & 1)
			res = mul(res, a);
		a = mul(a, a);
		n /= 2;
	}

	return res;
}

signed main() {
	crap;
	int n = 1e2;
	vi fib2;

	// matrix-expo in logN
	vvi base = {
		{1, 1},
		{1, 0}
	};

	for (int i = 0; i < n; i++) {
		vvi t = matrix_expo(base, i);
		fib2.push_back(t[0][0] * 1 + t[1][0] * 0);
		if (fib2[i] > (int)1e10)
			break;
	}

	// print1d(fib2);

	return 0;
}
