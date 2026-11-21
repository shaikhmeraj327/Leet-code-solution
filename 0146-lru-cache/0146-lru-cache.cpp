class LRUCache {
public:
    list<int>dll;
    int n;
    unordered_map<int,pair<list<int>::iterator,int>>map;


    LRUCache(int capacity) {
        this->n=capacity;
    }
    
    int get(int key) {
        if(map.find(key)!=map.end()){
            int val=map[key].second;
            dll.erase(map[key].first);
            dll.push_front(key);
            map[key].first=dll.begin();
            return val;
        }
        return -1;
        
    }
    
    void put(int key, int value) {
        if(map.find(key)!=map.end()){
            map[key].second=value;
            dll.erase(map[key].first);
            dll.push_front(key);
            map[key].first=dll.begin();
            return;
        }
        dll.push_front(key);
        map[key].first=dll.begin();
        map[key].second=value;
        n--;
        if(n<0){
            int oldKey=dll.back();
            dll.pop_back();
            map.erase(oldKey);
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */