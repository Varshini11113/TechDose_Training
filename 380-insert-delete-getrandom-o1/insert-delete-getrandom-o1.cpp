class RandomizedSet {
public:
    unordered_set<int>random;
    RandomizedSet() {
        // size = 1000;
    }
    
    bool insert(int val) {
        if(random.find(val) == random.end()){
            random.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(random.find(val) == random.end()){
            return false;
        }
        random.erase(val);    
        return true;
    }
    
    int getRandom() {
        auto it = random.begin();
        int num = rand() % random.size();
        while(num--) it++;
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */