class AllOne {
public:
    AllOne() {
        
    }
    
    void inc(string key) {
        if (strings.contains(key))
        {
            int num = strings[key];
            table[num].erase(key);

            if (table[num].empty())
            {
                table.erase(table.find(num));
            }

            ++num;

            if (table.contains(num) == false)
            {
                table[num] = std::unordered_set<std::string>();
            }

            table[num].insert(key);
            strings[key] = num;
        }
        else
        {
            strings[key] = 1;

            if (table.contains(1) == false)
            {
                table[1] = std::unordered_set<std::string>();
            }

            table[1].insert(key);
        }
    }
    
    void dec(string key) {
        int num = strings[key];
        table[num].erase(key);

        if (table[num].empty())
        {
            table.erase(table.find(num));
        }

        --num;

        if (num > 0)
        {
            if (table.contains(num) == false)
            {
                table[num] = std::unordered_set<std::string>();
            }

            table[num].insert(key);
            strings[key] = num;
        }
        else
        {
            strings.erase(strings.find(key));
        }
    }
    
    string getMaxKey() {
        if (table.empty())
        {
            return "";
        }

        return *(table.rbegin()->second.begin());
    }
    
    string getMinKey() {
        if (table.empty())
        {
            return "";
        }

        return *(table.begin()->second.begin());
    }

private:
    std::unordered_map<std::string, int> strings;
    std::map<int, std::unordered_set<std::string>> table;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */