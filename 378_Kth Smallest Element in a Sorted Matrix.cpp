struct Node
{
    int num;
    std::pair<int, int> pos;
    
    bool openList = false;
    bool closeList = false;
};

struct Comparator
{
    bool operator()(const Node* lhs, const Node* rhs)
    {
        return lhs->num > rhs->num;
    }
};

class NodePool
{
public:
    ~NodePool()
    {
        for (auto& node : nodes)
        {
            delete node.second;
        }
    }
    
    Node* GetNode(std::pair<int, int> pos)
    {
        if (nodes.find(pos) == nodes.end())
        {
            Node* node = new Node();
            node->pos = pos;
            
            nodes[pos] = node;
        }
        
        return nodes[pos];
    }
    
private:
    std::map<std::pair<int, int>, Node*> nodes;
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        Node* node = nodePool.GetNode(std::make_pair(0, 0));
        node->num = matrix[0][0];
        node->openList = true;
        
        queue.push(node);
        
        for (int i = 1; i < k; ++i)
        {
            node = queue.top();
            queue.pop();
            node->closeList = true;
            
            const int row = node->pos.first;
            const int col = node->pos.second;
            
            PushNodeToQueue(matrix, std::make_pair(row + 1, col));
            PushNodeToQueue(matrix, std::make_pair(row, col + 1));
        }
            
        return queue.top()->num;
    }
    
private:
    void PushNodeToQueue(const std::vector<std::vector<int>>& matrix, const std::pair<int, int>& pos)
    {
        const int size = matrix.size();
        
        if (pos.first >= size || pos.second >= size)
        {
            return;
        }
        
        Node* node = nodePool.GetNode(pos);
        
        if (node->closeList || node->openList)
        {
            return;   
        }
        
        node->num = matrix[pos.first][pos.second];
        node->openList = true;
        
        queue.push(node);
    }
    
private:
    NodePool nodePool;
    std::priority_queue<Node*, std::vector<Node*>, Comparator> queue;
};