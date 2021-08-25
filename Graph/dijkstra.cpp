vector<pii> adj[N];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int dis[N];
void dijkstra(int src) {
	for (int i = 0; i < N; ++i) {
		dis[i] = LLONG_MAX;
	}

	pq.push({0, src});
	dis[src] = 0;

	while (!pq.empty()) {
		auto curr = pq.top();
		pq.pop();

		int v = curr.second;
		int d_v = curr.first;
		if (d_v != dis[v])
			continue;// stale pair

		for (auto u : adj[v]) {
			int to = u.first;
			int len = u.second;

			if (dis[v] + len < dis[to]) {
				dis[to] = dis[v] + len;
				pq.push({dis[to], to});
			}
		}
	}
}