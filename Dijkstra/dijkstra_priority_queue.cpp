// Sabuj Jana
vector<vector<pair<int, int>>> adj;
vi dist;
vi visited;

void dijkstra(int n, int src) {

	dist[src] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, src});

	while (!pq.empty()) {
		int v = pq.top().second;
		int d = pq.top().first;
		pq.pop();

		if (visited[v])
			continue;

		//2. Mark it visited
		visited[v] = true;

		//3. Relax its neighbours simply
		for (auto u : adj[v]) {
			int to = u.first;
			int d = u.second;

			if (visited[to])
				continue;

			if (dist[v] + d < dist[to]) {
				dist[to] = dist[v] + d;
				pq.push({dist[to], to});
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
		if (i == src)
			continue;
		if (dist[i] == INT_MAX)
			cout << -1 << " ";
		else
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
