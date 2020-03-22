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

vector<int> rabin_karp(const string& pat, const string& str) {
	const int p = 31;
	const int m = 1e9 + 9;
	int S = pat.length();
	int T = str.length();

	vector<int> p_pow(max(S, T));
	p_pow[0] = 1; // p^0 - 1
	for (int i = 1; i < (int)p_pow.size(); i++)
		p_pow[i] = (p_pow[i - 1] * p) % m;

	vector<int> h(T + 1, 0); // length-wise hash
	for (int i = 0; i < T; i++) {
		h[i + 1] = (h[i] + (str[i] - 'a' + 1) * p_pow[i]) % m;
	}

	int h_s = 0;// hash of the pattern
	for (int i = 0; i < S; i++)
		h_s = (h_s + (pat[i] - 'a' + 1) * p_pow[i]) % m;

	std::vector<int> occurs;
	for(int i = 0; i + S - 1 < T; i++){
		int cur_h = (h[i + S] - h[i] + m ) % m;
		if(cur_h == h_s * p_pow[i] % m)
			occurs.push_back(i);
	}

	return occurs;

}


signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;
	//            0123456789x
	string str = "madametussadames";
	string pat = "adam";

	vector<int> ids = rabin_karp(pat, str);
	for (auto x : ids)
		cout << x << " ";

	return 0;
}




