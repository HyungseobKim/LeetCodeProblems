class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        const int targetColor = image[sr][sc];
        if (targetColor == color)
        {
            return image;
        }

        const int height = image.size();
        const int width = image[0].size();

        std::stack<std::pair<int, int>> connectedPixels;
        connectedPixels.push(std::make_pair(sr, sc));

        while (connectedPixels.size())
        {
            const std::pair<int, int> pixel = connectedPixels.top();
            connectedPixels.pop();

            for (int i = 0; i < 4; ++i)
            {
                const std::pair<int, int> neighbor = std::make_pair(pixel.first + adjacent_sr[i] , pixel.second + adjacent_sc[i]);

                if (neighbor.first >= 0 && neighbor.second >= 0 &&
                    neighbor.first < height && neighbor.second < width)
                {
                    if (image[neighbor.first][neighbor.second] == targetColor)
                    {
                        connectedPixels.push(neighbor);
                    }
                }
            }

            image[pixel.first][pixel.second] = color;
        }

        return image;
    }

private:
    int adjacent_sr[4] = { 0, 1, 0, -1 };
    int adjacent_sc[4] = { 1, 0, -1, 0 };
};