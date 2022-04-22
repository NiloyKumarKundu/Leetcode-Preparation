class MyHashMap {
public:
    vector<list<pair<int, int>>> mp;
    int size;
    MyHashMap() {
        size = 100;
        mp.resize(size);
    }
    
    int hash(int key) {
        return key % size;
    }
    
    list<pair<int, int>>::iterator search(int key) {
        int i = hash(key);
        
        list<pair<int, int>>::iterator it = mp[i].begin();
        
        while (it != mp[i].end()) {
            if (it->first == key) {
                return it;
            }
            ++it;
        }
        return it;
    }
     
    void put(int key, int value) {
        int i = hash(key);
        remove(key);
        mp[i].push_back({key, value});
    }
    
    int get(int key) {
        int i = hash(key);
        list<pair<int, int>>::iterator it = search(key);
        
        if (it == mp[i].end()) {
            return -1;
        }
        return it->second;
    }
    
    void remove(int key) {
        int i = hash(key);
        list<pair<int, int>>::iterator it = search(key);
        
        if (it != mp[i].end())
            mp[i].erase(it);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */







class MyHashMap {
public:
    vector<int> mp;
    int size;
    MyHashMap() {
        size = 1e6 + 2;
        mp.resize(size, -1);
    }
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        return mp[key];
    }
    
    void remove(int key) {
        mp[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */