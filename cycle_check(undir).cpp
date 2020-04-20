// main
for (int i = 1; i <= n; i++) {
	if (!vis[i]) {
		if (dfs(i, -1, vis))
			return true;
	}

	return false;
}

// dfs
bool dfs(int v, int par, vi& vis) {
	vis[v] = true;

	for (auto child : adj[v]) {
		if (!vis[child]) {
			if (dfs(child, v, vis))
				return true;
		} else if (child != par)
			return true;
	}

	return false;
}
