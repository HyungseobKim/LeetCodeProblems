struct Node
{
    bool visited = false;
    int num = 0;
};

class Solution {
public:    
    int numIslands(vector<vector<char>>& grid) {
        height = grid.size();
        width = grid[0].size();
        
        nodes = std::vector<Node>(width * height);
        
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                ProcessNode(grid, x, y);
            }
        }
        
        return islands;
    }

private:
    void ProcessNode(const std::vector<std::vector<char>>& grid, int x, int y)
    {
        const int index = y * width + x;
        Node& node = nodes[index];
        
        if (node.visited == true)
        {
            return;
        }
        
        node.visited = true;
        
        if (grid[y][x] == '0')
        {
            return;
        }
        
        if (node.num == 0)
        {
            node.num = ++islands;
        }

        if (x - 1 >= 0)
        {
            nodes[index - 1].num = node.num;
            ProcessNode(grid, x - 1, y);
        }
        
        if (x + 1 < width)
        {
            nodes[index + 1].num = node.num;
            ProcessNode(grid, x + 1, y);
        }

        if (y - 1 >= 0)
        {
            nodes[index - width].num = node.num;
            ProcessNode(grid, x, y - 1);
        }
        
        if (y + 1 < height)
        {
            nodes[index + width].num = node.num;
            ProcessNode(grid, x, y + 1);
        }
    }
    
private:
    int width;
    int height;
    
    std::vector<Node> nodes;
    
    int islands = 0;
};