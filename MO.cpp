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

const int block = 320;

struct Query {
	int l, r, idx;
};

bool comp(const Query& x, const Query& y) {
	if ((x.l / block) != (y.l / block))
		return x.l / block < y.l / block;
	return x.r < y.r;
}

vector<int> mosAlgo(vector<int>& arr, vector<Query>& queries) {
	vector<int> answers(queries.size());
	sort(queries.begin(), queries.end(), comp);

	int sum = 0;
	int l = 0;
	int r = -1;

	for (auto q : queries) {
		cout << q.l << " " << q.r << endl;
		while (r < q.r) {
			r++;
			sum += arr[r];
		}

		while (l < q.l) {
			sum -= arr[l];
			l++;
		}

		while (l > q.l) {
			l--;
			sum += arr[l];
		}

		while (r > q.r) {
			sum -= arr[r];
			r--;
		}

		answers[q.idx] = sum;
	}

	return answers;
}

void solve() {
	int n, q;
	cin >> n >> q;

	// get arr
	vi arr(n);
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
	}

	// get queries
	vector<Query> queries(q);
	for (int i = 0; i < q; ++i) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;

		queries[i] = {l, r, i};
	}

	// mo
	vector<int> req = mosAlgo(arr, queries);

	// print
	for (auto x : req)
		cout << x << endl;
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
