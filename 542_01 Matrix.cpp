// Correct solution
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int height = mat.size();
        const int width = mat[0].size();
        
        std::vector<std::vector<int>> distances(height, std::vector<int>(width, -1));
        
        std::queue<std::pair<int, int>> q;

        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                if (mat[y][x] == 0)
                {
                    distances[y][x] = 0;
                    q.push(std::make_pair(x, y));
                }
            }
        }

        while (q.size())
        {
            const std::pair<int, int> pos = q.front();
            q.pop();

            const int newDistance = distances[pos.second][pos.first] + 1;

            for (int i = 0; i < 4; ++i)
            {
                const std::pair<int, int> neighbor = std::make_pair(pos.first + adjacent_x[i] , pos.second + adjacent_y[i]);

                if (neighbor.first < 0 || neighbor.second < 0 || neighbor.first >= width || neighbor.second >= height)
                {
                    continue;
                }

                if (distances[neighbor.second][neighbor.first] >= 0)
                {
                    continue;
                }

                distances[neighbor.second][neighbor.first] = newDistance;
                q.push(neighbor);
            }            
        }

        return distances;

    }

private:
    const int adjacent_x[4] = { 1, -1, 0, 0 };
    const int adjacent_y[4] = { 0, 0, 1, -1};
};

// Using priority queue which is unnecessary.
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int height = mat.size();
        const int width = mat[0].size();

        // Create a storage for nodes to record visited state and position.
        std::vector<std::vector<bool>> visited(height, std::vector<bool>(width, false));

        // Container for distances - will be used by the algorithm and returned as a result.
        std::vector<std::vector<int>> distances(height, std::vector<int>(width, 0));

        // Initialize the prioirty queue which compares distances.
        std::priority_queue<Node> openList;

        // Finds all 0s and pushes into the queue.
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                if (mat[y][x] == 0)
                {
                    Node node;
                    node.x = x;
                    node.y = y;
                    node.distance = 0;

                    openList.push(node);
                }
            }
        }

        // Traverse all nodes
        while (openList.size())
        {
            // Get a node from the queue.
            Node node = openList.top();
            openList.pop();

            // If the node is visited already, skip.
            if (visited[node.y][node.x])
            {
                continue;
            }

            // Mark this node is visited.
            visited[node.y][node.x] = true;

            // Record the result.
            distances[node.y][node.x] = node.distance;

            // Find a new distance from this node to neighbors.
            const int newDistance = node.distance + 1;

            // Check all 4 neighbors
            for (int i = 0; i < 4; ++i)
            {
                // Get the position of a neighbor.
                const int neighbor_x = node.x + adjacent_x[i];
                const int neighbor_y = node.y + adjacent_y[i];

                // Check if the position is valid.
                if (neighbor_x < 0 || neighbor_y < 0 || neighbor_x >= width || neighbor_y >= height)
                {
                    continue;
                }

                // If the neighbor is alreday visited, skip.
                if (visited[neighbor_y][neighbor_x])
                {
                    continue;
                }

                if (mat[neighbor_y][neighbor_x] == 0)
                {
                    continue;
                }

                Node neighbor;
                neighbor.x = neighbor_x;
                neighbor.y = neighbor_y;
                neighbor.distance = newDistance;

                // Add the neighbor to the open list.
                openList.push(neighbor);
            }
        }

        return distances;
    }

private:
    struct Node
    {
        int x;
        int y;

        int distance = std::numeric_limits<int>::max();

        bool operator<(const Node& node) const
        {
            return distance > node.distance;
        }
    };

    const int adjacent_x[4] = { 1, -1, 0, 0 };
    const int adjacent_y[4] = { 0, 0, 1, -1 };
};


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int height = mat.size();
        const int width = mat[0].size();

        // Create a storage for nodes to record visited state and position.
        std::vector<std::vector<Node>> nodes(height, std::vector<Node>(width));

        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                Node& node = nodes[y][x];

                node.x = x;
                node.y = y;
            }
        }

        // Container for distances - will be used by the algorithm and returned as a result.
        std::vector<std::vector<int>> distances(height, std::vector<int>(width, std::numeric_limits<int>::max()));

        // Initialize the prioirty queue which compares distances.
        auto compare = [&distances](Node* const node1, Node* const node2){ return distances[node1->y][node1->x] > distances[node2->y][node2->x]; };
        std::priority_queue<Node*, std::vector<Node*>, decltype(compare)> openList(compare);

        // Finds all 0s and pushes into the queue.
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < width; ++x)
            {
                if (mat[y][x] == 0)
                {
                    distances[y][x] = 0;
                    openList.push(&nodes[y][x]);
                }
            }
        }

        // Traverse all nodes
        while (openList.size())
        {
            // Get a node from the queue.
            Node* const node = openList.top();
            openList.pop();

            // If the node is visited already, skip.
            if (node->visited)
            {
                continue;
            }

            // Mark this node is visited.
            node->visited = true;

            // Find a new distance from this node to neighbors.
            const int newDistance = distances[node->y][node->x] + 1;

            // Check all 4 neighbors
            for (int i = 0; i < 4; ++i)
            {
                // Get the position of a neighbor.
                const int neighbor_x = node->x + adjacent_x[i];
                const int neighbor_y = node->y + adjacent_y[i];

                // Check if the position is valid.
                if (neighbor_x < 0 || neighbor_y < 0 || neighbor_x >= width || neighbor_y >= height)
                {
                    continue;
                }

                // Get the neighbor node.
                Node* const neighbor = &nodes[neighbor_y][neighbor_x];

                // If the neighbor is alreday visited, skip.
                if (neighbor->visited)
                {
                    continue;
                }

                // Updates the neighbor if and only if the new distance is better.
                if (newDistance < distances[neighbor_y][neighbor_x])
                {
                    // Set the new distance for this neighbor.
                    distances[neighbor_y][neighbor_x] = newDistance;

                    // Add the neighbor to the open list.
                    openList.push(neighbor);
                }
            }
        }

        return distances;
    }

private:
    struct Node
    {
        int x;
        int y;
        
        bool visited = false;
    };

    const int adjacent_x[4] = { 1, -1, 0, 0 };
    const int adjacent_y[4] = { 0, 0, 1, -1 };
};