class Solution {
public:
    bool isValid(string s) {
        std::stack<int> openBrackets;

        for (const char c : s)
        {
            if (c == '(' || c == '{' || c== '[')
            {
                openBrackets.push(c);
            }
            else
            {
                if (openBrackets.empty())
                {
                    return false;
                }

                switch(openBrackets.top())
                {
                case '(':
                    if (c != ')')
                    {
                        return false;
                    }
                    break;

                case '{':
                    if (c != '}')
                    {
                        return false;
                    }
                    break;

                case ']':
                    if (c != ']')
                    {
                        return false;
                    }
                    break;
                }

                openBrackets.pop();
            }
        }

        return openBrackets.empty();
    }
};