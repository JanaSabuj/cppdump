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

void insertx(trieNode* root, int x){
	trieNode* curr = root;

	for(int i = 31; i >= 0; i--){
		int bit = (x>>i)&1;// find ith bit

		if(bit == 0){
			// go to left
			if(!curr->left)
				curr->left = new trieNode();
			curr = curr->left;
		}else if(bit == 1){
			// go to right
			if(!curr->right)
				curr->right = new trieNode();
			curr = curr->right;
		}
	}
}

int queryx(trieNode* root, int x){
	trieNode* curr = root;
	int val = 0;

	for(int i = 31; i >= 0; i--){
		int bit = (x>>i)&1;// find ith bit

		if(bit == 0){
			// go to 1
			if(curr->right){
				val += (1<<i);
				curr = curr->right;
			}
			else
				curr = curr->left;
		}else if(bit == 1){
			// go to 0
			if(curr->left){
				val += (1<<i);
				curr = curr->left;
			}
			else
				curr = curr->right;
		}
	}

	return val;
}


int findMaximumXOR(vector<int>& arr) {
	int n = arr.size();
	trieNode* root = new trieNode();// our trie

	for(int i=0; i<n; i++){
		insertx(root, arr[i]);		
	}

	int ans = 0;

	for(int i=0; i<n; i++){
		ans = max(ans, queryx(root, arr[i]));
	}

	return ans;

}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	crap;

	int n;
	cin >> n;

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	cout << findMaximumXOR(arr) << endl;


	return 0;
}




