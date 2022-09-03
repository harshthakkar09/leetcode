class LRUCache {
public:
    class Node{
    public:
        int key;
        int val;
        Node* pre;
        Node* next;
        
        Node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    
    
    int cap;
    unordered_map<int, Node*> track;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->pre = head;
    }
    
    void deleteNode(Node* node){
        Node* preNode = node->pre;
        Node* nextNode = node->next;
        preNode->next = nextNode;
        nextNode->pre = preNode;
    }
    
    void addNode(Node* node){
        Node* headNext = head->next;
        node->next =headNext;
        node->pre = head;
        head->next = node;
        headNext->pre = node;
    }
    
    int get(int key) {
        if(track.find(key) != track.end()){
            Node* node = track[key];
            int val = node->val;
            track.erase(key);
            deleteNode(node);
            addNode(node);
            track[key] = head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(track.find(key) != track.end()){
            Node* exisitingNode = track[key];
            deleteNode(exisitingNode);
            track.erase(key);
        }
        if(track.size() == cap){
            track.erase(tail->pre->key);
            deleteNode(tail->pre);
        }
        addNode(new Node(key, value));
        track[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */