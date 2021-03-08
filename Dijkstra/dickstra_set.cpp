const int inf = 1e9;
vector<vector<pair<int, int>>> adj;// adj list for weighted graphs
vector<int> dist;
vector<int> par;

void dijkstra(int src) {
	int n = adj.size();
	dist.assign(n, inf);
	par.assign(n, -1);

	dist[src] = 0;

	set<pair<int, int>> q;
	q.insert({0, src});

	while (!q.empty()) {
		int v = q.begin()->second;
		q.erase(q.begin());

		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (dist[v] + len < dist[to]) {
				q.erase({dist[to], to});
				dist[to] = d[v] + len;
				par[to] = v;
				q.insert({d[to], to});
			}
		}
	}
}
