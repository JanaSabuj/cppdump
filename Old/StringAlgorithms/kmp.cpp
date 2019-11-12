/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/
/*---------------------- Magic. Do not touch.-----------------------------*/
/*------------------------------God is Great/\---------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
//cout<<fixed<<showpoint<<setprecision(12)<<ans<<endl;
#define dbg(x) cerr << #x << " = " << x << endl
#define endl "\n"
#define int long long int
#define double long double
#define pb push_back
#define mp make_pair
#define PI acos(-1)

//const int INF=1e9+5;//billion
string alpha = "abcdefghijklmnopqrstuvwxyz";
/*----------JU IS LOVE----------*/
//int power(int a,int b,int m){int ans=1;while(b){if(b&1)ans=(ans*a)%m;b/=2;a=(a*a)%m;}return ans;}
//int power(int a, int b){int ans=1;while(b){if(b&1)ans=ans*a;b/=2;a=a*a;}return ans;}

int* LPS(string pattern){

	int n=pattern.length();
	int* lps=new int[n];
	lps[0]=0;
	int j=0,i=1;
	
	while(i<n){
		if(lps[j]==lps[i]){
			lps[i]=j+1;
			i++;
			j++;
		}
		else {
			if(j!=0)
				j=lps[j-1];
			else{
				lps[i]=0;
				i++;
			}
		}
	}

	return lps;

}



bool KMP(string text, string pattern) {

	int lenText = text.length();
	int lenPattern = pattern.length();

	int i = 0, j = 0;
	int* lps= LPS(pattern);
	while (i < lenText and j < lenPattern) {

		if (text[i] == pattern[j]) {
			i++;
			j++;
		}
		else {

			if(j!=0){
				j=lps[j-1];
			}
			else{
				i++;
			}

		}

		if(j==lenPattern)
			return true;


	}

	return false;

}

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	crap;

	string s, p;
	cin >> s >> p;

	if (KMP(s, p))
		cout << "YES";
	else
		cout << "NO";


	return 0;
}

