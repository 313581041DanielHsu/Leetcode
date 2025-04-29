class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 建圖 + 計算入度
        vector<vector<int>> graph(numCourses);  // 鄰接表
        vector<int> indegree(numCourses, 0);    // 入度陣列

        // 初始化圖與入度
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            graph[prereq].push_back(course); // prereq → course
            indegree[course]++;
        }

        // 把所有入度為 0 的課程先加入 queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> result;

        // 開始 BFS 拓撲排序
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            result.push_back(course);

            for (int next : graph[course]) {
                indegree[next]--; // 這門課少了一個先修條件
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        // 檢查是否能修完所有課程
        if (result.size() == numCourses) {
            return result;
        } else {
            return {}; // 有循環，無法完成所有課程
        }
    }
};

