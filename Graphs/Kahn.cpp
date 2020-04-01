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

const int nax = 1e5 + 7;
vector<vector<int>> adj(nax);
vector<int> in_degree(nax, 0);

void kahn(int n) {
	queue<int> q;// priority queue for lexicographically smallest
	// priority_queue<int, vector<int>, greater<int>> q;// priority queue for lexicographically smallest
	for (int i = 1; i <= n; ++i) {
		if (in_degree[i] == 0)
			q.push(i);
	}

	vector<int> order;
	while (!q.empty()) {
		int u = q.front();
		// int u = q.top(); // for priority queue
		q.pop();
		order.push_back(u);// in-deg = 0

		for (auto v : adj[u]) {
			--in_degree[v];
			if (in_degree[v] == 0)
				q.push(v);
		}
	}

	if ((int)order.size() != n)
		cout << "Not a DAG" << endl;
	else
		print1d(order);
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;
	int n, e;
	cin >> n >> e;

	int t = e;
	while (t--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		++in_degree[b];
	}

	kahn(n);

	return 0;
}