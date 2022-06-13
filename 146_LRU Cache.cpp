class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (table.find(key) == table.end())
        {
            return -1;
        }
        
        const int value = table[key]->second;
        
        queue.erase(table[key]);
        queue.push_back(std::make_pair(key, value));
        table[key] = --queue.end();
        
        return value;
    }
    
    void put(int key, int value) {
        auto itr = table.find(key);
        
        if (itr == table.end())
        {
            if (queue.size() == capacity)
            {
                table.erase(table.find(queue.front().first));
                queue.pop_front();
            }
        }
        else // exists
        {
            queue.erase(table[key]);
        }
        
        queue.push_back(std::make_pair(key, value));
        table[key] = --queue.end();
    }
    
private:
    std::list<std::pair<int, int>> queue;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> table;
    
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */