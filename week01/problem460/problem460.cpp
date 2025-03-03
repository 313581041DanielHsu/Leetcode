class LFUCache {
    int capacity;
    int minFreq;
    unordered_map<int,pair<int,int>> keyVal;
    unordered_map<int,list<int>> freqList;
    unordered_map<int,list<int>::iterator> pos;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {
        if(keyVal.find(key) == keyVal.end())
            return -1;
        freqList[keyVal[key].second].erase(pos[key]);
        keyVal[key].second++;
        freqList[keyVal[key].second].push_back(key);
        pos[key] = --freqList[keyVal[key].second].end();
        if(freqList[minFreq].empty())
            minFreq++;
        return keyVal[key].first;
    }
    
    void put(int key, int value) {
        if(!capacity)
            return;
        if(keyVal.find(key) != keyVal.end()) {
            keyVal[key].first = value;
            freqList[keyVal[key].second].erase(pos[key]);
            keyVal[key].second++;
            freqList[keyVal[key].second].push_back(key);
            pos[key] = --freqList[keyVal[key].second].end();
            if(freqList[minFreq].empty())
                minFreq++;
            return;
        }
        if(keyVal.size() == capacity) {
            int delKey = freqList[minFreq].front();
            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }
        keyVal[key] = {value,1};
        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();
        minFreq = 1;
    }
};

/*
使用 三個 unordered_map + list 來高效實現 O(1) 的 get() 和 put() 操作，確保我們可以：
快速找到 key 的 value 和 frequency
快速更新 key 的 frequency
快速刪除 LFU 的 key

📌 主要數據結構
變數名稱     類型	                                作用
keyVal	    unordered_map<int, pair<int, int>>	    存放 key → (value, frequency)
freqList	unordered_map<int, list<int>>	        存放 frequency → [keys]（按頻率分類的 key 清單）
pos	        unordered_map<int, list<int>::iterator>	存放 key → 在 freqList 內的 iterator（快速刪除 key）
minFreq	    int	                                    當前快取內的最小 frequency，方便 O(1) 找到 LFU key
capacity	int	                                    快取的最大容量


📌get(int key) 方法
操作步驟
如果 key 不存在，返回 -1。
刪除 key 在 freqList[frequency] 的舊位置。
增加 key 的 frequency，並把它插入 freqList[newFrequency] 的 尾部。
更新 pos[key]，記錄 key 在 freqList[newFrequency] 的新位置。
如果 freqList[minFreq] 空了，則 minFreq++（最小頻率遞增）。
返回 value。
📌 put(int key, int value) 方法
🔹 key 已存在
更新 value。
刪除 key 在 freqList[frequency] 的舊位置。
增加 key 的 frequency，並把它插入 freqList[newFrequency] 的 尾部。
更新 pos[key]，記錄 key 在 freqList[newFrequency] 的新位置。
如果 freqList[minFreq] 空了，則 minFreq++。
🔹 key 不存在
如果 cache 滿了，刪除 freqList[minFreq] 的最前面的 key（最少使用 & 最久未使用）。
新增 key，frequency = 1，插入 freqList[1]。
更新 pos[key]，記錄 key 在 freqList[1] 的新位置。
將 minFreq 設為 1（因為新插入的 key 頻率最小）。

*/
