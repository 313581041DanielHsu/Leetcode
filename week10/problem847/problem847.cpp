class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<pair<int, int>> q; 
        vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i});
            visited[i][1 << i] = true;
        }

        int steps = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [node, state] = q.front();
                q.pop();

                if (state == (1 << n) - 1) return steps;

                for (int neighbor : graph[node]) {
                    int nextState = state | (1 << neighbor);
                    if (!visited[neighbor][nextState]) {
                        visited[neighbor][nextState] = true;
                        q.push({neighbor, nextState});
                    }
                }
            }
            steps++;
        }

        return -1; 
    }
};
