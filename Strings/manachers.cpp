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

vector<int> D1(string s) {
	int n = s.length();
	vector<int> d1(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		d1[i] = k--;
		if (i + k > r) {
			l = i - k;
			r = i + k;
		}
	}

	return d1;
}

vector<int> D2(string s) {
	int n = s.length();
	vector<int> d2(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
		int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
		while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
			k++;
		}
		d2[i] = k--;
		if (i + k > r) {
			l = i - k - 1;
			r = i + k ;
		}
	}

	return d2;
}

vector<int> lengthD1(vector<int> d1) {
	int n = d1.size();
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		ans[i] = 2 * d1[i] - 1;
	}

	return ans;
}

vector<int> lengthD2(vector<int> d2) {
	int n = d2.size();
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		ans[i] = 2 * d2[i];
	}

	return ans;
}


signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;

	string str = "abcdfdcecbaabcdfdcecba";
	vector<int> d1 = D1(str);
	vector<int> d2 = D2(str);
	vector<int> len_d1 = lengthD1(d1);
	vector<int> len_d2 = lengthD2(d2);


	for (auto c : str)
		cout << c << " ";
	cout << endl;

	print1d(d1);
	print1d(d2);
	print1d(len_d1);
	print1d(len_d2);

	// leftd1 = i - (len-1)/2 
	// rightd1 = i + len/2

	// leftd2 = i - len/2
	// rightd2 = i + len/2 - 1

	return 0;
}




