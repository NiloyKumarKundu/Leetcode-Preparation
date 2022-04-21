// For key > 1e7


class MyHashSet {
public:
    vector<list<int>> s;
    int size;
    
    MyHashSet() {
        size = 100;         // we can reduce size because collution will be occur other value goes to the linked list.
        s.resize(size);
    }
    
    int hash(int key) {
        return key % size;
    }
    
    list<int>::iterator search(int key) {
        int i = hash(key);
        return find(s[i].begin(), s[i].end(), key);
    }
    
    void add(int key) {
        if (contains(key))
            return;
        int i = hash(key);
        s[i].push_back(key);
    }
    
    void remove(int key) {
        if (!contains(key))
            return;
        int i = hash(key);
        s[i].erase(search(key));
    }
    
    bool contains(int key) {
        int i = hash(key);
        if (search(key) != s[i].end()) 
            return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */





// Original Solution
class MyHashSet {
public:
    vector<int> s;
    int size;
    
    MyHashSet() {
        size = 1e6 + 2;
        s.resize(size);
    }
    
    void add(int key) {
        s[key] = 1;
    }
    
    void remove(int key) {
        s[key] = 0;
    }
    
    bool contains(int key) {
        return s[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */