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

void solve() {
	int n, q;
	cin >> n >> q;

	vi arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	int len = (int)sqrt(n + 0.0) + 1;
	vi b(len, INT_MAX);

	// preprocess

	for (int i = 0; i < n; ++i) {
		b[i  / len] = min(b[i / len], arr[i]);
	}

	// print1d(b);

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		// process
		int ans = INT_MAX;
		int c_l = l / len;
		int c_r = r / len;

		if (c_l == c_r) {
			for (int i = l; i <= r; i++)
				ans = min(ans, arr[i]);
		} else {
			for (int i = l; i < (c_l + 1) * len; i++)
				ans = min(ans, arr[i]);
			for (int i = c_l + 1; i < c_r; i++)
				ans = min(ans, b[i]);
			for (int i = c_r * len; i <= r; i++)
				ans = min(ans, arr[i]);
		}

		cout << ans << endl;
	}

}

signed main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("error.txt", "w", stderr);
// #endif
	crap;

	solve();

	return 0;
}
