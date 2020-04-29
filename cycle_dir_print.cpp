void print1d(const vector<int>& vec) {for (auto val : vec) {cout << val << " ";} cout << endl;}

void print2d(const vector<vector<int>>& vec) {for (auto row : vec) {for (auto val : row) {cout << val << " ";} cout << endl;}}

#define N 100
vvi adj;
vi color;
vi parent;
int cycle_start, cycle_end;

bool dfs(int v) {
	color[v] = 1; // pending
	for (auto u : adj[v]) {
		if (color[u] == -1) {
			// not visited
			parent[u] = v;
			if (dfs(u))
				return true;
		} else if (color[u] == 1) {
			cycle_start = u;
			cycle_end = v;
			return true;
		}
	}

	color[v] = 2;
	return false;
}

void solve() {
	int n, m;
	cin >> n >> m;

	color.assign(n + 1, -1);
	parent.assign(n + 1, -1);
	adj.assign(n + 1, {});

	while (m--) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
	}

	cycle_start = -1;

	for (int i = 1; i <= n; i++) {
		if (color[i] == -1 and dfs(i))
			break;
	}

	if (cycle_start == -1)
		cout << "NO CYCLE in the graph" << endl;
	else {
		cout << "Cycle present in the graph" << endl;
		// cout << cycle_start << " " << cycle_end << endl;

		vi route;
		route.push_back(cycle_start);
		for (int i = cycle_end; i != cycle_start; i = parent[i]) {
			route.push_back(i);
		}
		route.push_back(cycle_start);
		reverse(route.begin(), route.end());
		print1d(route);
	}
}

signed main() {
	solve();
	return 0;
}
