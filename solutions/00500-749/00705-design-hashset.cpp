// https://leetcode.com/problems/design-hashset/
// 705. Design HashSet
// implement a hash set
class MyHashSet {
private:
    int prime;
    vector<list<int>> buckets;
    
    int getHashKey(int val) {
        return val % prime;
    }
    
public:
    MyHashSet() : prime(10099), buckets(prime+1) {
    }
    
    void add(int key) {
        int hk = getHashKey(key);
        list<int>* entries = &buckets[hk];
        list<int>::iterator it;
        
        it = find(entries->begin(), entries->end(), key);
        if (it == entries->end()) {
            entries->push_back(key);
        }
    }
    
    void remove(int key) {
        int hk = getHashKey(key);
        list<int>::iterator it;
        list<int>* entries = &buckets[hk];
        
        it = find(entries->begin(), entries->end(), key);
        if (it != entries->end()) {
            entries->erase(it);
        }
    }
    
    bool contains(int key) {
        bool result = false;
        int hk = getHashKey(key);
        list<int>::iterator it;
        list<int>* entries = &buckets[hk];
        
        it = find(entries->begin(), entries->end(), key);
        if (it != entries->end()) {
            result = true;
        }
        
        return result;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

/*
// https://leetcode.com/problems/design-hashset/
// 705. Design HashSet
// version using a vector without hashing the key
class MyHashSet {
private:
    //vector<bool> h = vector<bool>(1000001, false);
    vector<bool> h;
public:
    MyHashSet() : h(1000001, false) {
    }
    
    void add(int key) {
        h[key] = true;
    }
    
    void remove(int key) {
        h[key] = false;
    }
    
    bool contains(int key) {
        return h[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
*/