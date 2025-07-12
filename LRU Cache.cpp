class LRUCache {
private:
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    list<int> order;
    int capacity;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    // LRUCache(int capacity) : capacity(capacity) {}
    
    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = --order.end();// prev(order.end());
        return cache[key].first;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            order.erase(cache[key].second);
            // Update value and move to back
        } else if (cache.size() == capacity) {
            // Remove least recently used item
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};// prev(order.end())
    }
};