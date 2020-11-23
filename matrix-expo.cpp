/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
//
//		  _____       _           _        _
//		 / ____|     | |         (_)      | |
//		| (___   __ _| |__  _   _ _       | | __ _ _ __   __ _
//		 \___ \ / _` | '_ \| | | | |  _   | |/ _` | '_ \ / _` |
//		 ____) | (_| | |_) | |_| | | | |__| | (_| | | | | (_| |
//		|_____/ \__,_|_.__/ \__,_| |  \____/ \__,_|_| |_|\__,_|
//		                        _/ |
//		                       |__/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
#define int long long int
#define double long double
#define PI acos(-1)
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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;
	int n = 10;
	vi fib1(n), fib2(n);
	fib1[0] = 0;
	fib1[1] = 1;
	for (int i = 2; i < n; i++)
		fib1[i] = fib1[i - 1] + fib1[i - 2];

	// matrix-expo in logN
	vvi base = {
		{1, 1},
		{1, 0}
	};

	for (int i = 0; i < n; i++) {
		vvi t = matrix_expo(base, i);
		// print1d(t);
		fib2[i] = t[0][0] * fib1[1] + t[1][0] * fib1[0];
	}

	print1d(fib1);
	print1d(fib2);

// op
// 0 1 1 2 3 5 8 13 21 34
// 1 1 2 3 5 8 13 21 34 55
	return 0;
}