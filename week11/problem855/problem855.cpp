class ExamRoom {
public:
    int N; // 座位總數
    set<int> seats; // 已有人坐的座位

    ExamRoom(int n) {
        N = n;
    }

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        int prev = -1;
        int maxDist = 0;
        int pos = 0;

        for (int s : seats) {
            if (prev == -1) {
                // 考慮最左邊
                if (s != 0 && s > maxDist) {
                    maxDist = s;
                    pos = 0;
                }
            } else {
                // 中間距離
                int dist = (s - prev) / 2;
                if (dist > maxDist) {
                    maxDist = dist;
                    pos = prev + dist;
                }
            }
            prev = s;
        }

        // 考慮最右邊
        if (N - 1 - *seats.rbegin() > maxDist) {
            pos = N - 1;
        }

        seats.insert(pos);
        return pos;
    }

    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
