class WordDictionary {
public:
    WordDictionary() {
        root = new Node();
    }

    ~WordDictionary()
    {
        DeleteAll(root);
    }
    
    void addWord(string word) {
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
            else
            {
                node = next;
            }
        }

        for (; index < length; ++index)
        {
            Node* newNode = new Node();
            node->children[word[index] - 'a'] = newNode;
            node = newNode;
        }

        node->wordEndHereExists = true;
    }
    
    bool search(string word) {
        return search_aux(root, word, 0);
    }

private:
    struct Node
    {
        Node* children[26] = { nullptr };
        bool wordEndHereExists = false;
    };
    Node* root;

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

    bool search_aux(Node* node, const string& word, int index)
    {
        const int length = word.length();
        const char c = word[index];
        
        if (index + 1 == length)
        {
            if (c == '.')
            {
                for (Node* child : node->children)
                {
                    if (child && child->wordEndHereExists)
                    {
                        return true;
                    }
                }

                return false;
            }

            Node* child = node->children[c - 'a'];
            return child && child->wordEndHereExists;
        }

        if (c == '.')
        {
            for (Node* child : node->children)
            {
                if (child && search_aux(child, word, index + 1))
                {
                    return true;
                }
            }

            return false;
        }

        node = node->children[c - 'a'];
        if (node)
        {
            return search_aux(node, word, index + 1);
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */