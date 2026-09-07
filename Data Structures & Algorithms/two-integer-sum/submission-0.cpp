#include <vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < nums.size(); ++i)
        {
            int difference = target - nums[i];

            if (seen.find(difference) != seen.end()) // found the match
            {
                return {seen[difference], i};
            }

            seen[nums[i]] = i;
        }
    }
};
