class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int size = points.size();

        auto compare = [](std::vector<int>* p1, std::vector<int>* p2){ return (*p1)[2] > (*p2)[2]; };
        std::priority_queue<std::vector<int>*, std::vector<std::vector<int>*>, decltype(compare)> q(compare);
        
        for (std::vector<int>& point : points)
        {
            point.push_back(point[0]*point[0] + point[1]*point[1]);
            q.push(&point);
        }

        std::vector<std::vector<int>> closePoints(k, std::vector<int>(2));

        for (int i = 0; i < k; ++i)
        {
            std::vector<int>* point = q.top();
            q.pop();

            closePoints[i][0] = (*point)[0];
            closePoints[i][1] = (*point)[1];
        }

        return closePoints;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        const int size = points.size();
        
        for (std::vector<int>& point : points)
        {
            point.push_back(point[0]*point[0] + point[1]*point[1]);
        }

        int last = size - 1;
        
        int numClosest = 0;
        int numClose = 0;

        while (numClose != k)
        {
            const int standard = points[last][2];
            
            int change = numClosest;

            for (int i = numClosest; i < last; ++i)
            {
                if (points[i][2] <= standard)
                {
                    std::swap(points[change], points[i]);
                    ++change;
                }
            }

            std::swap(points[change], points[last]);
            ++change;

            numClose = change;
            
            if (numClose < k)
            {
                numClosest = change;
            }
            else if (numClose > k)
            {
                if (change >= last)
                {
                    --last;
                }
                else
                {
                    last = numClose;
                }
                
                numClose = numClosest;
            }            
        }

        std::vector<std::vector<int>> closePoints(k, std::vector<int>(2));
        for (int i = 0; i < k; ++i)
        {
            closePoints[i][0] = points[i][0];
            closePoints[i][1] = points[i][1];
        }

        return closePoints;
    }
};