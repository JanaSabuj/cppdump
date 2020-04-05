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

const int N = 4;
vector<vector<int>> board(N, vector<int>(N, 0));
int cnt = 0;
bool isValid(int n, int row, int col) {
	//Col up
	for (int i = row - 1; i >= 0; i--) {
		if (board[i][col] == 1)
			return false;
	}

	// Left up diagonal
	for (int i = row - 1, j = col - 1; i >= 0 and j >= 0; i--, j--) {
		if (board[i][j] == 1)
			return false;
	}

	// Right up diagonal
	for (int i = row - 1, j = col + 1; i >= 0 and j < n; i--, j++) {
		if (board[i][j] == 1)
			return false;
	}

	return true;
}

void helper(int n, int row) {
	if (row == n) {
		// reached the base
		print2d(board);
		cnt++;
		return;
	}

	for (int j = 0; j < n; j++) {
		if (isValid(n, row, j)) {
			board[row][j] = 1;
			helper(n, row + 1);
			board[row][j] = 0;
		}
	}
	return;
}

void nQueen(int n) {
	helper(n, 0);
	return;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;

	int n = 4;
	nQueen(n);
	cout << cnt << endl;

	return 0;
}