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

vector<int> tree(10000, 0);
vector<int> arr(10000);

//1. build
void build(int start, int end, int tn) {
	if (start == end) {
		tree[tn] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	build(start, mid, 2 * tn);
	build(mid + 1, end, 2 * tn + 1);

	tree[tn] = tree[2 * tn] + tree[2 * tn + 1];
}

//2. update
void update(int start, int end, int tn, int idx, int val) {

	if (start == end) {
		arr[idx] = val;
		tree[tn] = val;
		return;
	}

	int mid = (start + end) / 2;
	if (idx > mid)
		update(mid + 1, end, 2 * tn + 1, idx, val);
	else
		update(start, mid, 2 * tn, idx, val);

	tree[tn] = tree[2 * tn] + tree[2 * tn + 1];
}

// 3. query
int query(int start, int end, int tn, int l, int r) {
	// outside
	if (start > r or end < l)
		return 0;
	// inside
	if (start >= l and end <= r)
		return tree[tn];

	// partial
	int mid = (start + end) / 2;
	int val1 = query(start, mid, 2 * tn, l, r);
	int val2 = query(mid + 1, end, 2 * tn + 1, l, r);

	return val1 + val2;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;

	arr = {1, 2, 3, 4, 5, 6, 7};
	int n = arr.size();
	// 1. build seg tree
	build(0, n - 1, 1);

	// 2. updateTree
	// change idx 2 to val 10
	int idx = 2;
	int val = 10;
	update(0, n - 1, 1, idx, val);

	// 3. query
	int l = 1;
	int r = 5;

	cout << query(0, n-1, 1, l, r) << endl;

	return 0;
}




