class Solution {
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto& c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else if (c == ')')
            {
                if (st.empty()) return false; // empty stack (no starting bracket)
                if (st.top() != '(') // if the one before is not a corresponding bracket
                {
                    return false;
                }
                st.pop();
            }
            else if (c == ']')
            {
                if (st.empty()) return false; // empty stack (no starting bracket)
                if (st.top() != '[') // if the one before is not a corresponding bracket
                {
                    return false;
                }
                st.pop();
            }
            else
            {
                if (st.empty()) return false; // empty stack (no starting bracket)
                if (st.top() != '{') // if the one before is not a corresponding bracket
                {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty(); // no elements must be remaining in the stack
    }
};
