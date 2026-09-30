class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int max_length = 0;
        int left = 0;
        std::unordered_set<char> seen;

        for (int right = 0; right < s.size(); ++right)
        {
            while (seen.count(s[right])) // same as seen.find(s[right]) != seen.end()
            {
                seen.erase(s[left]);
                left++;
            }

            seen.insert(s[right]);

            max_length = std::max(max_length, right - left + 1);
        }

        return max_length;
    }
};
