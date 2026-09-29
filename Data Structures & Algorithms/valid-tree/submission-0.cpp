class Solution {
public:
    vector<bool> visited;
    bool dfs(int v, int p, vector<vector<int>>& adj) {
        visited[v] = true;
        for (int u : adj[v]) {
            if (u == p) continue;
            if (visited[u]) return false;
            if (!dfs(u, v, adj)) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1) return false;
        vector<vector<int>> adj(n);
        visited.assign(n, false);
        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if (!dfs(0, -1, adj)) return false;
        for (int i = 0; i < n; i++) if (!visited[i]) return false;
        return true;
    }
};
