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

void print1d(const vector<int>& vec) {for (auto val : vec) {cout << val << " ";} cout << endl;}

void print2d(const vector<vector<int>>& vec) {for (auto row : vec) {for (auto val : row) {cout << val << " ";} cout << endl;}}

vector<int> tree(10005, 0);

void update(int index, int val, int n) {
	// updt idx index with +val
	for (; index <= n; index += index & (-index)) {
		tree[index] += val;
	}
}

int query(int index) {
	// give total sum from idx 1 to idx index
	int sum = 0;
	for (; index > 0; index -= index & (-index)) {
		sum += tree[index];
	}
	return sum;
}


signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;

	int n;
	cin >> n;

	vector<int> arr(n + 1);


	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		update(i, arr[i], n);
	}

	int q;
	cin >> q;

	while (q--) {
		int l, r;// input 1 based indexes OR inc++ them
		cin >> l >> r;
		cout << query(r) - query(l - 1) << endl;
	}

	// 7
	// 1 2 3 4 5 6 7
	// 3
	// 1 2
	// 3 5
	// 4 6

	// 3
	// 12
	// 15
	// [Finished in 1.0s]

	return 0;
}




