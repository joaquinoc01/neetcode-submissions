#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) 
    {
        std::unordered_set<int> seen;
        for (const auto& num : nums)
        {
            if (seen.find(num) == seen.end())
            {
                seen.insert(num);
            }
            else // number duplicated
                return true;
        }
        return false;
    }
};