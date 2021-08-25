// floyd_warshall -> N <= 500
void floyd_warshall(int n, int m) {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j) dis[i][j] = 0;
			else if (adj[i][j]) dis[i][j] = adj[i][j];
			else dis[i][j] = LLONG_MAX;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (dis[i][k] < LLONG_MAX and dis[k][j] < LLONG_MAX)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

}