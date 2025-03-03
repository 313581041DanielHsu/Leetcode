class LRUCache {
public:
    class Node{
        public:
            int key, value;
            Node* next, *prev;
            Node(int key, int value){
                this->key = key;
                this->value = value;
                next = NULL;
                prev = NULL;
            }
    };

    int capacity;
    unordered_map<int, Node*>mp;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node){
        Node* temp = head->next;
        head->next = node;
        node->prev = head; 

        node->next = temp;
        temp->prev = node;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        else{
            Node* currNode = mp[key];
            deleteNode(currNode);
            insertAtHead(currNode);
            return currNode->value;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* currNode = mp[key];
            currNode->value = value; 
            deleteNode(currNode);
            insertAtHead(currNode);
        }
        else{
            Node* newNode = new Node(key, value);
            if(mp.size() == capacity){
                Node* todel = tail->prev;
                mp.erase(todel->key);
                deleteNode(tail->prev);
                insertAtHead(newNode);
                mp[key]  = newNode;
                delete todel;
            }
            else{
                insertAtHead(newNode);
                mp[key] = newNode;
            }
        }
    }
};

/*
使用 雙向鏈表 (Doubly Linked List) + 哈希表 (unordered_map) 來實作 最近最少使用 (LRU) 快取，確保 get() 和 put() 操作皆為 O(1) 時間複雜度。
 1. 透過 Node 類別設計雙向鏈表
你設計了一個 雙向鏈表 (Node class)，每個節點包含：

key：儲存快取的鍵
value：儲存快取的值
next：指向下一個節點
prev：指向前一個節點
Node 節點的結構
2. 使用 head 和 tail 作為 dummy 節點
head 指向最近使用的節點（最左邊）。
tail 指向最久未使用的節點（最右邊）。
初始化時，head->next = tail，tail->prev = head，確保雙向鏈表有效運作。
3. 使用 unordered_map<int, Node*> mp 來快取 key 到 Node* 的映射
unordered_map 讓 get() 和 put() 查找 key 的操作是 O(1) 時間複雜度。
mp[key] 指向 Node*，這樣我們可以快速找到 key 對應的 Node，並直接進行刪除或移動操作。
deleteNode(Node* node)
4.insertAtHead(Node* node)
當 key 被存取時，需要將該 Node 從原位置刪除，並重新插入 head，這樣確保最近存取的數據保留在鏈表最前面。
5.get(int key)
當 key 存在時：
透過 mp[key] 快速找到 Node*
將 Node* 移動到 head（表示最近使用）
返回 value
6.put(int key, int value)
當 key 已經存在：

透過 mp[key] 取得 Node*
更新 value
刪除 Node，並將其移動到 head
*/
