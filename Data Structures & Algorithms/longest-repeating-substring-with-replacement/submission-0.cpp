class Solution {
public:
    int characterReplacement(string s, int k)
    {
        int count[26] = {}; // counts uppercase letters
        int left = 0;
        int max_freq = 0;
        int max_length = 0;

        for (int right = 0; right < s.size(); ++right)
        {
            count[s[right] - 'A']++; // add 1 to letter read
            max_freq = std::max(count[s[right] - 'A'] , max_freq);

            if ((right - left + 1) - max_freq > k) // we don't have enough credit
            {
                count[s[left] - 'A']--;
                left++;
            }
            max_length = std::max(max_length, right - left + 1);
        }
        return max_length;
    }
};
