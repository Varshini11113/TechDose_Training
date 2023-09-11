class MyHashMap {
public:
    vector<list<pair<int, int>>> hash;
    int size = 100000;
    MyHashMap() {
        hash.resize(size);
    }
    
    void put(int key, int value) {
        auto& ll = hash[key % size];
        for(auto& i : ll){
            if(i.first == key){
                i.second = value;
                return;
            }
        }
        ll.push_back({key, value});
    }
    
    int get(int key) {
        auto& ll = hash[key % size];
        for(auto& i : ll){
            if(i.first == key){
                return i.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        auto& ll = hash[key % size];
        for(auto& i : ll){
            if(i.first == key){
                ll.remove(i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */