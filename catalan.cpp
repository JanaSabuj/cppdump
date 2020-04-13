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

void print1d(const vector<int>& vec) {for (auto val : vec) {cout << val << " ";} cout << endl;}

void print2d(const vector<vector<int>>& vec) {for (auto row : vec) {for (auto val : row) {cout << val << " ";} cout << endl;}}

const int MOD = 1e9 + 7;
const int MAX = 100;
int catalan[MAX];

// C[i] = SUM(j = 0 to j = i - 1) C[j] * C[i - 1 - j]

void init(int n) {
	catalan[0] = catalan[1] = 1;
	for (int i = 2; i < n; i++) {
		catalan[i] = 0;// ith catalan
		for (int j = 0; j < i; j++) {
			catalan[i] += (catalan[j] * catalan[i - j - 1]) % MOD;
			if (catalan[i] >= MOD)
				catalan[i] -= MOD;
		}
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;

	init(10);
	for (int i = 0; i < 10; ++i) {
		cout << catalan[i] << " ";
	}

	return 0;
}
