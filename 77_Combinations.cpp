class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<int> base(k);
        combine_rec(base, 0, n, k);
        return answer;
    }
    
private:
    void combine_rec(std::vector<int>& base, int depth, int n, int k)
    {
        if (k == 1)
        {
            for (int i = 1; i <= n; ++i)
            {
                base[depth] = i;
                answer.push_back(base);
            }
            
            return;
        }
        
        for (int i = n; i >= k; --i)
        {
            base[depth] = i;
            
            combine_rec(base, depth + 1, i - 1, k - 1);
        }
    }
    
private:
    std::vector<std::vector<int>> answer;
};