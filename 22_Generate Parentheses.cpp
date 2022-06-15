class Solution {
public:
    vector<string> generateParenthesis(int n) {
        generateParenthesis_rec("", 0, n);
        return answer;
    }
    
private:
    void generateParenthesis_rec(std::string base, int currentOpen, int remainOpen)
    {
        if (currentOpen == 0)
        {
            if (remainOpen == 0)
            {
                // No more cases.
                return;
            }
            else
            {
                // Must open new one.
                generateParenthesis_rec(base + "(", currentOpen + 1, remainOpen - 1);
            }
        }
        else if (remainOpen == 0)
        {
            // Must close all.
            std::string s = base;
            
            for (int i = 0; i < currentOpen; ++i)
            {
                base += ")";
            }
            
            answer.push_back(base);
        }
        else // currentOpen > 0 && remainOpen > 0
        {
            // Both choices are possible.
            generateParenthesis_rec(base + "(", currentOpen + 1, remainOpen - 1);
            generateParenthesis_rec(base + ")", currentOpen - 1, remainOpen);
        }
    }
    
private:
    std::vector<std::string> answer;
};