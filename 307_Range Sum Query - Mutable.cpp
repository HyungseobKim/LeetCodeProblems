class NumArray
{
public:
    NumArray(vector<int>& nums)
        : size(nums.size()) 
    {
        data = std::vector<int>(size);
        
        for (int i = 0; i < size; ++i)
            data[i] = 0;
        
        tree = std::vector<int>(size+1);
        
        for (int i = 1; i <= size; ++i)
            tree[i] = 0;
        
        for (int i = 0; i < size; ++i)
            update(i, nums[i]);
    }
    
    void update(int index, int val)
    {
        int offset = val - data[index];
        data[index] = val;
        
        ++index;
        
        while (index <= size)
        {
            tree[index] += offset;
            index = GetNext(index);
        }
    }
    
    int sumRange(int left, int right)
    {
        return GetSum(right) - GetSum(left-1);
    }
    
private:
    int GetParent(int i) const
    {
        return i - (i & (-i));
    }
    
    int GetNext(int i) const
    {
        return i + (i & (-i));
    }
    
    int GetSum(int index) const
    {
        int sum = 0;
        ++index;
        
        while (index > 0)
        {
            sum += tree[index];
            index = GetParent(index);
        }
            
        return sum;
    }
    
private:
    std::vector<int> data;
    std::vector<int> tree;
    const int size;
};