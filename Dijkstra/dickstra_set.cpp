/*
Sabuj Jana / @greenindia
https://www.janasabuj.github.io
*/

const int N = 1e4 + 7;
vector<pair<int, int>> adj[N];
#define inf (1 << 30)
vi dist(N, inf);
vi par(N, -1);

void dickstra(int src) {
	set<pair<int, int>> s;
	s.insert({0, src});
	dist[src] = 0;

	while (!s.empty()) {
		int v = s.begin()->second;
		s.erase(s.begin());

		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (dist[v] + len < dist[to]) {
				s.erase({dist[to], to});
				dist[to] = dist[v] + len;
				par[to] = v;
				s.insert({dist[to], to});
			}
		}
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({b, w});
	}

	int src = 1;
	dickstra(src);
	int val = 1e9;
	for (int i = 2; i <= n; i++) {
		if (dist[i] == -1)
			cout << val << " ";
		else
			cout << dist[i] << " ";
	}
	cout << endl;
}

signed main()
{
	crap;

	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
