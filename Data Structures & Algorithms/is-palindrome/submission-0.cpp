class Solution {
public:
    bool isPalindrome(string s)
    {
        unsigned int left = 0;
        unsigned int right = s.length() - 1;

        while (left < right)
        {
            // Alphanumeric character
            if (!std::isalnum(s[left]))
                left++;
            else if (!std::isalnum(s[right]))
                right--;
            else
            {
                if (std::tolower(s[left]) == std::tolower(s[right]))
                {
                    left++;
                    right--;
                }
                else
                    return false;
            }
            
        }
        return true;
    }
};
