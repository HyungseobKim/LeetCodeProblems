class RandomizedSet {
public:
    RandomizedSet() {
        std::random_device rnd;
        rng = std::mt19937(rnd());
    }
    
    bool insert(int val) {
        if (table.find(val) != table.end())
        {
            // present
            return false;
        }
        
        // Insert "val" and store the index.
        numbers.push_back(val);
        table[val] = numbers.size() - 1;
        
        return true;
    }
    
    bool remove(int val) {
        auto itr = table.find(val);
        
        if (itr == table.end())
        {
            // not present
            return false;
        }
        
        // Move the last element to the position of "val".
        const int last = numbers.back();
        table[last] = table[val];
        numbers[table[val]] = last;
        
        // Remove "val".
        numbers.pop_back();
        table.erase(itr);
        
        return true;
    }
    
    int getRandom() {
        std::uniform_int_distribution<std::mt19937::result_type> dist(0, numbers.size() - 1);
        
        return numbers[dist(rng)];
    }

private:
    std::vector<int> numbers;
    std::unordered_map<int, int> table;
    
    std::mt19937 rng;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */