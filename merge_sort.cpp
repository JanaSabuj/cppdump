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

void merge(int arr[], int l, int mid, int r) {
	int n1 = mid - l + 1;
	int n2 = r - mid;

	int L[n1], R[n2];
	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int i = 0; i < n2; ++i) {
		R[i] = arr[mid + 1 + i];
	}

	int i = 0, j = 0, k = l;
	while (i < n1 and j < n2) {
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}

	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
}

void MS(int arr[], int l, int r) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		MS(arr, l, mid);
		MS(arr, mid + 1, r);
		merge(arr, l, mid, r);
	}
}


signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;

	int arr[] = {4, 8, 2, 4, 5, 7, 9, 6, 3, 3};
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << n << endl;
	MS(arr, 0, n - 1);

	for (int i = 0; i < n; ++i) {
		cout << arr[i] << " ";
	}

	return 0;
}