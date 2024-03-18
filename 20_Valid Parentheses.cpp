class Solution {
public:
    bool isValid(string s) {
        std::stack<char> table;

        for (char c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                table.push(c);
            }
            else
            {
                if (table.empty())
                {
                    return false;
                }

                const char top = table.top();
                
                switch (c)
                {
                    case ')':
                    if (top != '(')
                    {
                        return false;
                    }
                    break;

                    case ']':
                    if (top != '[')
                    {
                        return false;
                    }
                    break;

                    case '}':
                    if (top != '{')
                    {
                        return false;
                    }
                    break;                
                }

                table.pop();
            }
        }

        return table.empty();
    }
};