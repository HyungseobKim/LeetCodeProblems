class Solution {
public:
    vector<int> minOperations(string boxes) {
        const int length = boxes.length();
        std::vector<int> answer(length, 0);
        
        int balls = 0;
        for (int i = 0; i < length-1; ++i)
        {
            balls += (boxes[i] - '0');
            answer[i+1] = answer[i] + balls;
        }
        
        balls = 0;
        int prev = answer[length-1];
        
        for (int i = length-1; i > 0; --i)
        {
            balls += (boxes[i] - '0');
            const int update = (answer[i] - prev) + balls;
            prev = answer[i-1];
            answer[i-1] += update;
        }
        
        return answer;
    }
};