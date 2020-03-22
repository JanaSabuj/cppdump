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

struct trieNode {
	trieNode* left;
	trieNode* right;
};

void insert(trieNode* root, int x) {
	trieNode* curr = root;

	for (int i = 31; i >= 0; i--) {
		int bit = (x >> i) & 1;

		if (bit == 0) {
			if (!curr->left)
				curr->left = new trieNode();
			curr = curr->left;
		} else {
			if (!curr->right)
				curr->right = new trieNode();
			curr = curr->right;	
		}
	}
}

int query(trieNode* root, int x) {
	trieNode* curr = root;
	int val = 0;

	for (int i = 31; i >= 0; i--) {
		int bit = (x >> i) & 1;

		if (bit == 0) {
			// go to 1
			if (curr->right){
				val += (1 << i);
				curr = curr->right;
			}
			else
				curr = curr->left;
		} else {
			// go to 0
			if (curr->left){
				val += (1<<i);
				curr = curr->left;
			}
			else
				curr = curr->right;
		}
	}

	return val;
}


int XORSUBARRAY(vector<int>& arr) {
	int n = arr.size();

	int req = 0;
	int curr_xor = 0;
	trieNode* root = new trieNode();

	insert(root, 0);// MOST IMP FOR PREFIX OPS
	// IF ENTIRE PRE IS THE ANS, KEEP A CHECK FOR 0
	// a^b^c..z^0 = a^b^c^..^z

	for (int i = 0; i < n; i++) {
		curr_xor = curr_xor ^ arr[i];

		insert(root, curr_xor);

		int ans = query(root, curr_xor);

		req = max(req, ans);
	}

	return req;
}


signed main() {
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// #endif
	crap;
	// #icpc
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		std::vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		cout << XORSUBARRAY(arr) << endl;
	}


	return 0;
}




