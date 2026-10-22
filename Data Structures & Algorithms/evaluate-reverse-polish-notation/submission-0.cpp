class Solution {
public:
    int evalRPN(vector<string>& tokens)
    {
        int oper = 0;
        std::stack<int> st;

        for (const auto& token : tokens)
        {
            if (token == "+")
            {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                st.push(num1 + num2);
            }
            else if (token == "-")
            {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                st.push(num1 - num2);
            }
            else if (token == "*")
            {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                st.push(num1 * num2);
            }
            else if (token == "/")
            {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                st.push(num1 / num2);
            }
            else
            {
                st.push(std::stoi(token));
            }
        }
        return st.top();
    }
};
