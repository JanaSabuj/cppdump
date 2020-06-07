vector<vector<pair<int, int>>> adj;// adj list with node + edge-wt
vi dist;
vi visited;

void dijkstra(int n, int src) {

	dist[src] = 0;
	for (int i = 0; i < n; i++) {
		// n iterations

		//1. Pick an unvisited min-dist node
		int v = -1;
		for (int j = 1; j <= n; j++) {
			if (!visited[j] and (v == -1 or dist[j] < dist[v])) {
				v = j;
			}
		}
		if (dist[v] == INT_MAX)
			break;

		//2. Mark it visited
		visited[v] = true;


		//3. Relax its neighbours simply
		for (auto u : adj[v]) {
			int to = u.first;
			int d = u.second;
      
			if (visited[u])
				continue;
			if (dist[v] + d < dist[to]) {
				dist[to] = dist[v] + d;
			}
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	adj.clear();
	adj.resize(n + 1);
	dist.assign(n + 1, INT_MAX);
	visited.assign(n + 1, false);

	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}


	int src;
	cin >> src;

	dijkstra(n, src);

	for (int i = 1; i <= n; i++) {		
			cout << dist[i] << " ";
	}
	cout << endl;
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("error.txt", "w", stderr);
#endif
	crap;

	int t;
	cin >> t;

	while (t--) {
		solve();
	}


	return 0;
}
