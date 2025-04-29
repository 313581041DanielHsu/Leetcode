class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1), candA, candB;
        for (int i = 1; i <= n; ++i) parent[i] = i;

        vector<int> realParent(n + 1, 0);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (realParent[v] == 0) {
                realParent[v] = u;
            } else {
                candA = {realParent[v], v};
                candB = {u, v};
                edge[1] = 0;  
            }
        }

        for (int i = 1; i <= n; ++i) parent[i] = i;

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            if (v == 0) continue; 

            int pu = find(parent, u);
            if (pu == v) {
                return candA.empty() ? edge : candA;
            }
            parent[v] = pu;
        }
        return candB;
    }

private:
    int find(vector<int>& parent, int x) {
        if (parent[x] != x) parent[x] = find(parent, parent[x]);
        return parent[x];
    }
};

