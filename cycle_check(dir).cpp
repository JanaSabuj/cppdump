class Solution {
public:

    bool dfs(int v, vector<int>& color,  const vector<vector<int>>& adj) {

        color[v] = 1; // gray
        for (auto u : adj[v]) {
            if (color[u] == 0) {
                if (dfs(u, color, adj))
                    return true;
            } else {
                if (color[u] == 1)
                    return true;
            }
        }

        color[v] = 2;
        return false;
    }

    bool canFinish(int n, vector<vector<int>>& prereqs) {
        vector<vector<int>> adj(n);
        for (auto edge : prereqs) {
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n, 0);

        bool ans = true;

        for (int i = 0; i < n; i++) {
            if (color[i] == 0 and dfs(i, color, adj))
                return false;
        }

        return true;
    }
};
