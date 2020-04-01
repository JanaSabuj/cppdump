/*--------------------------"SABUJ-JANA"------"JADAVPUR UNIVERSITY"--------*/
/*-------------------------------@greenindia-----------------------------------*/

//   _____       _           _        _                   
//  / ____|     | |         (_)      | |                  
// | (___   __ _| |__  _   _ _       | | __ _ _ __   __ _ 
//  \___ \ / _` | '_ \| | | | |  _   | |/ _` | '_ \ / _` |
//  ____) | (_| | |_) | |_| | | | |__| | (_| | | | | (_| |
// |_____/ \__,_|_.__/ \__,_| |  \____/ \__,_|_| |_|\__,_|
//                         _/ |                           
//                        |__/                         
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
int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89};
string alpha = "abcdefghijklmnopqrstuvwxyz";
/*----------JU IS LOVE----------*/
//int power(int a,int b,int m){int ans=1;while(b){if(b&1)ans=(ans*a)%m;b/=2;a=(a*a)%m;}return ans;}
//int power(int a, int b){int ans=1;while(b){if(b&1)ans=ans*a;b/=2;a=a*a;}return ans;}

const int n = 100 ;// no of nodes
vector<int> adj[n];// adj list


queue<int> q;
std::vector<int> used(n, 0); // used array
std::vector<int> d(n, 0), p(n, 0); // distance and parent vector

void bfs(int root) {

	q.push(root);
	used[root] = 1;
	d[root] = 0;
	p[root] = -1;

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (auto u : adj[x]) {
			if (!used[u]) {
				used[u] = true;
				q.push(u);
				d[u] = d[x] + 1;
				p[u] = x;
			}
		}
	}


}


signed main() {

	freopen("input.txt", "r", stdin);
	crap;

	int nodes;
	int edges;
	cin >> nodes >> edges;

	for (int i = 0; i < edges; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	bfs(1);// root

	//printing the shortest undirected path from 1 to 13
	int dest = 13;
	if(!used[dest])
		cout <<"No path from root" <<endl;
	else
	{
		std::vector<int> path;
		for(int v = dest; v!=-1; v = p[v]){
			path.push_back(v);
		}
		reverse(path.begin(), path.end());
		cout <<"Path: ";
		for(auto x: path)
			cout << x <<" ";
	}s

	return 0;
}





