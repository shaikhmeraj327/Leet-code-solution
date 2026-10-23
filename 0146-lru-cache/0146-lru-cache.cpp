class LRUCache {
public:
    list<int>dll;
    unordered_map<int,pair<list<int>::iterator,int>>map;// <key,<add,value>>
    int n;

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
            dll.erase(map[key].first);
            dll.push_front(key);
            map[key].first=dll.begin();
            map[key].second=value;
            return;

        }
        dll.push_front(key);
        map[key].first=dll.begin();
        map[key].second=value;
        n--;
        if(n<0){
            int oldKey=dll.back();
            dll.pop_back();
            map.erase(oldKey);n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

//  class LRUCache {
// public:
//     vector<pair<int,int>>cache;
//     int n;

//     LRUCache(int capacity) {
//         this->n=capacity;
//     }
    
//     int get(int key) {
//         for(int i=0;i<cache.size();i++){
//             if(cache[i].first==key){
//                 int val=cache[i].second;
//                 cache.erase(cache.begin()+i);
//                 cache.push_back({key,val});
//                 return val;
//             }
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         for(int i=0;i<cache.size();i++){
//             if(cache[i].first==key){
//                 cache.erase(cache.begin()+i);
//                 cache.push_back({key,value});
//                 return;
//             }
//         }
//         if(cache.size()==n){
//             cache.erase(cache.begin());
//             cache.push_back({key,value});
//             return;
//         }
//         cache.push_back({key,value});
//     }
// };