class Trie {
public:
    Trie() {
        root = new Node;
    }

    ~Trie()
    {
        DeleteAll(root);
    }
    
    void insert(string word) {
        const int length = word.length();

        Node* node = root;
        int index = 0;

        for (; index < length; ++index)
        {
            Node* next = node->children[word[index] - 'a'];
            
            if (next == nullptr)
            {
                break;
            }

            node = next;
        }

        for (; index < length; ++index)
        {
            Node* newNode = new Node;

            node->children[word[index] - 'a'] = newNode;

            node = newNode;
        }

        node->isEndOfWord = true;
    }
    
    bool search(string word) {
        const int length = word.length();

        Node* node = root;

        for (int i = 0; i < length; ++i)
        {
            Node* next = node->children[word[i] - 'a'];
            
            if (next == nullptr)
            {
                return false;
            }

            node = next;
        }

        return node->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        const int length = prefix.length();

        Node* node = root;

        for (int i = 0; i < length; ++i)
        {
            Node* next = node->children[prefix[i] - 'a'];
            
            if (next == nullptr)
            {
                return false;
            }

            node = next;
        }

        return true;
    }

private:
    struct Node
    {
        Node* children[26] = { nullptr };

        bool isEndOfWord = false;
    };

    void DeleteAll(Node* node)
    {
        for (Node* child : node->children)
        {
            if (child)
            {
                DeleteAll(child);
            }
        }

        delete node;
    }

    Node* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */