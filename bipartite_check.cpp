class Solution {
public:
	bool dfs(const vector<vector<int>>& adj, vector<int>& visited,  vector<int>& color , int v, int c) {
		visited[v] = 1;
		color[v] = c;

		for (auto child : adj[v]) {
			if (!visited[child])
				return dfs(adj, visited, color, child, c ^ 1);
			else
				return (color[child] == color[v]);
		}
		return true;
	}
	bool isBipartite(vector<vector<int>>& adj) {
		int nodes = adj.size();
		vector<int> visited(nodes, 0);// false
		vector<int> color(nodes, -1);// no color
		bool is_bipartite = true;

		for (int i = 0; i < nodes; i++) {
			if (!visited[i])
				is_bipartite = is_bipartite & dfs(adj, visited, color, i, 1);

		}
		for (int i = 0; i < nodes; i++)
			cout << color[i] << endl;

		return is_bipartite;
	}
};
