class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> st;
        std::vector<int> result(temperatures.size(), 0);

        for (size_t i = 0; i < temperatures.size(); ++i)
        {
            // if temperature is bigger than last
            while (!st.empty() && temperatures[st.top()] < temperatures[i])
            {
                int prev_day = st.top(); st.pop();

                // distance of days is just today minus the day this temperature was taken
                result[prev_day] = i - prev_day;
            }
            // if temperatures in descending order or empty
            st.push(i);
        }
        return result;
    }
};
