class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        if (s1.size() > s2.size()) return false;

        std::vector<int> s1_count(26, 0);
        std::vector<int> window_count(26, 0);
        int left = 0;
        int right = s1.size() - 1;

        for (const auto& c : s1)
            s1_count[c - 'a']++; // fill hash map with frequency of s1 chars

        for (int i = 0; i < s1.size(); ++i)
        {
            window_count[s2[i] - 'a']++; // fill window hash map with frequency of s2 chars
        }

        if (s1_count == window_count)
            return true;
        else
        {
            for (int i = s1.size(); i < s2.size(); ++i) // starts at index end of s1 + 1
            {
                window_count[s2[i] - 'a']++; // add entering char
                window_count[s2[i - s1.size()] - 'a']--; // remove leaving char

                if (s1_count == window_count)
                    return true;
            }
        }
        return false;
    }
};