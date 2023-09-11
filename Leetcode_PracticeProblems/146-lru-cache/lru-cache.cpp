class LRUCache {
public:
    list<pair<int,int>>cache;
    unordered_map<int, list<pair<int,int>>::iterator> map;
   
    void refresh(int key, int value){
        cache.erase(map[key]);
        cache.push_front(make_pair(key, value));
        map[key] = cache.begin();
    }
     int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(map.find(key) != map.end()){
            refresh(key, (*map[key]).second);
            return (*map[key]).second;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(map.find(key) != map.end()){
            refresh(key, value);
        }
        else{
            cache.push_front(make_pair(key, value));
            map[key] = cache.begin();
        if(map.size() > capacity){
            map.erase(cache.back().first);
            cache.pop_back();
        }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */