class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
            prev = nullptr;
            next = nullptr;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int cap;
    map<int, Node*> mp;

    void insetAfterHead(Node* newNode) {
        Node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }

    void deleteNode(Node* delNode) {
        Node* delPrev = delNode->prev;
        Node* delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* resNode = mp[key];
            int res = resNode->val;
            deleteNode(resNode);
            insetAfterHead(resNode);
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->val = value;
            deleteNode(node);
            insetAfterHead(node);
        } else {
            if (mp.size() == cap) {
                Node* beforeTail = tail->prev;
                deleteNode(beforeTail);
                mp.erase(beforeTail->key);
            }
            Node* newNode = new Node(key, value);
            insetAfterHead(newNode);
            mp[key] = newNode;
        }
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */