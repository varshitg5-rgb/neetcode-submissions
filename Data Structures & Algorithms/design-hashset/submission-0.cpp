class MyHashSet {
public:
    vector<vector<bool>> v{1000, vector<bool>(1000,false)};
    MyHashSet() {
        
    }
    
    void add(int key) {
        v[key/1000][key%1000] = true;
    }
    
    void remove(int key) {
        v[key/1000][key%1000] = false;
    }
    
    bool contains(int key) {
        return v[key/1000][key%1000];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */