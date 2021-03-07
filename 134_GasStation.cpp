class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        const int size = static_cast<int>(gas.size());
        
        int tank = 0;
        int index = 0;
        
        for (int i = size-1; i >= 0 && i >= index; --i)
        {
            int gain = gas[i] - cost[i];
            tank += gain;
            
            if (gain >= 0 && tank >= 0)
            {
                while (tank >= 0 && index < i)
                {
                    tank += (gas[index] - cost[index]);
                    ++index;
                }
                
                if (index == i && tank >= 0)
                    return i;
            }
        }
        
        return -1;
    }
};