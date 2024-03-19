class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        height = grid.size();
        width = grid[0].size();

        int islands = 0;

        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                if (grid[y][x] == '1')
                {
                    ExploreAnIsland(grid, std::make_pair(x, y));
                    ++islands;
                }
            }
        }

        return islands;
    }

private:
    void ExploreAnIsland(std::vector<std::vector<char>>& grid, const std::pair<int, int>& pos)
    {
        std::stack<std::pair<int, int>> lands;
        lands.push(pos);

        while (lands.size())
        {
            const std::pair<int, int> land = lands.top();
            lands.pop();

            for (int i = 0; i < 4; ++i)
            {
                const std::pair<int, int> neighbor = std::make_pair(land.first + adjacent_x[i], land.second + adjacent_y[i]);

                if (neighbor.first >= 0 && neighbor.first < width && neighbor.second >= 0 && neighbor.second < height)
                {
                    if (grid[neighbor.second][neighbor.first] == '1')
                    {
                        lands.push(neighbor);
                    }
                }
            }

            grid[land.second][land.first] = '0';
        }
    }

    const int adjacent_x[4] = { 1, 0, -1, 0 };
    const int adjacent_y[4] = { 0, 1, 0, -1 };

    int width;
    int height;
};