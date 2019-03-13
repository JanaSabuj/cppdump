//Built by Sabuj Jana(greenindia) from Jadavpur University,Kolkata,India
//God is Great
#include <bits/stdc++.h>
using namespace std;
#define crap ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define int long long int
const int INF = 1e9 + 5; //billion
#define pb push_back
#define mp make_pair

typedef vector<int> vi;

const int MAX = 1e4 + 5;
int id[MAX], nodes, edges;
int mincost;
pair< int, pair<int, int>> p[MAX];
vector<pair<int, int>> mst;

//initialize
void initialize() {

	for (int i = 0; i < MAX; ++i)
	{
		/* code */
		id[i] = i;
	}
}

//root
int root(int x) {

	while (id[x] != x) {
		id[x] = id[id[x]];
		x = id[x];
	}

	return x;
}

//union1
void union1(int x, int y) {

	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}

//kruskal
int kruskal(pair< int, pair<int, int>> p[]) {

	int x, y, cost, mc = 0;
	for (int i = 0; i < edges; ++i)
	{
		/* code */
		// selecting edges 1/1 in asc order
		x = p[i].second.first;
		y = p[i].second.second;
		cost = p[i].first;

		//check for cycle
		if ( root(x) != root(y)) {
			mc += cost;
			union1(x, y);
			mst.pb({x, y});
		}

	}

	return mc;
}

signed main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
	crap;

	//clearing the global mst vector
	mst.clear();

	// take the entire input of graph
	cin >> nodes >> edges;

	for (int i = 0; i < edges; ++i)
	{
		/* code */
		int x, y, weight;
		cin >> x >> y >> weight;
		p[i] = { weight, {x, y}};
	}
	// initialise array for union find
	initialize();

	//sorting the edges in ascending order of weights
	sort(p, p + edges);
	mincost = kruskal(p);
	cout << mincost << endl;

	//printing the MST
	for (auto x : mst) {
		cout << x.first << " " << x.second << endl;
	}


	return 0;

}

