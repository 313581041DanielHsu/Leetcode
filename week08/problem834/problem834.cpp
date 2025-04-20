class Solution {
public:
    vector<vector<int>> tree;     // 鄰接表：存圖
    vector<int> res;              // 每個節點的答案（距離總和）
    vector<int> count;            // 每個節點的子樹節點數（包含自己）
    int N;

    // 第一次 DFS：計算 res[0]（以 0 為根），以及每個節點的子樹節點數
    void postOrder(int node, int parent) {
        for (int child : tree[node]) {
            if (child == parent) continue; // 避免往回走

            postOrder(child, node);

            count[node] += count[child];
            res[node] += res[child] + count[child];
        }
    }

    // 第二次 DFS：根據 res[parent] 推 res[child]
    void preOrder(int node, int parent) {
        for (int child : tree[node]) {
            if (child == parent) continue;

            // 公式：從 parent 向下轉移
            res[child] = res[node] - count[child] + (N - count[child]);

            preOrder(child, node);
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        tree.resize(n);
        res.resize(n, 0);
        count.resize(n, 1); // 每個節點初始為自己，數量為 1

        // 建圖（無向圖）
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        // 第一次 DFS：先求出 root 的總距離和（res[0]）
        postOrder(0, -1);

        // 第二次 DFS：從 root 推出其他節點的答案
        preOrder(0, -1);

        return res;
    }
};

