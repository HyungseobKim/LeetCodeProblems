class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::string s = "";
        generateParenthesis_rec(s, n, 0);
        return answer;
    }

private:
    void generateParenthesis_rec(std::string& s, int toOpen, int toClose)
    {
        if (toOpen == 0)
        {
            std::string closing = "";

            for (int i = 0; i < toClose; ++i)
            {
                closing += ')';
            }

            answer.push_back(s + closing);
            return;
        }

        if (toClose > 0)
        {
            s += ')';

            generateParenthesis_rec(s, toOpen, toClose - 1);

            s.pop_back();
        }

        s += '(';

        generateParenthesis_rec(s, toOpen - 1, toClose + 1);

        s.pop_back();
    }

    std::vector<std::string> answer;
};