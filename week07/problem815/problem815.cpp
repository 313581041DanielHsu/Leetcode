class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0; // 如果起點就是終點，則返回 0

        // 建立從巴士站到巴士路線的映射
        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); i++) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);  // 每個站點對應所有經過這個站的路線
            }
        }

        // 用 BFS 來搜索最短的巴士路線數
        queue<int> q;  // 用來存儲當前巴士路線的索引
        unordered_set<int> visitedStops;  // 用來標記已經訪問過的巴士站
        unordered_set<int> visitedRoutes;  // 用來標記已經訪問過的巴士路線

        // 初始化
        q.push(source);
        visitedStops.insert(source);
        int buses = 0;

        // BFS 開始
        while (!q.empty()) {
            buses++;
            int size = q.size();

            for (int i = 0; i < size; i++) {
                int currentStop = q.front();
                q.pop();

                // 查找經過 currentStop 的所有巴士路線
                for (int routeIndex : stopToRoutes[currentStop]) {
                    if (visitedRoutes.count(routeIndex)) continue;  // 已經訪問過這條路線，跳過

                    // 標記路線為已訪問
                    visitedRoutes.insert(routeIndex);

                    // 將這條路線上所有的站點加入隊列
                    for (int nextStop : routes[routeIndex]) {
                        if (nextStop == target) return buses;  // 如果找到目標站點，返回步數
                        if (!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
    }
};
