class MyHashMap {
public:
        //creating the hash table
        vector<list<pair<int, int>>> table;
        int tableSize = 10000;
    MyHashMap() {
        table.resize(tableSize);
    }
    
    void put(int key, int value) {
        //pointing to the index (linkedList)
        auto& chain = table[key % tableSize];
        for(auto& i : chain){
            if(i.first == key){
                i.second = value;
                return;
            }
        }
        chain.push_back({key, value});
    }
    
    int get(int key) {
        auto& chain = table[key % tableSize];
        for(auto& i : chain){
            if(i.first == key){
                return i.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        auto& chain = table[key % tableSize];
        for(auto& i : chain){
            if(i.first == key){
                chain.remove(i);
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